#include<bits/stdc++.h>
using namespace std;
#define int long long
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

const int N = 207;

struct Dinic{
    struct edge{
        int to, flow, cap;
    };

    const static int N = N * N * 2; //count of vertices

    vector<edge> e;
    vector<int> g[N + 7];
    int dp[N + 7];
    int ptr[N + 7];

    void clear(){
        for (int i = 0; i < N + 7; i++) g[i].clear();
        e.clear();
    }

    void addEdge(int a, int b){
        int cap = 1;
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

int num[N][N];
string a[N];

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif

    int n, m;
    cin >> n >> m;
    int ptr = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            num[i][j] = ptr++;

    int cnt = 0;                        
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < m; ++j)
            if (a[i][j] == '#')
                cnt++;
    }    
    
    auto check = [&] (int i, int j) {
        return 0 <= i && i < n && 0 <= j && j < m && a[i][j] == '#';
    };  

    auto hor = [&] (int i, int j) {
        return num[i][j];
    };  
    auto ver = [&] (int i, int j ) {
        return num[i][j] + N * N;
    };  

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '#') {
                if (check(i - 1, j) && check(i, j - 1)) {
                    dinic.addEdge(hor(i - 1, j), ver(i, j - 1));
                }   
                if (check(i - 1, j) && check(i, j + 1)) {
                    dinic.addEdge(hor(i - 1, j), ver(i, j));
                }   

                if (check(i + 1, j) && check(i, j - 1)) {
                    dinic.addEdge(hor(i, j), ver(i, j - 1));
                }   
                if (check(i + 1, j) && check(i, j + 1)) {
                    dinic.addEdge(hor(i, j), ver(i, j));
                }   
            }                           
        }   
    }   

    const int S = 2 * N * N - 2;
    const int T = 2 * N * N - 1;

    int per = 0;

    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (check(i, j) && check(i + 1, j)) {
                dinic.addEdge(S, hor(i, j));
                per++;
            }   
        }   
    }   

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j + 1 < m; ++j) {
            if (check(i, j) && check(i, j + 1)) {
                dinic.addEdge(ver(i, j), T);
                per++;
            }   
        }   
    }   

    int mar = dinic.dinic(S, T);
    int ind = per - mar;

    #ifdef HOME
    debug(cnt);
    debug(per);
    debug(mar);
    debug(ind);
    #endif

    cout << cnt - ind << endl;
}