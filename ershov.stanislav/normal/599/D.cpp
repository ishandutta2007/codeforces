#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

#define fs first
#define sc second

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

ll want;

int main () {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    cin >> want;
    vector<pair<ll, ll> > ans1;
    vector<pair<ll, ll> > ans2;
    for (ll i = 1; ; i++) {
        ll sumsq = (i * (i + 1) * (2 * i + 1)) / 6;
        if (sumsq > want) {
            break;
        }
        ll add = i * (i + 1) / 2;
        if ((want - sumsq) % add == 0) {
            ans1.eb(i, i + (want - sumsq) / add);
            if (want > sumsq) {
                ans2.eb(i + (want - sumsq) / add, i);
            }
        }
    }
    reverse(all(ans2));
    cout << sz(ans1) + sz(ans2) << endl;
    for (int i = 0; i < sz(ans1); i++) {
        printf(LLD " " LLD "\n", ans1[i].first, ans1[i].second);
    }
    for (int i = 0; i < sz(ans2); i++) {
        printf(LLD " " LLD "\n", ans2[i].first, ans2[i].second);
    }
    return 0;
}