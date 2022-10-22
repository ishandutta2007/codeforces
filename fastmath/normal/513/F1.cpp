#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <fstream>
#include <array>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define x first
#define y second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cerr << #x << ": " << x << '\n';

#define FORI(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR(i,a) FORI(i,0,a)
#define ROFI(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define ROF(i,a) ROFI(i,0,a)
#define rep(a) FOR(_,a)
#define each(a,x) for (auto& a: x)
#define FORN(i, n) FORI(i, 1, n + 1)

using vi = vector<int>;
template <typename T>
std::istream& operator >>(std::istream& input, std::pair <T, T> & data)
{
    input >> data.x >> data.y;
    return input;
}
template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& data)
{
    for (T& x : data)
        input >> x;
    return input;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const pair <T, T> & data)
{
    output << "(" << data.x << "," << data.y << ")";
    return output;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& data)
{
    for (const T& x : data)
        output << x << " ";
    return output;
}
std::ostream& operator <<(std::ostream& output, const __int128 &x)
{
    __int128 n = x;
    if (n == 0) {
        output << "0";
        return output;
    }
    if (n < 0) {
        n = -n;
        output << "-";
    }
    string s;
    while (n) {
        s += '0' + (n%10);
        n /= 10;
    }
    reverse(all(s));
    cout << s;
    return output;
}
ll div_up(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll div_down(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down 
ll math_mod(ll a, ll b) { return a - b * div_down(a, b); }
#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>; 
tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; 
} // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; 
}
ll gcd(ll a, ll b) {
    while (b) {
        tie(a, b) = mp(b, a % b);
    }
    return a;
}
int Bit(int mask, int bit) { return (mask >> bit) & 1; }

const int N = 23, INF = 1e18;
string greed[N];

struct Chel {
    int x, y, t;
};

V <ii> v = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };

#define pb push_back

struct Dinic{
    struct edge{
        int to, flow, cap;
    };

    const static int N = 23 * 23 * 4; //count of vertices

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
        for (minFlow = (1 << 30); minFlow; minFlow >>= 1){
            while(bfs()){
                for (int i = 0; i < N; i++) ptr[i] = 0;
                while(int now = dfs(start, (int)2e9 + 7)) flow += now;
            }
        }
        return flow;
    }
} dinic;


int n, m;
void bfs(int x, int y, int dist[N][N]) {
    FOR (i, N) {
        FOR (j, N) {
            dist[i][j] = INF;
        }
    }
    if (greed[x][y] == '#') {
        return;
    }
    queue <ii> q;
    q.push(mp(x, y));
    dist[x][y] = 0;
    while (q.size()) {
        auto p = q.front(); q.pop();
        int i = p.x, j = p.y;
        each (e, v) {
            int x = i + e.x, y = j + e.y;
            if (0 <= x && x < n && 0 <= y && y < m && greed[x][y] == '.') {
                if (ckmin(dist[x][y], dist[i][j] + 1)) {
                    q.push(mp(x, y));
                }
            }
        }
    }
}

int dist[N][N][N][N];

signed main() {
    #ifdef LOCAL
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int males, females;
    cin >> n >> m >> males >> females;
    FOR (i, n) {
        cin >> greed[i];
    }

    int x, y, t;
    cin >> x >> y >> t;
    x--; y--;

    if (abs(males - females) != 1) {
        cout << -1 << endl;
        exit(0);
    }

    V <Chel> a(males), b(females);
    FOR (i, males) {
        cin >> a[i].x >> a[i].y >> a[i].t;
        a[i].x--; a[i].y--;
    }
    FOR (i, females) {
        cin >> b[i].x >> b[i].y >> b[i].t;
        b[i].x--; b[i].y--;
    }

    if (males > females) {
        b.app({x, y, t});
    }
    else {
        a.app({x, y, t});
    }

    FOR (i, n) {
        FOR (j, m) {
            bfs(i, j, dist[i][j]);
        }
    }
    assert(a.size() == b.size());
    int k = a.size();

    auto num = [&] (int x, int y) {
        return x * m + y;
    };

    auto check = [&] (int Tim) {
        dinic.clear();
        const int S = dinic.N - 2;
        const int T = dinic.N - 1;

        FOR (i, k) {
            dinic.addEdge(S, i, 1);
            FOR (x, n) {
                FOR (y, m) {
                    int d = dist[a[i].x][a[i].y][x][y];
                    if (d != INF) {
                        if (d * a[i].t <= Tim) {
                            dinic.addEdge(i, 2 * k + num(x, y), 1);
                        }
                    }
                }
            }
        }
        FOR (x, n) {
            FOR (y, m) {
                if (greed[x][y] == '.') {
                    dinic.addEdge(2 * k + num(x, y), 2 * k + n * m + num(x, y), 1);
                }
            }
        }
        FOR (i, k) {
            dinic.addEdge(i + k, T, 1);
            FOR (x, n) {
                FOR (y, m) {
                    int d = dist[b[i].x][b[i].y][x][y];
                    if (d != INF) {
                        if (d * b[i].t <= Tim) {
                            dinic.addEdge(2 * k + n * m + num(x, y), i + k, 1);
                        }
                    }
                }
            }
        }

        return dinic.dinic(S, T) == k;
    };

    int l = -1, r = INF;
    if (!check(r)) {
        cout << -1 << endl;
        exit(0);
    }

    while (l < r - 1) {
        int m = (l + r) / 2;
        if (check(m)) {
            r = m;
        }
        else {
            l = m;
        }
    }
    cout << r << endl;
}