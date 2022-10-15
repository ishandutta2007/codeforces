/*-------------------( alex256 )--------------------+
|    Contest: Educational Round 3                   |
|       Task: E                                     |
|       Date: 19. 12. 2015                          |
+--------------------------------------------------*/
#pragma comment(linker, "/STACK:100000000")
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <ctime>
#define int long long
#define LL long long
#define ULL unsigned long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define Actually true
#define yes ;
using namespace std;
int init() { ios_base::sync_with_stdio(0); srand(time(NULL)); return 0; }
int initializer = init();
bool will_it_be_AC() { return Actually yes; }
bool prime(LL n) { for (LL i = 2; i * i <= n; i++) if (n % i == 0) return false; return true; }
vector <LL> divs(LL n) { vector <LL> v; LL i = 2; while (i * i <= n) if (n % i == 0) { n /= i; v.pb(i); } else i++; v.pb(n); return v; }
LL gcd(LL a, LL b) { return b ? gcd (b, a % b) : a; }
LL extgcd(LL a, LL b, LL &x, LL &y) { if (a == 0) { x = 0; y = 1; return b; } LL x1, y1, d = extgcd(b % a, a, x1, y1); x = y1 - (b / a) * x1; y = x1; return d; }
template <typename T> void ivector(vector <T> &v, int size) { for (int i = 0; i < size; i++) cin >> v[i]; }
template <typename T> void ovector(vector <T> v, int size, string separator) { if (size != 0) cout << v[0]; for (int i = 1; i < size; i++) cout << separator << v[i]; }
int getint() { int r; cin >> r; return r; }
LL getll() { LL r; cin >> r; return r; }
void rdln() { string s; getline(cin, s); }
string getstr() { string s; cin >> s; return s; }
template <typename T> class fenwick
{
    private: vector<T> t; int n; public:
    fenwick(int nn) { init(nn); }
    void init(int nn) { n = nn; t.assign(n, 0); }
    T sum(int r) { T result = 0; for (; r >= 0; r = (r & (r + 1)) - 1) result += t[r]; return result; }
    void inc(int i, T delta) { for (; i < n; i = (i | (i + 1))) t[i] += delta; }
    T sum(int l, int r) { return sum(r) - sum(l - 1); }
    T get(int i) { return sum(i, i); }
    void put(int i, T v) { inc(i, v - sum(i, i)); }
    int size() { return n; }
};
//End of template

int n = getint();
vector <int> ns, siz;

void initit()
{
    ns.resize(n); siz.resize(n);
    for (int i = 0; i < n; i++) ns[i] = -1, siz[i] = 0;
}

int root(int i)
{
    while (ns[i] >= 0) i = ns[i];
    return i;
}

bool unite(int i, int j)
{
    i = root(i), j = root(j);
    if (i == j) return false;
    if (siz[i] == siz[j]) siz[i]++;
    if (siz[i] >= siz[j]) ns[j] = i; else ns[i] = j;
    return true;
}

int l;
vector< vector< pair<int, int> > > g;
vector<int> tin, tout;
int timer;
vector < vector<int> > up, path;

void dfs(long v, int pth = 0, long p = 0)
{
    tin[v] = ++timer;
    up[v][0] = p;
    path[v][0] = pth;
    for (long i = 1; i <= l; i++)
        up[v][i] = up[up[v][i - 1]][i - 1],
        path[v][i] = max(path[v][i - 1], path[up[v][i - 1]][i - 1]);
    for (long i = 0; i < g[v].size(); i++)
        if (g[v][i].ff != p) dfs(g[v][i].ff, g[v][i].ss, v);
    tout[v] = ++timer;
}

bool upper(int a, int b)
{
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b)
{
    if (upper(a, b)) return a;
    if (upper(b, a)) return b;
    for (int i = l; i >= 0; i--)
        if (!upper(up[a][i], b)) a = up[a][i];
    return up[a][0];
}

int maxp(int a, int b)
{
    if (a == b) return 0;
    int pth = 0;
    for (int i = l; i >= 0; i--)
        if (!upper(up[a][i], b)) pth = max(pth, path[a][i]), a = up[a][i];
    return max(pth, path[a][0]);
}

int maxpath(int a, int b)
{
    int c = lca(a, b);
    return max(maxp(a, c), maxp(b, c));
}

void prepare()
{
    tin.resize(n);
    tout.resize(n);
    up.resize(n);
    path.resize(n);
    l = 1;
    while ((1 << l) <= n) l++;
    for (int i = 0; i < n; i++)  up[i].resize(l + 1), path[i].resize(l + 1);
    dfs(0);
}

main()
{
    int m = getint();
    vector< pair< pair<int, int>, pair<int, int> > > v(m);
    vector<int> ans(m);
    for (int i = 0; i < m; i++)
    {
        cin >> v[i].ss.ff >> v[i].ss.ss >> v[i].ff.ff;
        v[i].ss.ff--, v[i].ss.ss--;
        v[i].ff.ss = i + 1;
    }
    sort(v.begin(), v.end());
    int osz = 0;
    initit();
    for (int i = 0; i < m; i++)
        if (unite(v[i].ss.ff, v[i].ss.ss))
        {
            v[i].ff.ss = -v[i].ff.ss;
            osz += v[i].ff.ff;
        }
    g.resize(n);
    for (int i = 0; i < m; i++)
        if (v[i].ff.ss < 0)
        {
            ans[(-v[i].ff.ss) - 1] = osz;
            g[v[i].ss.ff].pb(mp(v[i].ss.ss, v[i].ff.ff));
            g[v[i].ss.ss].pb(mp(v[i].ss.ff, v[i].ff.ff));
        }
    prepare();
    for (int i = 0; i < m; i++)
        if (v[i].ff.ss > 0)
        {
            int p = maxpath(v[i].ss.ff, v[i].ss.ss);
            ans[v[i].ff.ss - 1] = osz - p + v[i].ff.ff;
        }
    for (int i = 0; i < m; i++) cout << ans[i] << endl;
    return 0;
}