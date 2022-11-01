#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct PushRelabel {
    struct Edge {
        int dest, back;
        ll f, c;
    };
    vector<vector<Edge>> g;
    vector<ll> ec;
    vector<Edge*> cur;
    vector<vector<int>> hs;
    vector<int> H;
    
    PushRelabel(int n) : g(n), ec(n), cur(n), hs(2*n), H(n) {}
    
    void addEdge(int s, int t, ll cap, ll rcap=0) {
        if (s == t) return;
        g[s].push_back({t, (int) g[t].size(), 0, cap});
        g[t].push_back({s, (int) g[s].size() - 1, 0, rcap});
    }
    void addFlow(Edge& e, ll f) {
        Edge &back = g[e.dest][e.back];
        if (!ec[e.dest] && f) 
            hs[H[e.dest]].push_back(e.dest);
        e.f += f; e.c -= f; ec[e.dest] += f;
        back.f -= f; back.c += f; ec[back.dest] -= f;
    }
    ll maxFlow(int s, int t) {
        int v = (int)g.size(); 
        H[s] = v; 
        ec[t] = 1;
        
        vector<int> co(2*v); 
        co[0] = v-1;

        for (int i = 0; i < v; i++) 
            cur[i] = g[i].data();
        for (Edge& e : g[s]) 
            addFlow(e, e.c);

        for (int hi = 0;;) {
            while (hs[hi].empty())
                if (!hi--) 
                    return -ec[s];
            
            int u = hs[hi].back(); hs[hi].pop_back();
            while (ec[u] > 0) { // discharge u
                if (cur[u] == g[u].data() + (int)g[u].size()) {
                    H[u] = 1e9;
                    for (Edge& e : g[u]) if (e.c && H[u] > H[e.dest]+1)
                    H[u] = H[e.dest]+1, cur[u] = &e;
                    if (++co[H[u]], !--co[hi] && hi < v)
                        for (int i = 0; i < v; i++) if (hi < H[i] && H[i] < v)
                            --co[H[i]], H[i] = v + 1;
                    hi = H[u];
                } else if (cur[u]->c && H[u] == H[cur[u]->dest]+1) {
                    addFlow(*cur[u], min(ec[u], cur[u]->c));
                } else ++cur[u];
            } 
        }
    }
    bool leftOfMinCut(int a) { return H[a] >= g.size(); }
};

int ans[300030], cnt[300030];
vector<int> v[200020];

vector<int> ys;

int main() {
    int source = 0, sink = 1, n, sum = 0;

    scanf("%d", &n);
    for (int i = 0, sz; i < n; i++) {
        scanf("%d", &sz);
        sum += sz / 2;    
        for (int j = 0, x; j < sz; j++) {
            scanf("%d", &x);      
            v[i].push_back(x);
            ys.push_back(x);
        }
    }

    sort(ys.begin(), ys.end());
    ys.resize(unique(ys.begin(), ys.end()) - ys.begin());
    
    PushRelabel g(n+ys.size()+3);

    for (int i = 0; i < n; i++) {
        g.addEdge(source, i+2, v[i].size() / 2);
        for (int j = 0, x; j < v[i].size(); j++) {
            v[i][j] = lower_bound(ys.begin(), ys.end(), v[i][j]) - ys.begin();
            ans[v[i][j]]++;
            cnt[v[i][j]]++;
        }
        for (int x : v[i]) {
            if (ans[x]) g.addEdge(i+2, n+x+2, ans[x]);
            ans[x] = 0;
        }
    }

    int flag = 1;
    for (int i = 0; i < ys.size(); i++) {        
        int x = i;
        flag &= (cnt[x] % 2 == 0);
        g.addEdge(n + x + 2, sink, cnt[x] / 2);
    }

    if (flag == 0) puts("NO");
    else if (g.maxFlow(source, sink) != sum) puts("NO");
    else {
        puts("YES");
        for (int i = 0; i < n; i++) {
            for (auto ed : g.g[i+2]) {
                if (ed.dest == source) continue;
                ans[ed.dest-n-2] += ed.f;
            }
            for (int x : v[i]) {
                if (ans[x] > 0) {
                    ans[x]--;
                    printf("L");
                }
                else printf("R");
            }
            puts("");
        }
    }
    return 0;
}