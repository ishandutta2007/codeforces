#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)


template <int N>
class UnionFind {
    public:
        int p[N];
        int rank[N];
        UnionFind();
        int find(int x);
        void link(int a, int b);
};

template <int N>
UnionFind<N>::UnionFind() {
    REP(i,N) {
        p[i] = i;
        rank[i] = 0;
    }
}       

template <int N>
int UnionFind<N>::find(int x) {
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

template <int N>
void UnionFind<N>::link(int a, int b) {
    int x = find(a), y = find(b);
    if (rank[y] > rank[x]) swap(x,y);
    if (rank[y] == rank[x]) rank[x]++;
    p[y] = x;
}

namespace ChuLiu {
struct Edge {
    long long cost; int idx;
    bool operator<(const Edge& ot) const {
        if (cost != ot.cost) return cost < ot.cost;
        return idx < ot.idx;
    }
};

template <int N>
class Solver {
	int p[N];
    long long added[N];
    int mn[N];
    int rank[N];
    set<Edge> pq[N];
    vector<int> cycle[N];
    UnionFind<N> wDSU;
    ChuLiu::Edge enter[N];
    int leaf[N];
    vector< pair<int, pair<int, int> > > edgeList;
    void hang(int x, int y);
    void cut(int x);
    void comp(int x);
    int find(int x);
    Edge get_min(int x);
    void link(int x, int y);
public:
	vector<int> go(int n, vector< pair<int, pair<int, int> > > &el);
};

template <int N>
void Solver<N>::hang(int x, int y) {
    if (!pq[x].empty()) {
        Edge a = *pq[x].begin();
        a.cost += added[x];
        pq[y].insert(a);
    }
    p[x] = y;
}

template <int N>
void Solver<N>::cut(int x) {
    if (p[x] != x) {
        cut(p[x]);
        if (!pq[x].empty()) {
            Edge a = *pq[x].begin();
            a.cost += added[x];
            pq[p[x]].erase(a);
        }
    }
}

template <int N>
void Solver<N>::comp(int x) {
    if (p[x] != x) {
        comp(p[x]);
        if (p[p[x]] != p[x]) added[x] += added[p[x]];
        hang(x,p[p[x]]);
    }
}

template <int N>
int Solver<N>::find(int x) {
    if (p[p[x]] != p[x]) {
        cut(x);
        comp(x);
    }
    return p[x];
}

template <int N>
Edge Solver<N>::get_min(int x) {
    if (pq[x].empty()) return {-1,-1};
    Edge ret = *pq[x].begin();
    
    int v = edgeList[ret.idx].second.second;
    if (v != x) {
        find(v);
        pq[v].erase(pq[v].begin());
        hang(v,x);
    }
    pq[x].erase(ret);
    ret.cost += added[x];
    return ret;
}

template <int N>
void Solver<N>::link(int x, int y) {
    if (rank[x] < rank[y]) swap(x,y);
    if (rank[x] == rank[y]) rank[x]++;
    added[y] -= added[x];
    hang(y,x);
}

template <int N>
vector<int> Solver<N>::go(int n, vector< pair<int, pair<int, int> > > &el) {
    edgeList = el;
    std::vector<int> tp(edgeList.size(), -2);
    std::vector<int> visit(edgeList.size(), 0);
    std::vector< std::vector<int> > children(edgeList.size());
    std::vector<int> roots;
    std::vector<int> rset;

    REP(i,edgeList.size()) pq[edgeList[i].second.second].insert({edgeList[i].first, i});

    REP(i,n) {
        p[i] = mn[i] = i;
        added[i] = 0;
        leaf[i] = -1;
        rank[i] = 0;
        enter[i] = {-1,-1};
        roots.push_back(i);
    }

    while (!roots.empty()) {
        int k = find(roots.back());
        roots.pop_back();
        ChuLiu::Edge e = get_min(k);
        if (e.idx == -1) {
            rset.push_back(mn[k]);
            continue;
        }
        if (find(edgeList[e.idx].second.first) == k) {
            roots.push_back(k); 
        }
        else {
            tp[e.idx] = -1;
            if (!cycle[k].empty()) {
                for (int x : cycle[k]) {
                    tp[x] = e.idx;
                    children[e.idx].push_back(x);
                }
            }
            else leaf[k] = e.idx;
            
            if (wDSU.find(edgeList[e.idx].second.first) != wDSU.find(k)) {
                wDSU.link(wDSU.find(edgeList[e.idx].second.first), wDSU.find(k));
                enter[k] = e;
            }
            else {
                vector<int> tc;
                ChuLiu::Edge xy = e;
                int val = e.cost;
                int vertex = find(edgeList[e.idx].second.second);
                while (xy.idx != -1) { 
                    tc.push_back(xy.idx);
                    if (xy.cost > val) {
                        val = xy.cost;
                        vertex = find(edgeList[xy.idx].second.second);
                    }
                    xy = enter[find(edgeList[xy.idx].second.first)];
                }
                added[find(k)] += val - e.cost;
                xy = enter[find(edgeList[e.idx].second.first)];
                while (xy.idx != -1) {
                    added[find(edgeList[xy.idx].second.second)] += val - xy.cost;
                    link(find(k), find(edgeList[xy.idx].second.second));
                    if (find(edgeList[xy.idx].second.first)==find(k)) break;
                    xy = enter[find(edgeList[xy.idx].second.first)];
                }
                mn[find(k)] = mn[vertex];
                swap(cycle[find(k)], tc);
                roots.push_back(k);
                enter[find(k)]={-1,-1};
            }
        }
    }
    
    REP(i, edgeList.size()) if (tp[i] == -1) roots.push_back(i);
    vector<int> ans;
    while (!rset.empty() || !roots.empty()) {
        int v;
        if (!rset.empty()) {
            v = rset.back();
            rset.pop_back();
        }
        else {
            while (!roots.empty() && visit[roots.back()]) roots.pop_back();
            if (roots.empty()) break;
            v = edgeList[roots.back()].second.second;
            ans.push_back(roots.back());
            roots.pop_back();
        }

        int vt = leaf[v];
        if (vt == -1) continue;
        visit[vt] = 1;
        while (tp[vt] != -1 && !visit[tp[vt]]) {
            visit[tp[vt]]=1;
            for (int x : children[tp[vt]]) if (x != vt) roots.push_back(x);
            vt = tp[vt];
        }
    }

    return ans;
}

}

 
int n, m;
vector< pair<int, pair<int, int> > > edgeList;
int real_idx[100100];

void solve() {
#ifdef ONLINE_JUDGE 
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    scanf("%d %d", &n, &m);

    map< pair<int, int>, pair<int, int> > ee;
    REP(i,m) {
        int u,v,c;
        scanf("%d %d %d", &u, &v, &c); u--; v--;
        if (v == 0) continue;
        if (ee.count({u,v}) == 0 || ee[{u,v}].first > c) {
            ee[{u,v}] = {c,i+1};
        }
    }
    for (auto it=ee.begin(); it!=ee.end(); it++) {
        edgeList.push_back({it->second.first, {it->first.first, it->first.second}});
        real_idx[edgeList.size()-1] = it->second.second;
    }
    
    ChuLiu::Solver<100003> solv; 
    vector<int> nr;
    vector<int> ans = solv.go(n, edgeList);
    if ((int)ans.size() < n-1) {
        printf("-1\n");
        return;
    }
    for (int x: ans) {
        if (edgeList[x].first != 0) nr.push_back(real_idx[x]);
    }

    printf("%d\n", nr.size());
    if (!nr.empty()) {
        bool f = false;
        for (int x : nr) {
            if (f) printf(" ");
            f = true;
            printf("%d", x);
        }
        printf("\n");
    }
}

int main() {
    solve();
}