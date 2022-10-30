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

using namespace std;

const int N = 800200;

int n, a[N], ans[N];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 2; i <= n; i++) {
        for (int k = 1; k <= n - 1; ) {
            int nxt = 0;
            if (((i - 2) / k) + 1 > 1) {
                nxt = max(k + 1, (i - 2) / ((i - 2) / k) + 1);
            } else {
                nxt = n + 1;
            }
            if (a[i] < a[(i - 2) / k + 1]) {
                ans[k]++;
                ans[nxt]--;
            }
            k = nxt;
        }
    }
    for (int i = 1; i <= n - 1; i++) {
        ans[i] += ans[i - 1];
        printf("%d ", ans[i]);
    }
    return 0;
}