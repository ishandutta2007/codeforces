/*-------------------( alex256 )--------------------+
|    Contest: CF Round 331 (Div. 2)                 |
|       Task: C                                     |
|       Date: 13. 11. 2015                          |
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
#define INF 2147483647
#define LLINF 9223372036854775807
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
using namespace std;
int init() { ios_base::sync_with_stdio(0); return 0; }
int initializer = init();
bool will_it_be_AC() { return true; }
bool prime(LL n) { for (LL i = 2; i * i <= n; i++) if (n % i == 0) return false; return true; }
vector <LL> divs(LL n) { vector <LL> v; LL i = 2; while (i * i <= n) if (n % i == 0) { n /= i; v.pb(i); } else i++; v.pb(n); return v; }
LL gcd(LL a, LL b) { return b ? gcd (b, a % b) : a; }
LL extgcd(LL a, LL b, LL &x, LL &y) { if (a == 0) { x = 0; y = 1; return b; } LL x1, y1, d = extgcd(b % a, a, x1, y1); x = y1 - (b / a) * x1; y = x1; return d; }
template <typename T> void ivector(vector <T> &v, int size) { for (int i = 0; i < size; i++) cin >> v[i]; }
template <typename T> void ovector(vector <T> v, int size, string separator) { if (size != 0) cout << v[0]; for (int i = 1; i < size; i++) cout << separator << v[i]; }
int getint() { int r; cin >> r; return r;}
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
vector < pair<int, int> > a(n), v(n), ans(n), k(n);
vector <int> c(n), u(100001), q[300000];
int w[300000] = {};

int main()
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].ff >> a[i].ss;
        q[a[i].ss - a[i].ff + 150000].pb(a[i].ss + a[i].ff);
    }
    ivector(c, n);
    for (int i = 0; i < 300000; i++) sort(q[i].begin(), q[i].end());
    for (int i = 0; i < n; i++)
    {
        int t = c[i] + 150000;
        if (w[t] >= q[t].size())
        {
            cout << "NO";
            return 0;
        }
        int va = q[t][w[t]], vb = c[i];
        int nx = (va + vb) / 2, ny = (va - vb) / 2;
        //cout << nx << " " << ny << endl;
        if (u[nx] != ny)
        {
            cout << "NO";
            return 0;
        }
        u[nx]++;
        ans[i] = mp(ny, nx);
        w[t]++;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
        cout << ans[i].ff << " " << ans[i].ss << "\n";

    return 0;
}