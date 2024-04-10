/*-------------------( alex256 )--------------------+
|    Contest: CodeForces Round 326 (Div. 2)         |
|       Task: D                                     |
|       Date: 15. 10. 2015                          |
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

const LL mod = 1000000007;

vector <LL> f[1500000], g[1500000];

#define int LL

main()
{
    LL n; cin >> n;
    LL l; cin >> l;
    LL k; cin >> k;
    LL o = l % n;
    vector <int> v(n);
    ivector(v, n);
    vector <int> Q(n), q(n);
    for (int i = 0; i < n; i++) Q[i] = v[i];
    sort(Q.begin(), Q.end());
    for (int i = 0; i < n; i++) q[i] = Q[n - 1 - i];

    vector <pair <LL, LL> > u;
    u.pb(make_pair(q[0], 1));
    for (int i = 1; i < n; i++)
    {
        if (q[i - 1] == q[i]) u[u.size() - 1].second++;
        else u.pb(make_pair(q[i], 1));
    }
    int s = u.size();
    f[0].resize(s + 1);
    for (int i = s - 1; i >= 0; i--) f[0][i] = f[0][i + 1] + u[i].second;
    for (int i = 1; i < k; i++)
    {
        f[i].resize(s + 1);
        f[i][s] = 0;
        for (int j = s - 1; j >= 0; j--)
            f[i][j] = (f[i][j + 1] + u[j].second * (f[i - 1][j])) % mod;
    }

    for (int i = 0; i < s; i++) u[i].second = 0;

    if (o == 0) o = n;
    q.resize(o + 1);
    Q.resize(o);
    for (int i = 0; i < o; i++) Q[i] = v[i];
    sort(Q.begin(), Q.end());
    for (int i = 0; i < o; i++) q[i] = Q[o - 1 - i];
    q[o] = -1;

    int p = 0;

    for (int i = 0; i < s; i++)
    {
        while (p < o && q[p] > u[i].first) p++;
        while (p < o && q[p] == u[i].first) { u[i].second++; p++; }
    }

    g[0].resize(s + 1);
    for (int i = s - 1; i >= 0; i--) g[0][i] = g[0][i + 1] + u[i].second;
    for (int i = 1; i < k; i++)
    {
        g[i].resize(s + 1);
        g[i][s] = 0;
        for (int j = s - 1; j >= 0; j--)
            g[i][j] = (g[i][j + 1] + u[j].second * (f[i - 1][j])) % mod;
    }

    LL res = 0;
    LL L = ((l - 1) / n) + 1;

    for (LL i = 1; i <= k; i++)
    {
        LL A = (L - i) % mod, B = f[i - 1][0] % mod,
           C = (A * B) % mod, D = g[i - 1][0] % mod,
           E = (C + D) % mod;
        res = (res + E) % mod;
        if (i == L) break;
    }

    cout << res;

    return 0;
}