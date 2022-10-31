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

const int N = 1e5 + 100;

int n, a[N];

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << a[1] - a[0] << ' ' << a[n - 1] - a[0] << endl;
    for (int i = 1; i < n - 1; i++) {
        cout << min(a[i] - a[i - 1], a[i + 1] - a[i]) << ' ' << max(a[i] - a[0], a[n - 1] - a[i]) << endl;
    }
    cout << a[n - 1] - a[n - 2] << ' ' << a[n - 1] - a[0] << endl;
    return 0;
}