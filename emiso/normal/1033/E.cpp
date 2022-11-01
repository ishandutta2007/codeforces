#include <bits/stdc++.h>

using namespace std;

map<vector<int>, int> cache;

int query(vector<int> v) {
    if(v.size() < 2) return 0;
    sort(v.begin(), v.end());
    auto it = cache.find(v);
    if(it != cache.end()) return it->second;

    printf("? %d\n", v.size());
    for(int i = 0; i < v.size(); i++)
        printf("%d%c", v[i], (i+1==v.size()) ? '\n' : ' ');
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    if(ret == -1) exit(0);
    return cache[v] = ret;
}

vector<int> nodes, notyet;

int query_aux(vector<int> &v, int l, int r) {
    return query(vector<int>(v.begin() + l, v.begin() + r));
}

int query_aux2(int la, int ra, int lb, int rb) {
    int x, y, xy;
    x = query_aux(nodes, la, ra);
    y = query_aux(notyet, lb, rb);


    vector<int> v;
    for(int i = la; i < ra; i++) v.push_back(nodes[i]);
    for(int i = lb; i < rb; i++) v.push_back(notyet[i]);
    xy = query(v);

    return xy - x - y;
}

pair<int, int> search_edge(int la, int ra, int lb, int rb) {
    if(la + 1 == ra) {
        if(lb + 1 == rb) return {nodes[la], notyet[lb]};
        else {
            int mb = (lb + rb + 1)/2;
            if(query_aux2(la, ra, lb, mb))
                    return search_edge(la, ra, lb, mb);
            else    return search_edge(la, ra, mb, rb);
        }
    } else {
        int ma = (la + ra + 1)/2;
        if(query_aux2(la, ma, lb, rb))
                return search_edge(la, ma, lb, rb);
        else    return search_edge(ma, ra, lb, rb);
    }
}

int n, cor[601];
vector<int> adj[601];

void cmon(vector<int> &v) {
    nodes.clear();
    notyet.clear();
    for(int x : v) {
        nodes.push_back(x);
        for(int y : v)
            if(y != x)
                notyet.push_back(y);
        if(query_aux2(0, 1, 0, notyet.size())) {
            auto p = search_edge(0, 1, 0, notyet.size());
            adj[p.first].push_back(p.second);
            adj[p.second].push_back(p.first);
        }
        nodes.pop_back();
        notyet.clear();
    }
}

int visit[601][2];
vector<int> cyc;

int dfs(int no, int par) {
    if(!cyc.empty()) return 1;
    if(visit[no][par]) return 1;
    visit[no][par] = 1;
    if(visit[no][1-par]) return -1;

    for(int v : adj[no]) {
        if(dfs(v, 1 - par) == -1) {
            cyc.push_back(no);
            if(visit[no][par] && visit[no][1-par]) return 1;
            else return -1;
        }
    }
    return 1;
}

int main() {
    scanf("%d", &n);

    nodes.push_back(1);
    cor[1] = 0;
    for(int i = 2; i <= n; i++)
        notyet.push_back(i);

    for(int i = 1; i < n; i++) {
        auto p = search_edge(0, nodes.size(), 0, notyet.size());
        adj[p.first].push_back(p.second);
        adj[p.second].push_back(p.first);
        cor[p.second] = 1 - cor[p.first];
        nodes.push_back(p.second);

        for(int i = 0; i < notyet.size(); i++)
            if(p.second == notyet[i])
                notyet.erase(notyet.begin() + i);
    }
    assert(notyet.empty());

    vector<int> v[2];
    for(int i = 1; i <= n; i++)
        v[cor[i]].push_back(i);

    if(!query(v[0]) && !query(v[1])) {
        printf("Y %d\n", v[0].size());
        for(int i = 0; i < v[0].size(); i++)
            printf("%d%c", v[0][i], (i+1==v[0].size()) ? '\n' : ' ');
        fflush(stdout);
        return 0;
    }

    if(query(v[0])) cmon(v[0]);
    else cmon(v[1]);

    dfs(1, 0);


    printf("N %d\n", cyc.size());
    for(int i = 0; i < cyc.size(); i++)
        printf("%d%c", cyc[i], (i+1==cyc.size()) ? '\n' : ' ');
    fflush(stdout);
    return 0;
}