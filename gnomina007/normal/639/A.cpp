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

int arr[150005];
int cur[10];

int main()
{
#ifdef DEBUG
    freopen ("test.in", "r", stdin);
#endif // DEBUG

    int n, k, q;
    cin >> n >> k >> q;
    for (int i = 0 ;i < n ; ++i)
    {
        cin >> arr[i];
    }
    arr[n] = -INF;
    for (int i = 0 ; i < 10 ; ++i)
    {
        cur[i] = n;
    }
    for (int i = 0 ; i < q ; ++i)
    {
        int t, id;
        cin >> t >> id;
        if (t == 1)
        {
            int temp = id - 1;
            for (int j = 0 ; j < k ; ++j)
            {
                if (arr[temp] > arr[cur[j]])
                {
                    swap (temp, cur[j]);
                }
            }
        }
        else
        {
            bool flag = true;
            for (int j = 0 ; j < k ; ++j)
            {
                if (cur[j] == id - 1)
                {
                    flag = false;
                    cout << "YES\n";
                    break;
                }
            }
            if (flag)
            {
                cout << "NO\n";
            }
        }
    }
    return 0;
}