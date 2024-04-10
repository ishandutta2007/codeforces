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

int arr[1000005];

int main()
{
#ifdef DEBUG
    freopen ("test.in", "r", stdin);
#endif // DEBUG

    int n;
    cin >> n;
    int winner = -1;
    int mx = 0;
    for (int i = 0 ; i < 1000005 ; ++i)
    {
        arr[i] = 0;
    }
    for (int i = 0 ; i < n ; ++i)
    {
        int a;
        cin >> a;
        ++arr[a];
        if (arr[a] > mx)
        {
            winner = a;
            mx = arr[a];
        }
    }
    cout << winner;
    return 0;
}