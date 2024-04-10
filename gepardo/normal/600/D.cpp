/*-------------------( alex256 )--------------------+
|    Contest: Educational Round 2                   |
|       Task: D                                     |
|       Date: 27. 11. 2015                          |
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
#define Actually true
#define yes ;
#define fr(i, n) for (int i = 0; i < n; i++)
#define ld long double
using namespace std;
int init() { ios_base::sync_with_stdio(0); return 0; }
int initializer = init();
bool will_it_be_AC() { return Actually yes; }
bool prime(LL n) { for (LL i = 2; i * i <= n; i++) if (n % i == 0) return false; return true; }
vector <LL> divs(LL n) { vector <LL> v; LL i = 2; while (i * i <= n) if (n % i == 0) { n /= i; v.pb(i); } else i++; v.pb(n); return v; }
LL gcd(LL a, LL b) { return b ? gcd (b, a % b) : a; }
LL extgcd(LL a, LL b, LL &x, LL &y) { if (a == 0) { x = 0; y = 1; return b; } LL x1, y1, d = extgcd(b % a, a, x1, y1); x = y1 - (b / a) * x1; y = x1; return d; }
template <typename T> void ivector(vector <T> &v, int size) { for (int i = 0; i < size; i++) cin >> v[i]; }
template <typename T> void ovector(vector <T> v, int size, string separator) { if (size != 0) cout << v[0]; for (int i = 1; i < size; i++) cout << separator << v[i]; }
int getint() { int r; cin >> r; return r; }
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

int main()
{
    ld x1, y1, r1;
    ld x2, y2, r2;
    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;
    ld sqdist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2),
       dist = sqrt(sqdist);
    //1. Not intersect
    if (dist >= r1 + r2)
    {
        cout << 0;
        return 0;
    }
    //2. 1 in 2.
    if (dist + r1 <= r2)
    {
        cout << ldout(PI * r1 * r1, 18);
        return 0;
    }
    //3. 2 in 1
    if (dist + r2 <= r1)
    {
        cout << ldout(PI * r2 * r2, 18);
        return 0;
    }
    //4. Norm case
    ld cos1 = (r1 * r1 - r2 * r2 + sqdist) / (2 * r1 * dist),
       cos2 = (r2 * r2 - r1 * r1 + sqdist) / (2 * r2 * dist);
    ld ang1 = acos(cos1), ang2 = acos(cos2),
       da1 = ang1 * 2, da2 = ang2 * 2;
    ld sr1 = PI * r1 * r1, sr2 = PI * r2 * r2,
       st1 = r1 * r1 * sin(da1) / 2, st2 = r2 * r2 * sin(da2) / 2,
       ss1 = sr1 * da1 / PI / 2, ss2 = sr2 * da2 / PI / 2;
    cout << ldout(ss1 - st1 + ss2 - st2, 18);
    return 0;
}