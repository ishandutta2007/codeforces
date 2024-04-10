/*
+--------------------( alex256 )--------------------+
|    Contest: 321 (Div. 2)                          |
|       Task: A                                     |
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

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector <int> v(n);
    ivector(v, n);
    int m = 0, s = 0;
    for (int i = 1; i < n; i++)
        if (v[i] < v[i - 1])
        {
            m = max(m, i - s);
            s = i;
        }
    m = max(m, n - s);
    cout << m;
    return 0;
}