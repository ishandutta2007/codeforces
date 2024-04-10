/*-------------------( alex256 )--------------------+
|    Contest: Codeforces Round 338 (Div. 2)         |
|       Task: C                                     |
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

int d[3000][3000] = {}, d2[3000][3000] = {}, c[3000] = {}, c2[3000] = {}, z[3000] = {}, z2[3000] = {}, f[3000] = {}, p[3000] = {};

void repair(int n)
{
    if (n == 0) return;
    if (p[n] < 0)
    {
        int j = -p[n] - 1;
        repair(j);
        cout << z2[j] + 1 << " " << z2[j] - (n - j) + 2 << endl;
        return;
    }
    if (p[n] > 0)
    {
        int j = p[n] - 1;
        repair(j);
        cout << z[j] + 1 << " " << n - j + z[j] << endl;
        return;
    }
}

int main()
{
    string s1, s2, s3;
    getline(cin, s1);
    getline(cin, s2);
    s3 = s1;
    reverse(s3.begin(), s3.end());
    int n1 = s1.length(), n2 = s2.length();

    for (int i = 0; i < n2; i++) d[n1 - 1][i] = (s1[n1 - 1] == s2[i]) ? 1 : 0;
    for (int i = 0; i < n1; i++) d[i][n2 - 1] = (s1[i] == s2[n2 - 1]) ? 1 : 0;
    for (int i = n1 - 2; i >= 0; i--)
        for (int j = n2 - 2; j >= 0; j--)
            d[i][j] = (s1[i] == s2[j]) ? (d[i + 1][j + 1] + 1) : 0;

    for (int i = 0; i < n2; i++) d2[n1 - 1][i] = (s3[n1 - 1] == s2[i]) ? 1 : 0;
    for (int i = 0; i < n1; i++) d2[i][n2 - 1] = (s3[i] == s2[n2 - 1]) ? 1 : 0;
    for (int i = n1 - 2; i >= 0; i--)
        for (int j = n2 - 2; j >= 0; j--)
            d2[i][j] = (s3[i] == s2[j]) ? (d2[i + 1][j + 1] + 1) : 0;

    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
            if (d[i][j] > c[j])
            {
                c[j] = d[i][j];
                z[j] = i;
            }

    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
            if (d2[i][j] > c2[j])
            {
                c2[j] = d2[i][j];
                z2[j] = n1 - 1 - i;
            }

    int inf = 123456;
/*
    for (int i = 0; i < n2; i++) cout << c[i] << " "; cout << endl;
    for (int i = 0; i < n2; i++) cout << c2[i] << " "; cout << endl;
*/
    f[0] = 0;
    for (int i = 0; i < n2; i++)
    {
        f[i + 1] = inf;
        for (int j = 0; j <= i; j++)
        {
            if (c[j] > (i - j))
            {
                if (f[j] < f[i + 1])
                {
                    f[i + 1] = f[j] + 1;
                    p[i + 1] = j + 1;
                }
            }
            if (c2[j] > (i - j))
            {
                if (f[j] < f[i + 1])
                {
                    f[i + 1] = f[j] + 1;
                    p[i + 1] = -(j + 1);
                }
            }
        }
    }
/*
    for (int i = 0; i <= n2; i++) cout << f[i] << " ";
    cout << endl;
*/
    if (f[n2] == inf)
    {
        cout << -1;
        return 0;
    }
    cout << f[n2] << endl;
    repair(n2);

    return 0;
}