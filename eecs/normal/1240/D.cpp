#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;

const int maxn = 300010, P1 = 1000000007, P2 = 1000000009, B = 998244353;
int T, n, a[maxn];
__gnu_pbds::gp_hash_table<unsigned long long, int> mp;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        long long ans = 0;
        function<void(int, int)> solve = [&](int l, int r) {
            if (l == r) return;
            int mid = (l + r) / 2;
            solve(l, mid), solve(mid + 1, r);
            vector<array<int, 3>> st = {{0, 0, 0}};
            mp.clear();
            for (int i = mid; i >= l; i--) {
                if (st.back()[0] == a[i]) st.pop_back();
                else st.push_back({a[i], (1LL * st.back()[1] * B + a[i]) % P1, (1LL * st.back()[2] * B + a[i]) % P2});
                mp[1uLL * st.back()[1] * P2 + st.back()[2]]++;
            }
            st = {{0, 0, 0}};
            for (int i = mid + 1; i <= r; i++) {
                if (st.back()[0] == a[i]) st.pop_back();
                else st.push_back({a[i], (1LL * st.back()[1] * B + a[i]) % P1, (1LL * st.back()[2] * B + a[i]) % P2});
                auto h = 1uLL * st.back()[1] * P2 + st.back()[2];
                if (mp.find(h) != mp.end()) ans += mp[h];
            }
        };
        solve(1, n);
        printf("%lld\n", ans);
    }
    return 0;
}