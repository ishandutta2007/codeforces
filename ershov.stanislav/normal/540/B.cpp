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

#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9 + 100;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

int n, k, p, x, y, a[1111], b[1111];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    scanf("%d%d%d%d%d", &n, &k, &p, &x, &y);

    int cnt = 0, all = 0;
    for (int i = 0; i < k; i++) {
        scanf("%d", a + i);
        if (a[i] >= y) {
            cnt++;
        }
        all++;
    }
    for (; all < n && cnt < (n + 1) / 2; all++) {
        a[all] = y;
        cnt++;
    }
    for (; all < n; all++) {
        a[all] = 1;
    }

    bool good = true;
    for (int i = 0; i < n; i++) {
        b[i] = a[i];
//        cout << a[i] << ' ';
    }
    sort(a, a + n);
    if (a[n / 2] < y) {
        good = false;
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    if (sum > x) {
        good = false;
    }

    if (good) {
        for (int i = k; i < n; i++) {
            cout << b[i] << ' ';
        }
    } else {
        cout << "-1\n";
    }

    return 0;
}