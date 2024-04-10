#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 5e5 + 7;

struct Edge{
    int u, v, c;
};

bool comp(Edge a, Edge b){
    return a.c < b.c;
}

struct Event{
    bool type;
    int u, val;
    Event(bool a, int b, int c){
        type = a;
        u = b;
        val = c;
    }
};

map <int, vector < pair <int, vector <Edge> > > > want;

bool ans[MAXN];

int father[MAXN], cnt[MAXN];
stack <Event> h;

inline int getroot(int u){
    while (father[u] != u){
        u = father[u];
    }
    return u;
}

inline bool merge(int u, int v){
    u = getroot(u);
    v = getroot(v);

    if (u == v) return false;

    if (cnt[u] > cnt[v]){
        h.push(Event(0, v, father[v]));
        father[v] = u;
        h.push(Event(1, u, cnt[u]));
        cnt[u] += cnt[v];
    }
    else{
        h.push(Event(0, u, father[u]));
        father[u] = v;
        h.push(Event(1, v, cnt[v]));
        cnt[v] += cnt[u];
    }

    return true;
}

inline void fuck_go_back(int sz){
    while (h.size() > sz){

        if (h.top().type == 0){
            father[h.top().u] = h.top().val;
        }
        else{
            cnt[h.top().u] = h.top().val;
        }

        h.pop();
    }
}

map <int, int> prev_;

signed main(){
    //freopen("input.txt", "r", stdin);
    cout.precision(40);

    int n, m;
    scanf("%d%d", &n, &m);
    vector <Edge> e(m);
    map <int, vector <Edge> > ms;
    for (int i = 0; i < m; ++i){
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].c);
        e[i].u--;
        e[i].v--;
        ms[e[i].c].push_back(e[i]);
    }

    int last = 0;
    for (pair <int, vector <Edge> > elem: ms){
        prev_[elem.first] = last;
        last = elem.first;
    }

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; ++i){
        int k;
        scanf("%d", &k);
        map <int, vector <Edge> > new_q;
        for (int j = 0; j < k; ++j){
            int num;
            scanf("%d", &num);
            new_q[e[num - 1].c].push_back(e[num - 1]);
        }
        for (pair <int, vector <Edge> > elem: new_q){
            int cost = elem.first;
            want[prev_[cost]].push_back({i, elem.second});
        }
    }

    for (int i = 0; i < q; ++i){
        ans[i] = true;
    }

    for (int i = 0; i < n; ++i){
        father[i] = i;
        cnt[i] = 1;
    }

    ms[0] = {};
    for (pair <int, vector <Edge> > elem: ms){
        int cost = elem.first;
        for (Edge ed: elem.second){
            merge(ed.u, ed.v);
        }

        int sz = h.size();

        for (pair <int, vector <Edge> > quer: want[cost]){
            int quer_num = quer.first;
            for (Edge ed: quer.second){
                ans[quer_num] &= merge(ed.u, ed.v);
            }

            fuck_go_back(sz);
        }
    }

    for (int i = 0; i < q; ++i){
        if (ans[i]){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }

    return 0;
}