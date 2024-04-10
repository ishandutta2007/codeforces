#include<bits/stdc++.h>
using namespace std;
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';

#define pb push_back

struct Dinic{
    struct edge{
        int to, flow, cap;
    };

    const static int N = 2e4+7; //count of vertices

    vector<edge> e;
    vector<int> g[N + 7];
    int dp[N + 7];
    int ptr[N + 7];

    void clear(){
        for (int i = 0; i < N + 7; i++) g[i].clear();
        e.clear();
    }

    void addEdge(int a, int b, int cap){
        g[a].pb(e.size());
        e.pb({b, 0, cap});
        g[b].pb(e.size());
        e.pb({a, 0, 0});
    }

    int minFlow, start, finish;

    bool bfs(){
        for (int i = 0; i < N; i++) dp[i] = -1;
        dp[start] = 0;
        vector<int> st;
        int uk = 0;
        st.pb(start);
        while(uk < st.size()){
            int v = st[uk++];
            for (int to : g[v]){
                auto ed = e[to];
                if (ed.cap - ed.flow >= minFlow && dp[ed.to] == -1){
                    dp[ed.to] = dp[v] + 1;
                    st.pb(ed.to);
                }
            }
        }
        return dp[finish] != -1;
    }

    int dfs(int v, int flow){
        if (v == finish) return flow;
        for (; ptr[v] < g[v].size(); ptr[v]++){
            int to = g[v][ptr[v]];
            edge ed = e[to];
            if (ed.cap - ed.flow >= minFlow && dp[ed.to] == dp[v] + 1){
                int add = dfs(ed.to, min(flow, ed.cap - ed.flow));
                if (add){
                    e[to].flow += add;
                    e[to ^ 1].flow -= add;
                    return add;
                }
            }
        }
        return 0;
    }

    int dinic(int start, int finish){
        Dinic::start = start;
        Dinic::finish = finish;
        int flow = 0;
        for (minFlow = 1; minFlow; minFlow >>= 1){
            while(bfs()){
                for (int i = 0; i < N; i++) ptr[i] = 0;
                while(int now = dfs(start, (int)2e9 + 7)) flow += now;
            }
        }
        return flow;
    }
} dinic;


signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif

    int n, M;
    cin >> n >> M;

    struct Edge {
        int u, v, c;
    };

    vector <Edge> ed(M);
    for (int i = 0; i < M; ++i) 
        cin >> ed[i].u >> ed[i].v >> ed[i].c;
    
    const int INF = 1e9+7;
    int l = 0, r = INF;
    while (l < r - 1) {
        int m = (l + r) >> 1;
        dinic.clear();
        for (int i = 0; i < M; ++i) {
            if (ed[i].c <= m) {
                dinic.addEdge(ed[i].u, ed[i].v + n, 1);
            }   
        }   
        const int S = 0, T = 2 * n + 1;
        for (int i = 1; i <= n; ++i) {
            dinic.addEdge(S, i, 1);
            dinic.addEdge(i + n, T, 1);
        }   
        if (dinic.dinic(S, T) == n) {
            r = m;
        }   
        else {
            l = m;
        }   
    }           
    if (r == INF)
        cout << -1 << endl;
    else            
        cout << r << endl;
}