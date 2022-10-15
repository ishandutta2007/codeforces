/*-------------------( alex256 )--------------------+
|    Contest: Goodbye 2015                          |
|       Task: C                                     |
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
#include <cstdio>
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
#define ft(i, f, t) for (int i = f; i < t; i++)
#define here cout << "here"
#define right RIGHT
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

char a[1000][1000] = {};
int down[1000][1000] = {}, right[1000][1000] = {};

int getdown(int i, int j)
{
    if (i < 0 || j < 0) return 0; else return down[i][j];
}

int getright(int i, int j)
{
    if (i < 0 || j < 0) return 0; else return right[i][j];
}

int main()
{
    int n = getint(), m = getint();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            char c = 0;
            while (c <= ' ') cin >> c;
            a[i][j] = c;
        }
    for (int i = 0; i < (n - 1); i++)
        for (int j = 0; j < m; j++)
        {
            int q = 0;
            if (a[i][j] == '.' && a[i + 1][j] == '.') q = 1;
            if (i == 0 && j == 0) down[i][j] = q;
            else if (i == 0) down[i][j] = down[i][j - 1] + q;
            else if (j == 0) down[i][j] = down[i - 1][j] + q;
            else down[i][j] = down[i - 1][j] + down[i][j - 1] - down[i - 1][j - 1] + q;
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < (m + 1); j++)
        {
            int q = 0;
            if (a[i][j] == '.' && a[i][j + 1] == '.') q = 1;
            if (i == 0 && j == 0) right[i][j] = q;
            else if (i == 0) right[i][j] = right[i][j - 1] + q;
            else if (j == 0) right[i][j] = right[i - 1][j] + q;
            else right[i][j] = right[i - 1][j] + right[i][j - 1] - right[i - 1][j - 1] + q;
        }
    int k = getint();
    for (int i = 0; i < k; i++)
    {
        int a = getint(), b = getint(), c = getint(), d = getint();
        a--, b--, c--, d--;
        cout << getdown(c - 1, d) - getdown(c - 1, b - 1) - getdown(a - 1, d) + getdown(a - 1, b - 1) +
                getright(c, d - 1) - getright(c, b - 1) - getright(a - 1, d - 1) + getright(a - 1, b - 1) << endl;
    }
    return 0;
}