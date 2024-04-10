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
#define left _left
#define right _right

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

const int N = 3e5 + 300, M = 1e6 + 100;

int n, k, a[N], left[N], right[N], sum[N], cnt[M];
ll ans = 0;
vector<pair<int, int> > q[N];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif

    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        sum[i + 1] = (sum[i] + a[i]) % k;
    }

    vector<int> magic;
    magic.pb(-1);
    for (int i = 0; i < n; i++) {
        while (magic.size() > 1 && a[magic.back()] < a[i]) {
            magic.pop_back();
        }
        left[i] = magic.back();
        magic.pb(i);
    }
    magic.clear();
    magic.pb(n);
    for (int i = n; i >= 0; i--) {
        while (magic.size() > 1 && a[magic.back()] <= a[i]) {
            magic.pop_back();
        }
        right[i] = magic.back();
        magic.pb(i);
    }

    for (int i = 0; i < n; i++) {
        if (right[i] - i > i - left[i]) {
            for (int j = left[i] + 1; j <= i; j++) {
                int want = (sum[j] + a[i] % k + k) % k;
                q[i + 1].eb(want, 1);
                q[right[i] + 1].eb(want, -1);
            }
        } else {
            for (int j = i + 1; j <= right[i]; j++) {
                int want = (sum[j] - a[i] % k + k) % k;
                q[left[i] + 1].eb(want, 1);
                q[i + 1].eb(want, -1);
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        for (auto j : q[i]) {
            cnt[j.fs] += j.sc;
        }
        ans += cnt[sum[i]];
    }

    printf(LLD"\n", ans - n);

    return 0;
}