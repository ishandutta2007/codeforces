
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define I int
#define int long long
#define D double
#define il inline
#define C char
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define ls(k) (k) << 1
#define rs(k) (k) << 1 | 1
#define re register
#define V void
#define RT return
#define inn in()
#define u_map unordered_map
#define pair_q priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
#define p_q priority_queue
#define IOS std::ios::sync_with_stdio(false);
const int mod = 1e9 + 7;
const int Mxdt = 1000000;
inline char gc()
{
    static char buf[Mxdt], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, Mxdt, stdin), p1 == p2) ? EOF : *p1++;
}
inline int in()
{
    int x = 0, f = 1;
    char ch = gc();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = gc();
    }
    while (ch >= '0' && ch <= '9')
        x = (x << 3) + (x << 1) + (ch ^ 48), ch = gc();
    return x * f;
}
void out(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        out(x / 10);
    putchar(x % 10 + '0');
    return;
}

const int N = 200200;
int a[N], b[N];
int n;
int ed[N][2];
struct node {
    int ne, to, w;
} e[N << 1];
int h[N], c = 0;
int m;
vector<int> g[N];
void dfs(int v, int fa, int t) {
    for (int id : g[v])
        if (id != fa) {
            int u = ed[id][0] ^ ed[id][1] ^ v;
            b[id] = m + n * (t ^ 1);
            a[u] = m + n * t;
            m++;
            dfs(u, id, t ^ 1);
        }
}
signed main(void) {
    IOS;
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        n = 1 << n;
        m = 1, c = 0;
        for (int i = 0; i <= n; i++) {
            g[i].clear();
        }
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            v = v - 1, u = u - 1;
            g[v].push_back(i);
            g[u].push_back(i);
            ed[i][0] = u;
            ed[i][1] = v;
        }
        a[0] = n;
        dfs(0, -1, 0);
        cout << 1 << endl;
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << endl;
        for (int i = 1; i < n; i++) {
            cout << b[i] << ' ';
        }
        cout << endl;
    }
}