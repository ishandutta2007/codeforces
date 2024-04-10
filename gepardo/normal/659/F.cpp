/*-------------------( alex256 )--------------------\
|    Contest: Codeforces Round 346 (Div. 2)         |
|       Task: F                                     |
|       Date: 30. 03. 2016                          |
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

#define int long long

int n = in, m = in, k = in;
int ar[2000][2000];
bool used[2000][2000];
bool u2[2000][2000];
int cnt = 0;

void dfs(int i, int j, int mv, int mc)
{
    if (cnt == mc) return;
    if (u2[i][j]) return;
    if (ar[i][j] < mv) return;
    cnt++;
    u2[i][j] = true;
    dfs(i - 1, j, mv, mc);
    dfs(i + 1, j, mv, mc);
    dfs(i, j - 1, mv, mc);
    dfs(i, j + 1, mv, mc);
}

class DSU
{
    public:

    vector <int> p, s;
    int mSz;
    void makeSet(int v)
    {
        p[v] = v;
        s[v] = 1;
    }
    DSU(int n) : p(n), s(n), mSz(1)
    {
        for (int i = 0; i < n; i++)
            makeSet(i);
    }
    int findSet(int v)
    {
        if (v == p[v]) return v;
        return p[v] = findSet(p[v]);
    }
    void unionSets(int a, int b)
    {
        a = findSet(a);
        b = findSet(b);
        if (a != b)
        {
            if (s[a] < s[b]) swap(a, b);
            p[b] = a;
            s[a] += s[b];
        }
        mSz = max(mSz, s[a]);
    }
};

main()
{
    set< pair<int, pair<int,int> > > s;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            ar[i][j] = in;
            s.insert({-ar[i][j], {i, j}});
        }
    pair < int, pair<int,int> > bestIt = {1, {-1, -1}};
    DSU d(10000000);
    for (auto it: s)
    {
        int num = -it.ff, x = it.ss.ff, y = it.ss.ss;
        used[x][y] = true;
        if (used[x - 1][y]) d.unionSets(x * m + y, (x - 1) * m + y);
        if (used[x + 1][y]) d.unionSets(x * m + y, (x + 1) * m + y);
        if (used[x][y - 1]) d.unionSets(x * m + y, x * m + (y - 1));
        if (used[x][y + 1]) d.unionSets(x * m + y, x * m + (y + 1));

        //out.putLn(num, ' ', d.mSz);

        if (k % num != 0) continue;
        if (d.mSz >= (k / num))
        {
            bestIt = it;
            break;
        }
    }

    //out.putLn(bestIt);

    if (bestIt.ff == 1) out = "NO";
        else
        {
            out.putLn("YES");
            dfs(bestIt.ss.ff, bestIt.ss.ss, -bestIt.ff, k / (-bestIt.ff));
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                    cout << ((u2[i][j]) ? -bestIt.ff : 0) << " ";
                cout << endl;
            }
        }

    return 0;
}