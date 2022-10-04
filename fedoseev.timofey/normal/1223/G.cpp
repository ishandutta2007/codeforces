#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 5e5 + 7;
const ll Inf = 1e18;

int cnt[N];
int prv[N];
int pref[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    prv[0] = -1;
    for (int i = 1; i < N; ++i) {
        if (cnt[i]) prv[i] = i;
        else prv[i] = prv[i - 1];
    }
    for (int i = 0; i + 1 < N; ++i) pref[i + 1] = pref[i] + cnt[i];
    auto getSum = [&] (int l, int r) {
        return pref[r] - pref[l];
    };
    ll ans = 0;
    for (int y = 2; y < N; ++y) {
        ll cntY = 0;
        for (int j = 0; j * y < N; ++j) {
            cntY += (ll)j * getSum(j * y, min(N - 1, (j + 1) * y));
        }

        ll l = 1, r = cntY + 1;  
        while (r - l > 1) {
            ll m = (l + r) / 2;
            if (cntY < m) {
                r = m;
                continue;
            }
            auto checkDif = [&] () {
                ll mn1 = Inf, mn2 = Inf;

                auto Update = [&] (ll have) {
                    if (have < mn1) {
                        mn2 = mn1;
                        mn1 = have;
                    } else {
                        mn2 = min(mn2, have);
                    }
                };

                for (int j = 0; j * y < N; ++j) {
                    int L = j * y;
                    int R = min(N - 1, (j + 1) * y - 1);
                    int id = prv[R];
                    if (id < L || id < m) continue;
                    ll nd = max(0LL, (m - (id % y) + y - 1) / y);
                    Update(nd);
                    if (cnt[id] > 1) Update(nd);
                    else {
                        id = prv[id - 1];
                        if (id < L || id < m) continue;
                        nd = max(0LL, (m - (id % y) + y - 1) / y);
                        Update(nd);
                    }
                }
                return (cntY - mn1 - mn2 >= m);
            };
            auto checkSame = [&] () {
                ll mn = Inf;
                for (int j = 0; j * y < N; ++j) {
                    int L = j * y;
                    int R = min(N - 1, (j + 1) * y - 1);
                    int id = prv[R];
                    if (id < L || id < 2 * m) continue;
                    ll nd = (id / y) - (id - 2 * m) / y;
                    mn = min(mn, nd);
                }
                return (cntY - mn >= m);
            };
            if (checkDif() || checkSame()) {
                l = m;
            } else {
                r = m;
            }
        }
        if (l > 1) ans = max(ans, y * l);
    }
    cout << ans << '\n';
}