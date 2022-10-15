/*-------------------( alex256 )--------------------\
|    Contest: Codeforces Round 355 (Div. 2)         |
|       Task: D                                     |
|       Date: 01. 06. 2016                          |
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
#define ff first
#define ss second
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
struct outFloat
{
    int precision;
    LD value;
    outFloat(LD v, int p) : precision(p), value(v) {} };
typedef outFloat ofl;
template <typename T> struct debugInfo
{
    string name;
    T val;
    debugInfo(const char* n, T v) : name(n), val(v) {};
};
template <typename T> debugInfo<T> makeDebugInfo(const char* n, T v)
{
    return debugInfo<T>(n, v);
}
// Constants
const int inf = 123456789;
const LL llInf = 123456789012345678LL;
const LD pi = 3.14159265358979323846;
const int maxN = 2000000;
// Input / Output
int init()
{
    ios_base::sync_with_stdio(0);
    srand(time(NULL));
    return 0;
}
int initializer = init();
template <typename T1, typename T2> istream& operator>>(istream& is, pair<T1, T2> &p)
{
    is >> p.first >> p.second;
    return is;
}
template <typename T> istream& operator>>(istream& is, vector<T> &p)
{
    for (int i = 0; i < p.size(); i++) is >> p[i];
    return is;
}
class inputer
{
private:
    istream* istr;
public:
    inputer(istream &is) : istr(&is) {}
    template <typename T> void get(T &n)
    {
        (*istr) >> n;
    }
    template <typename T, typename... Args> void get(T &n, Args&... args)
    {
        get(n);
        get(args...);
    }
    template <typename... Args> void getLn(Args&... args)
    {
        get(args...);
        getLn();
    }
    template <typename T> operator T()
    {
        T n;
        get(n);
        return n;
    }
    void getLn()
    {
        string s;
        getline(cin, s);
    }
    template <typename T> void getv(vector <T> &v, int size)
    {
        v.resize(size);
        (*istr) >> v;
    }
};
#define endl "\n"
string delim = " ";
template <typename T1, typename T2> ostream& operator<<(ostream& os, const pair<T1, T2> &p)
{
    os << p.first << delim << p.second;
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const vector<T> &p)
{
    for (int i = 0; i < p.size(); i++)
    {
        if (i != 0) os << delim;
        os << p[i];
    }
    return os;
}
ostream& operator<<(ostream& os, const outFloat &of)
{
    os << setprecision(of.precision) << of.value;
    return os;
}
template <typename T> ostream& operator<<(ostream& os, const debugInfo<T> &dbg)
{
    os << "\"" << dbg.name << "\" = \"" << dbg.val << "\"" << endl;
}
class outputer
{
private:
    ostream* ostr;
public:
    outputer(ostream &os) : ostr(&os) {}
    template <typename T> void put(const T &n)
    {
        (*ostr) << n;
    }
    template <typename T, typename... Args> void put(const T &n, const Args&... args)
    {
        put(n);
        put(args...);
    }
    template <typename... Args> void putLn(const Args&... args)
    {
        put(args...);
        putLn();
    }
    template <typename T> outputer& operator=(const T &n)
    {
        putLn(n);
        return *this;
    }
    void putLn()
    {
        (*ostr) << endl;
    }
    template <typename T> void putv(vector <T> v, int size, string delim)
    {
        for (int i = 0; i < size; i++)
        {
            if (i != 0) (*ostr) << delim;
            (*ostr) << v[i];
        }
    }
};
inputer in(cin);
outputer out(cout);
char getChar()
{
    char c = 0;
    while (c <= ' ') cin >> c;
    return c;
}
// Other methods
bool willItBeAC()
{
    return Actually yes;
}
int getMyRating()
{
    return rating(alex256);
}
bool prime(LL n)
{
    for (LL i = 2; i * i <= n; i++) if (n % i == 0) return false;
    return true;
}
vector <LL> divs(LL n)
{
    vector <LL> v;
    LL i = 2;
    while (i * i <= n) if (n % i == 0)
        {
            n /= i;
            v.pb(i);
        }
        else i++;
    v.pb(n);
    return v;
}
LL gcd(LL a, LL b)
{
    return b ? gcd (b, a % b) : a;
}
LL extGcd(LL a, LL b, LL &x, LL &y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    LL x1, y1, d = extGcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
template <typename T> class fenwick
{
private:
    vector<T> t;
    int n;
public:
    fenwick(int nn)
    {
        init(nn);
    }
    void init(int nn)
    {
        n = nn;
        t.assign(n, 0);
    }
    T sum(int r)
    {
        T result = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) result += t[r];
        return result;
    }
    void inc(int i, T delta)
    {
        for (; i < n; i = (i | (i + 1))) t[i] += delta;
    }
    T sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }
    T get(int i)
    {
        return sum(i, i);
    }
    void put(int i, T v)
    {
        inc(i, v - sum(i, i));
    }
    int size()
    {
        return n;
    }
};
//End of template

#define int long long

int q[400][400];
int dp[400][400] = {};
int dp2[400][400];

inline int dist(pair<int,int> a, pair<int,int> b)
{
    return llabs(a.ff - b.ff) + llabs(a.ss - b.ss);
}

struct three
{
    int a, b, c;
    three(int a, int b, int c) : a(a), b(b), c(c) {}
};

operator< (three a, three b)
{
    return a.c > b.c;
}

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int n = in, m = in, p = in;
vector<vector<pair<int,int>>> qs(p);

void pass1(int i) // O(qs[i].size() * qs[i-1].size())
{
    for (int j = 0; j < qs[i].size(); j++)
        for (int k = 0; k < qs[i-1].size(); k++)
            dp[qs[i][j].ff][qs[i][j].ss] =
                min(dp[qs[i][j].ff][qs[i][j].ss],
                    dp[qs[i-1][k].ff][qs[i-1][k].ss] +
                    dist(qs[i][j], qs[i-1][k]));
}

void pass2(int qi) // O(n * m * log);
{
    priority_queue<three> qu;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (q[i][j] == qi-1)
                qu.push(three(i, j, dp[i][j])),
                dp2[i][j] = dp[i][j];
            else
                dp2[i][j] = llInf;
    while (!qu.empty())
    {
        three t = qu.top();
        qu.pop();
        if (t.c != dp2[t.a][t.b]) continue;
        for (int i = 0; i < 4; i++)
        {
            int nx = t.a + dx[i], ny = t.b + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dp2[nx][ny] > dp2[t.a][t.b] + 1)
            {
                dp2[nx][ny] = dp2[t.a][t.b] + 1;
                qu.push(three(nx, ny, dp2[nx][ny]));
            }
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (q[i][j] == qi)
                dp[i][j] = dp2[i][j];
}

main()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            q[i][j] = (int)in - 1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            qs[q[i][j]].pb({i, j});
            dp[i][j] = llInf;
        }
    for (int i = 0; i < qs[0].size(); i++)
        dp[qs[0][i].ff][qs[0][i].ss] = dist( {0, 0}, qs[0][i]);
    for (int i = 1; i < p; i++)
    {
        if (qs[i].size() * qs[i-1].size() <= n * m * 12)
            pass1(i);
        else
            pass2(i);
    }
    out = dp[qs[p-1][0].ff][qs[p-1][0].ss];
    return 0;
}