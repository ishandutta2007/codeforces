#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

#define all(x) x.begin(), x.end()

typedef long long ll;
typedef unsigned long long uli;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const int P = 1e9 + 7, Q = 1e9 + 9;
const int base = 41;
const double PI = 3.141592653589793238;
const double eps = 1e-7;

#ifdef DEBUG
#define dout(x) cerr << x
#else
#define dout(x)
#endif // DEBUG

#ifdef DEBUG
#define END {cout << endl; return main ();}
#else
#define END return 0
#endif

int main()
{
#ifdef DEBUG
    freopen ("test.in", "r", stdin);
#endif // DEBUG

    int n, d, h;
    cin >> n >> d >> h;
    if (n == 2 && d == 1 && h == 1)
    {
        cout << "1 2\n";
        return 0;
    }
    if (d == 1)
    {
        cout << -1 << endl;
        return 0;
    }
    if (d < h)
    {
        cout << -1 << endl;
        return 0;
    }
    if (d > 2 * h)
    {
        cout << -1 << endl;
        return 0;
    }
    if (d > n - 1)
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 2 ; i <= h + 1 ; ++i)
    {
        cout << i - 1 << ' ' << i << endl;
    }
    for (int i = h + 2 ; i <= d + 1 ; ++i)
    {
        if (i == h + 2)
        {
            cout << "1 " << i << endl;
        }
        else
        {
            cout << i - 1 << ' ' << i << endl;
        }
    }
    if (d != h)
    {
        for (int i = d + 2 ; i <= n ; ++i)
        {
            cout << "1 " << i << endl;
        }
    }
    else
    {
        for (int i = d + 2 ; i <= n ; ++i)
        {
            cout << "2 " << i << endl;
        }
    }
    return 0;
}