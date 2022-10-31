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

const int INF = (int) 1e9 + 100;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

int main() {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    ll a, b;
    cin >> a >> b;
    int ans = 0;
    for (int cnt = 2; cnt < 63; cnt++) {
        ll cur = (1ll << cnt) - 1;
        for (int i = 0; i + 1 < cnt; i++) {
            ll r = (cur ^ (1ll << i));
            if (r >= a && r <= b) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}