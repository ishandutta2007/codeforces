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

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

using namespace std;

const int N = 1e6 + 100;

int n, q;
int a[N * 2];
int next[N * 2];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    scanf("%d%d", &n, &q);
//    n = 1e6;
//    q = 1;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
//        a[i] = rand() + 1;
//        mx = max(a[i], mx);
    }
    for (int i = 0; i < n; i++) {
        a[i + n] = a[i];
    }
    for (int t = 0; t < q; t++) {
        long long b;
        scanf(LLD, &b);
//        cout << b << endl;
//        b = rand() * 1ll * 1000 + rand();
//        b = max(mx * 1ll, b);
        long long cur = 0;
        int mn = INF, mni = 0;
        for (int i = 0, j = 0; i < 2 * n; i++) {
            while (j < 2 * n && cur + a[j] <= b) {
                cur += a[j];
                j++;
            }
            if (i < n && j - i < mn) {
                mn = j - i;
                mni = i;
            }
            next[i] = j;
//            cout << next[i] << ' ';
            cur -= a[i];
        }
//        cout << endl;
        int ans = INF;
        for (int i = mni + 1; i < n && i <= mni + mn; i++) {
            int cnt = 0;
//            cout << mni + 1 << ' ' << next[mni + 1] << endl;
            for (int cur2 = i; cur2 < i + n; cur2 = next[cur2]) {
                cnt++;
            }
            ans = min(ans, cnt);
        }
        if (mni + mn > n) for (int i = 0; i <= (mni + mn) % n; i++) {
            int cnt = 0;
            for (int cur = i; cur < i + n; cur = next[cur]) {
                cnt++;
            }
            ans = min(ans, cnt);
        }

        printf("%d\n", ans);
    }
    return 0;
}