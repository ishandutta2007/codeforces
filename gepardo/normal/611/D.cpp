/*-------------------( alex256 )--------------------+
|    Contest: Goodbye 2015                          |
|       Task: D                                     |
|       Date: 30. 12. 2015                          |
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
#define INF 1234567
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
#define ft(i, f, t) for (int i = f; i < t; i++)
#define here cout << "here"
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

const int MOD = (int)(1e9 + 7);

int g[5001][5001] = {}, pg[5001][5001] = {}, q[5001][5001] = {};

main()
{
    int n = getint();
    string s;
    getline(cin, s); getline(cin, s);

    for (int i = 0; i < n; i++)
        for (int j = 1; j <= n; j++)
            q[i][j] = INF;

    for (int j = 1; j <= (n / 2); j++)
    {
        int r = 0;
        for (int k = 0; k < j; k++)
        {
            if (s[n - j + k] > s[n - j - j + k]) break;
            if (s[n - j + k] < s[n - j - j + k]) { r = INF; break; }
            r++;
        }
        q[n - 1][j] = r;
    }

    for (int i = n - 2; i >= 0; i--)
        for (int j = 1; j <= ((i + 1) / 2); j++)
        {
            if (s[i - j + 1] > s[i - j - j + 1]) q[i][j] = 0;
            if (s[i - j + 1] < s[i - j - j + 1]) q[i][j] = INF;
            if (s[i - j + 1] == s[i - j - j + 1]) q[i][j] = min(INF, q[i + 1][j] + 1);
        }

    if (s[0] != '0') g[0][1] = 1;
    pg[0][1] = g[0][1]; for (int j = 2; j <= n; j++) pg[0][j] = (pg[0][j - 1] + g[0][j]) % MOD;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= i; j++)
            if (s[i - j + 1] != '0')
            {
                g[i][j] = (g[i][j] + pg[i - j][j - 1]) % MOD;
                if (q[i][j] < j)
                    g[i][j] = (g[i][j] + g[i - j][j]) % MOD;
            }
        if (s[0] != '0') g[i][i + 1] = 1;
        pg[i][1] = g[i][1]; for (int j = 2; j <= n; j++) pg[i][j] = (pg[i][j - 1] + g[i][j]) % MOD;
    }
    /*for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n; j++) if (q[i][j] == INF) cout << "-1 "; else cout << q[i][j] << " ";
        cout << endl;
    }*/
    cout << pg[n - 1][n] % MOD;
    return 0;
}