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

int obstacle[200005];

int main()
{
#ifdef DEBUG
    freopen ("test.in", "r", stdin);
#endif // DEBUG

    int n, m, s, d;
    cin >> n >> m >> s >> d;
    for (int i = 0 ; i < n ; ++i)
    {
        cin >> obstacle[i];
    }
    sort (obstacle, obstacle + n);
    if (n == 0)
    {
        cout << "RUN " << m << endl;
        return 0;
    }
    if (obstacle[0] <= s)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    int jump = 2;
    for (int i = 1; i < n ; ++i)
    {
        if (obstacle[i] - obstacle[i - 1] <= s + 1)
            jump += obstacle[i] - obstacle[i - 1];
        else
        {
            if (jump > d)
            {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
            else
                jump = 2;
        }
    }
    if (jump > d)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << "RUN " << obstacle[0] - 1 << endl;
    jump = 2;
    for (int i = 1 ; i < n ; ++i)
    {
        if (obstacle[i] - obstacle[i - 1] <= s + 1)
        {
            jump += obstacle[i] - obstacle[i - 1];
        }
        else
        {
            cout << "JUMP " << jump << endl;
            cout << "RUN " << obstacle[i] - obstacle[i - 1] - 2 << endl;
            jump = 2;
        }
    }
    cout << "JUMP " << jump << endl;
    if (m - obstacle[n - 1] - 1 > 0)
    {
        cout << "RUN " << m - obstacle[n - 1] - 1 << endl;
    }
    return 0;
}