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
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 510;

bool a[N][N];
int n, m, q;
int cur[N];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d%d%d", &n, &m, &q);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int last = -1, r = 0; r < m; r++) {
            if (a[i][r]) {
                cur[i] = max(cur[i], r - last);
            } else {
                last = r;
            }
        }
    }

    for (int k = 0; k < q; k++) {
        int i, j;
        scanf("%d%d", &i, &j);
        i--, j--;

        a[i][j] = a[i][j] != true;

        cur[i] = 0;

        for (int last = -1, r = 0; r < m; r++) {
            if (a[i][r]) {
                cur[i] = max(cur[i], r - last);
            } else {
                last = r;
            }
        }
        int mx = 0;
        for (int r = 0; r < n; r++) {
            mx = max(mx, cur[r]);
        }

        printf("%d\n", mx);
    }

    return 0;
}