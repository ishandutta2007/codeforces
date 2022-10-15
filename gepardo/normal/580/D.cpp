/*
+--------------------( alex256 )--------------------+
|    Contest: 321 (Div. 2)                          |
|       Task: D                                     |
|       Date: 22.09.2015                            |
+---------------------------------------------------+
*/

#include <algorithm>
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
#define ldout(v, prec) setprecision(prec) << v
#define debug(v) #v << " = \"" << v << "\""
#define ffor(i, n) for (int i = 0; i < n; i++)
#define bfor(i, n) for (int i = n - 1; i >= 0; i--)
#define xfor(i, f, t) for (int i = f; i <= t; i++)
#define xbfor(i, f, t) for (int i = t; i >= f; i--)
#define endless for (;;)

using namespace std;

bool will_it_be_AC()
{
    return true;
}

bool prime(LL n)
{
    for (LL i = 2; i * i <= n; i++) if (n % i == 0) return false;
    return true;
}

vector <LL> divs(LL n)
{
    vector <LL> v; LL i = 2;
    while (i * i <= n) if (n % i == 0) { n /= i; v.pb(i); } else i++;
    v.pb(n);
    return v;
}

LL gcd(LL a, LL b)
{
    return b ? gcd (b, a % b) : a;
}

LL extgcd(LL a, LL b, LL &x, LL &y)
{
	if (a == 0) { x = 0; y = 1; return b; }
	LL x1, y1, d = extgcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1; y = x1;
	return d;
}

template <typename T> void ivector(vector <T> &v, int size)
{
    ffor (i, size) cin >> v[i];
}

template <typename T> void ovector(vector <T> v, int size, string separator)
{
    if (size != 0) cout << v[0];
    xfor (i, 1, size - 1) cout << separator << v[i];
}

int n, m;
LL dp[1048576][20];
LL ss[20];
LL t[20][20] = {};

LL launch_dp(int mask, int l, int k, LL sum)
{
    if (dp[mask][l] >= 0) return dp[mask][l] + sum;
    if (k == m) return sum;
    LL res = -1;
    for (int i = 0; i < n; i++)
    {
        int sdvig = 1 << i;
        if ((mask & sdvig) != 0) continue;
        LL newsum = sum + ss[i] + t[l][i];
        res = max(res, launch_dp(mask | sdvig, i, k + 1, newsum));
    }
    dp[mask][l] = res - sum;
    if (res < 0) endless;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> ss[i];
    for (int i = 0; i < k; i++)
    {
        int q, w, r;
        cin >> q >> w >> r;
        q--; w--;
        t[q][w] += r;
    }
    for (int i = 0; i < 1048576; i++)
        for (int j = 0; j <= n; j++)
           dp[i][j] = -1;

    cout << launch_dp(0, n, 0, 0);
    return 0;
}