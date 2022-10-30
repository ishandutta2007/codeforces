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

int desk[105][105];
pair< int, int > act[10005];

int main()
{
#ifdef DEBUG
    freopen ("test.in", "r", stdin);
#endif // DEBUG

    int actcnt = 0;
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0 ; i < n ; ++i)
    {
        for (int j = 0 ; j < m ; ++j)
        {
            desk[i][j] = 0;
        }
    }
    for (int i = 0 ; i < q ; ++i)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int r;
            cin >> r;
            --r;
            int mem = desk[r][0];
            for (int j = 0 ; j < m - 1 ; ++j)
            {
                desk[r][j] = desk[r][j + 1];
            }
            desk[r][m - 1] = mem;
            act[actcnt] = mp (1, r);
            //dout (actcnt << ' ' << act[actcnt].fs << endl);
            ++actcnt;
        }
        else if (t == 2)
        {
            int c;
            cin >> c;
            --c;
            int mem = desk[0][c];
            for (int j = 0 ; j < n - 1 ; ++j)
            {
                desk[j][c] = desk[j + 1][c];
            }
            desk[n - 1][c] = mem;
            act[actcnt] = mp (2, c);
            ++actcnt;
        }
        else
        {
            int r, c, x;
            cin >> r >> c >> x;
            --r;
            --c;
            desk[r][c] = x;
        }
    }
    for (int i = actcnt - 1 ; i >= 0 ; --i)
    {
        int r;
        //dout (act[i].fs << endl);
        if (act[i].fs == 1)
        {
            r = act[i].sc;
            //dout (r << endl);
            int mem = desk[r][m - 1];
            for (int j = m - 1 ; j > 0 ; --j)
            {
                desk[r][j] = desk[r][j - 1];
            }
            desk[r][0] = mem;
        }
        else
        {
            r = act[i].sc;
            //dout (r << endl);
            int mem = desk[n - 1][r];
            for (int j = n - 1 ; j > 0 ; --j)
            {
                desk[j][r] = desk[j - 1][r];
            }
            desk[0][r] = mem;
        }
    }
    for (int i = 0 ; i < n ; ++i)
    {
        for (int j = 0 ; j < m ; ++j)
        {
            cout << desk[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}