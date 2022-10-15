/*-------------------( alex256 )--------------------\
|    Contest: Educational Round 10                  |
|       Task: E                                    |
|       Date: 25. 03. 2016                          |
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
#define mp make_pair
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define debug(v) #v << " = \"" << v << "\""
#define here cout << "here"
#define endless for (;;)
// Other defines
#define Actually true
#define yes ;
#define alex256 2121
#define rating(n) n
using namespace std;
// Types
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
struct outFloat { int precision; LD value; outFloat(LD v, int p) : precision(p), value(v) {} };
typedef outFloat ofl;
// Constants
const int inf = 123456789;
const LL llInf = 123456789012345678;
const LD pi = 3.14159265358979323846;
const int maxN = 2000000;
// Input / Output
int init() { ios_base::sync_with_stdio(0); srand(time(NULL)); return 0; }
int initializer = init();
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
class outputer
{
    private: ostream* ostr; public:
    outputer(ostream &os) : ostr(&os) {}
    template <typename T> void put(const T &n) { (*ostr) << n; }
    template <typename T, typename... Args> void put(const T &n, const Args&... args) { put(n); put(args...); }
    template <typename... Args> void putLn(const Args&... args) { put(args...); putLn(); }
    template <typename T> outputer& operator=(const T &n) { put(n); return *this; }
    void putLn() { (*ostr) << endl; }
    template <typename T> void putv(vector <T> v, int size, string delim) { for (int i = 0; i < size; i++) { if (i != 0) (*ostr) << delim; (*ostr) << v[i]; } }
};
inputer in(cin);
outputer out(cout);
char getChar() { char c = 0; while (c <= ' ') cin >> c; return c; }
// Other methods
bool willItBeAC() { return Actually yes; }
int getMyRating() { return rating(alex256); }
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

vector< pair< pair<int,int>,int > > getVi(int m)
{
    vector< pair< pair<int,int>,int > > v;
    in.getv(v, m);
    return v;
}

int n = (int)in + 1, m = in;
vector< pair< pair<int,int>,int > > v = getVi(m);
int a = in, b = in;

vector < vector<int> > g;

vector <bool> used(n);
vector <int> tin(n), fup(n);
int timer = 0;

set < pair<int,int> > bridges;

vector <int> cmp(n, -1);
int compCount;
vector < vector< pair<int,int> > > g1;
vector <int> good;


void dfs(int v, int p = -1)
{
    fup[v] = tin[v] = timer++;
    used[v] = true;
    for (int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        if (to == p) continue;
        if (used[to]) fup[v] = min(fup[v], tin[to]);
            else
            {
                dfs(to, v);
                fup[v] = min(fup[v], fup[to]);
                if (fup[to] > tin[v]) bridges.insert({v, to}), bridges.insert({to, v});
            }
    }
}

void findBridges()
{
    for (int i = 0; i < n; i++) if (!used[i]) dfs(i);
}

void makeGraph()
{
    g.clear(), g.resize(n);
    for (int i = 0; i < m; i++)
    {
        if (bridges.count(v[i].ff)) continue;
        g[v[i].ff.ff].pb(v[i].ff.ss);
        g[v[i].ff.ss].pb(v[i].ff.ff);
    }
}

void compFind(int v, int c)
{
    if (cmp[v] != -1) return;
    cmp[v] = c;
    for (int i = 0; i < g[v].size(); i++) compFind(g[v][i], c);
}

void findComps()
{
    for (int i = 0; i < n; i++)
        if (cmp[i] == -1) compFind(i, compCount++);
}

void makeNewGraph()
{
    good.resize(compCount);
    g1.resize(compCount);
    for (int i = 0; i < m; i++)
    {
        int da = cmp[v[i].ff.ff], db = cmp[v[i].ff.ss];
        if (da == db) good[da] = max(good[da], v[i].ss);
            else
            {
                g1[da].pb({db, v[i].ss});
                g1[db].pb({da, v[i].ss});
            }
    }
    a = cmp[a];
    b = cmp[b];
}

bool doDFS(int v, int p = -1, bool can = false)
{
    bool ok = false;
    if (good[v]) can = true;
    if (v == b) return can;
    for (int i = 0; i < g1[v].size(); i++)
    {
        int to = g1[v][i].ff;
        if (to == p) continue;
        ok = ok || doDFS(to, v, can || g1[v][i].ss);
    }
    return ok;
}

main()
{
    makeGraph();
    findBridges();
    makeGraph();
    findComps();
    makeNewGraph();
    out.putLn(doDFS(a) ? "YES" : "NO");
    return 0;
}