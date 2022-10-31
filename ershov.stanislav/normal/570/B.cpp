#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-10;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

int n, m;

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    cin >> n >> m;
    if (n == 1) {
        cout << 1 << endl;
    } else {
        if (n - m > m - 1) {
            cout << m + 1 << endl;
        } else {
            cout << m - 1 << endl;
        }
    }
    return 0;
}