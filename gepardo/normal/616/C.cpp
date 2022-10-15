/*-------------------( alex256 )--------------------+
|    Contest: Educational Codeforces Round 5        |
|       Task: C                                     |
|       Date: 11. 01. 2016                          |
+--------------------------------------------------*/
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
#define INF 123456789
#define LLINF 123456789012345678
#define PI 3.14159265358979323846
#define MAXN 1000000
#define LL long long
#define ULL unsigned long long
#define ar(a) a[MAXN]
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair <int, int>
#define sz(x) (int)x.size()
#define ldout(v, prec) setprecision(prec) << v
#define debug(v) #v << " = \"" << v << "\""
#define endless for (;;)
#define fenint fenwick <int>
#define fenll fenwick <LL>
#define Actually true
#define yes ;
#define fr(i, n) for (int i = 0; i < n; i++)
#define ft(i, f, t) for (int i = f; i < t; i++)
#define here cout << "here"
using namespace std;
template <typename T1, typename T2> istream& operator>> (istream& is, pair<T1, T2> &p) { is >> p.first >> p.second; return is; }
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

int n, m;
string a[2000];
int sz[2000][2000] = {}, q[2000][2000] = {};
int cnt = 0;
int szs[2000000];


int getsize(int i, int j)
{
    if (i < 0 || j < 0 || i >= n || j >= m) return 0;
    if (a[i][j] == '*') return 0;
    if (sz[i][j] != INF) return sz[i][j];
    sz[i][j] = 0;
    int res = getsize(i - 1, j) + getsize(i + 1, j) + getsize(i, j + 1) + getsize(i, j - 1) + 1;
    return res;
}

void asgn(int i, int j, int val)
{
    if (i < 0 || j < 0 || i >= n || j >= m) return;
    if (a[i][j] == '*') return;
    if (q[i][j] != 0) return;
    q[i][j] = val;
    asgn(i - 1, j, val);
    asgn(i + 1, j, val);
    asgn(i, j - 1, val);
    asgn(i, j + 1, val);
}

int getitem(int i, int j)
{
    if (i < 0 || j < 0 || i >= n || j >= m) return 0;
    if (a[i][j] == '*') return 0;
    else return q[i][j];
}

int main()
{
    cin >> n >> m; rdln();
    for (int i = 0; i < n; i++) a[i] = getstr();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            sz[i][j] = INF;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cnt++;
            asgn(i, j, cnt);
            szs[cnt] = getsize(i, j);
        }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '.') cout << '.';
            else
            {
                vector <int> v;
                int res = 1;
                v.pb(getitem(i - 1, j));
                v.pb(getitem(i + 1, j));
                v.pb(getitem(i, j - 1));
                v.pb(getitem(i, j + 1));

                for (int i = 0; i < v.size(); i++)
                    for (int j = 0; j < v.size(); j++)
                        if (v[i] == v[j] && i != j) v[i] = 0;
                for (int i = 0; i < v.size(); i++)
                    if (v[i] != 0) res += szs[v[i]];
                cout << res % 10;
            }
        }
        cout << endl;
    }



    return 0;
}