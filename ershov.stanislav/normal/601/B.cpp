#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int maxn = 1e5 + 100;
int n, q;
int a[maxn], b[maxn];

int main() {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    for (int i = 0; i < n - 1; i++) {
        b[i] = abs(a[i + 1] - a[i]);
    }
    for (int t = 0; t < q; t++) {
        int l, r;
        scanf("%d%d", &l, &r);
        l--, r--;
        ll ans = 0;
        ll cursum = 0;
        vector<pair<int, int> > v;
        for (int i = l; i < r; i++) {
            ll sum = 0;
            while (sz(v) && v.back().first <= b[i]) {
                sum += v.back().second;
                cursum -= (ll) (v.back().second) * (v.back().first);
                v.pop_back();
            }
            sum += 1;
            v.eb(b[i], sum);
            cursum += (ll) sum * b[i];
            ans += cursum;
        }
        printf(LLD "\n", ans);
    }
    return 0;
}