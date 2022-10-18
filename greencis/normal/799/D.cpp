#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll a, b, h, w, n;
ll p[100105];
int ans = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> a >> b >> h >> w >> n;
    if ((a <= h && b <= w) || (a <= w && b <= h)) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < n; ++i)
        cin >> p[i];
    sort(p, p + n, greater<ll>());
    n = min(n, 34LL);
    for (int iter = 2; iter--; swap(a, b)) {
        ll height = max(1LL, (a + h - 1) / h);
        ll width = max(1LL, (b + w - 1) / w);
        vector<char> used(100005);
        used[1] = 1;
        ll pref = 1;
        ld pref_ld = 1;
        ll mx_greater = (ll)9e18;
        bool found = false;
        for (int i = 0; i < n && !found; ++i) {
            pref *= p[i];
            pref_ld *= p[i];
            for (ll j = 100004; j >= 0; --j) {
                if (!used[j])
                    continue;
                ll nxt = j * p[i];
                if (nxt <= 100004)
                    used[nxt] = 1;
                else
                    mx_greater = min(mx_greater, nxt);
            }
            for (ll j = 100004; j >= 0; --j) {
                if (!used[j])
                    continue;
                if ((j >= height && (pref_ld / j >= 1e8 || pref / j >= width)) ||
                    (j >= width && (pref_ld / j >= 1e8 || pref / j >= height))) {
                    found = true;
                    ans = min(ans, i + 1);
                    break;
                }
            }
            if (mx_greater < (ll)9e18 && ((pref_ld / mx_greater >= 1e8 || pref / mx_greater >= width) ||
                                        (pref_ld / mx_greater >= 1e8 || pref / mx_greater >= height))) {
                found = true;
                ans = min(ans, i + 1);
            }
        }
    }

    if (ans > 1000000)
        ans = -1;
    cout << ans << endl;

    return 0;
}