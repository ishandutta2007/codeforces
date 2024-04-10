/*-------------------( alex256 )--------------------+
|    Contest: Codeforces Round 338 (Div. 2)         |
|       Task: D                                     |
|       Date: 08. 01. 2016                          |
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
#define int long long
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
LL mod1 = (LL)(1e9 + 7), mod2 = mod1 - 1;
//End of template

main()
{
    map <LL, LL> m;
    bool div2 = false;
    int n = getint();
    for (int i = 0; i < n; i++) m[getint()]++;
    for (map <LL, LL> :: iterator it = m.begin(); it != m.end(); it++)
        if ((it -> ss % 2) != 0) div2 = true;
    bool issqr = !div2;
    LL cnt = 1, mul = 1;
    for (map <LL, LL> :: iterator it = m.begin(); it != m.end(); it++)
    {
        int q = (it -> ss) + 1, w = it -> ff;
        int c = (issqr) ? ((q - 1) / 2) : q - 1;
        for (int i = 0; i < c; i++) mul = (mul * w) % mod1;
        if (q % 2 == 0 && div2)
        {
            div2 = false;
            q /= 2;
        }
        cnt = (cnt * q) % mod2;
    }
	LL q = cnt, aa = mul;
	LL res = 1;
	while (q)
    {
		if (q & 1) res = (res * aa) % mod1;
		aa = (aa * aa) % mod1;
		q >>= 1;
	}
	cout << res;

	return 0;
}