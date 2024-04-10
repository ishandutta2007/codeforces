/*-------------------( alex256 )--------------------\
|    Contest: Codeforces Round 378 (Div. 2)         |
|       Task: F                                     |
|       Date: 31. 10. 2016                          |
\--------------------------------------------------*/
// Includes
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
// Defines
#define ar(a) a[maxN]
#define pb push_back
#define F first
#define S second
#define sz(x) (int)x.size()
#define debug(v) makeDebugInfo(#v, v)
#define dbg(v) out.put(makeDebugInfo(#v, v)), cout.flush()
#define here out = "here"; cout.flush()
#define endless for (;;)
// Other defines
#define Actually true
#define yes ;
#define alex256 2048
#define rating(n) n
using namespace std;
// Types
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
struct outFloat { int precision; LD value; outFloat(LD v, int p) : precision(p), value(v) {} }; typedef outFloat ofl;
template <typename T> struct debugInfo { string name; T val; debugInfo(const char* n, T v) : name(n), val(v) {}; };
template <typename T> debugInfo<T> makeDebugInfo(const char* n, T v) { return debugInfo<T>(n, v); }
// Constants
const int inf = 123456789;
const LL llInf = 123456789012345678LL;
const LD pi = 3.14159265358979323846;
const int maxN = 2000000;
// Input / Output
int init() { ios_base::sync_with_stdio(0); srand(time(NULL)); return 0; } int initializer = init();
template <typename T1, typename T2> istream& operator>>(istream& is, pair<T1, T2> &p) { is >> p.first >> p.second; return is; }
template <typename T> istream& operator>>(istream& is, vector<T> &p) { for (int i = 0; i < p.size(); i++) is >> p[i]; return is; }
class inputer
{
    private: istream* istr; public:
    inputer(istream &is) : istr(&is) {}
    template <typename T> void get(T &n) { (*istr) >> n; }
    template <typename T, typename... Args> void get(T &n, Args&... args) { get(n); get(args...); }
    template <typename... Args> void getLn(Args&... args) { get(args...); getLn(); }
    template <typename T> operator T() { T n; get(n); return n; }
    void getLn() { string s; getline(cin, s); }
    template <typename T> void getv(vector <T> &v, int size) { v.resize(size); (*istr) >> v; }
};
#define endl "\n"
string delim = " ";
template <typename T1, typename T2> ostream& operator<<(ostream& os, const pair<T1, T2> &p) { os << p.first << delim << p.second; return os; }
template <typename T> ostream& operator<<(ostream& os, const vector<T> &p) { for (int i = 0; i < p.size(); i++) { if (i != 0) os << delim; os << p[i]; } return os; }
ostream& operator<<(ostream& os, const outFloat &of) { os << setprecision(of.precision) << of.value; return os; }
template <typename T> ostream& operator<<(ostream& os, const debugInfo<T> &dbg) { os << "\"" << dbg.name << "\" = \"" << dbg.val << "\"" << endl; }
class outputer
{
    private: ostream* ostr; public:
    outputer(ostream &os) : ostr(&os) {}
    template <typename T> void put(const T &n) { (*ostr) << n; }
    template <typename T, typename... Args> void put(const T &n, const Args&... args) { put(n); put(args...); }
    template <typename... Args> void putLn(const Args&... args) { put(args...); putLn(); }
    template <typename T> outputer& operator=(const T &n) { putLn(n); return *this; }
    void putLn() { (*ostr) << endl; }
    template <typename T> void putv(vector <T> v, int size, string delim) { for (int i = 0; i < size; i++) { if (i != 0) (*ostr) << delim; (*ostr) << v[i]; } }
};
inputer in(cin);
outputer out(cout);
char getChar() { char c = 0; while (c <= ' ') cin >> c; return c; }
// Other methods
bool willItBeAC() { return Actually yes; } int getMyRating() { return rating(alex256); }
bool prime(LL n) { for (LL i = 2; i * i <= n; i++) if (n % i == 0) return false; return true; }
vector <LL> divs(LL n) { vector <LL> v; LL i = 2; while (i * i <= n) if (n % i == 0) { n /= i; v.pb(i); } else i++; v.pb(n); return v; }
LL gcd(LL a, LL b) { return b ? gcd (b, a % b) : a; }
LL extGcd(LL a, LL b, LL &x, LL &y) { if (a == 0) { x = 0; y = 1; return b; } LL x1, y1, d = extGcd(b % a, a, x1, y1); x = y1 - (b / a) * x1; y = x1; return d; }
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

#define int long long

int n = in;
vector <int> ns, siz;

void init_dsu()
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
        if (g[v][i].F != p) dfs(g[v][i].F, g[v][i].S, v);
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
    int m = in;
    vector< pair< pair<int, int>, pair<int, int> > > v(m);
    vector <int> w;
    in.getv(w, m);
    vector <int> c;
    in.getv(c, m);
    vector <int> ans(m);
    for (int i = 0; i < m; i++)
    {
        v[i].S.F = in, v[i].S.S = in; v[i].F.F = w[i];
        v[i].S.F--, v[i].S.S--;
        v[i].F.S = i + 1;
    }
    int s = in;
    sort(v.begin(), v.end());
    int osz = 0;
    init_dsu();
    for (int i = 0; i < m; i++)
        if (unite(v[i].S.F, v[i].S.S))
        {
            v[i].F.S = -v[i].F.S;
            osz += v[i].F.F;
        }
    g.resize(n);
    for (int i = 0; i < m; i++)
        if (v[i].F.S < 0)
        {
            ans[(-v[i].F.S) - 1] = osz;
            g[v[i].S.F].pb({v[i].S.S, v[i].F.F});
            g[v[i].S.S].pb({v[i].S.F, v[i].F.F});
        }
    prepare();
    for (int i = 0; i < m; i++)
        if (v[i].F.S > 0)
        {
            int p = maxpath(v[i].S.F, v[i].S.S);
            ans[v[i].F.S - 1] = osz - p + v[i].F.F;
        }
    for (int i = 0; i < m; i++) ans[i] -= s / c[i];
    int mv = 0;
    for (int i = 1; i < m; i++) if (ans[i] < ans[mv]) mv = i;
    out.putLn(ans[mv]);
    out.putLn(mv + 1, ' ', w[mv] - (s / c[mv]));
    init_dsu();
    for (int i = 0; i < m; i++)
    {
        v[i].F.S = abs(v[i].F.S) - 1;
        if (v[i].F.S == mv) unite(v[i].S.F, v[i].S.S);
    }
    for (int i = 0; i < m; i++)
    {
        if (v[i].F.S == mv) continue;
        if (unite(v[i].S.F, v[i].S.S))
            out.putLn(v[i].F.S + 1, ' ', v[i].F.F);
    }
    return 0;
}