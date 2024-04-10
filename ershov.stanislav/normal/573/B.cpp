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
#define rank _rank

#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 1e5 + 100;

int a[N], n;
int mn[N];

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }

    int cur_mx = n;
    for (int i = n - 1; i >= 0; i--) {
        cur_mx = min(cur_mx, a[i] + i);
        mn[i] = cur_mx - i;
    }
//    cout << mx << endl;
    cur_mx = n;
    for (int i = 0; i < n; i++) {
        cur_mx = min(cur_mx, a[i] + n - 1 - i);
        mn[i] = min(mn[i], cur_mx - (n - 1 - i));
    }

    int mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, mn[i]);
//        cout << mn[i] << ' ';
    }

    cout << mx << endl;
    return 0;
}