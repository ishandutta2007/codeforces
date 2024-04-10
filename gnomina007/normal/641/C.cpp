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

int desk[1000005];

int main()
{
#ifdef DEBUG
    freopen ("test.in", "r", stdin);
#endif // DEBUG

    int n, q;
    scanf ("%d%d", &n, &q);
    ll pos1 = 0, pos2 = 1;
    for (int i = 0 ; i < q ; ++i)
    {
        int t;
        scanf ("%d", &t);
        if (t == 1)
        {
            int s;
            scanf ("%d", &s);
            if (s < 0)
                s = n + s;
            pos1 = (pos1 + s);
            pos2 = (pos2 + s);
        }
        else
        {
            if (pos1 % 2 == 0)
            {
                ++pos1;
                --pos2;
            }
            else
            {
                --pos1;
                ++pos2;
            }
        }
    }
    pos1 %= n;
    pos2 %= n;
    for (int i = 0 ; i < n / 2 ; ++i)
    {
        desk[pos1] = 1 + i * 2;
        desk[pos2] = 2 + i * 2;
        pos1 = (pos1 + 2);
        if (pos1 >= n)
            pos1 -= n;
        pos2 = (pos2 + 2);
        if (pos2 >= n)
            pos2 -= n;
    }
    for (int i = 0 ; i < n ; ++i)
    {
        printf("%d ", desk[i]);
    }
    return 0;
}