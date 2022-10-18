#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int ans = 0;
    vector<vector<int>> st;
    auto get = [&st](int l, int r) {
        int high = 31 - __builtin_clz(int32_t(r - l + 1));
        return gcd(st[r][high], st[l + (1 << high) - 1][high]);
    };
    while (n--) {
        int x;
        cin >> x;
        int k = st.size();
        vector<int> cur{x};
        for (int h = 1; h < 19; ++h) {
            int ni = k - (1 << (h - 1));
            cur.push_back(gcd(cur.back(), ni >= 0 ? st[ni][h - 1] : 0));
        }
        st.push_back(cur);

        int L = k;
        int curGcd = x;
        bool good = true;
        while (true) {
            int lo = -1, hi = L - 1;
            while (lo < hi) {
                int mid = (lo + hi + 1) >> 1;
                if (get(mid, k) != curGcd)
                    lo = mid;
                else
                    hi = mid - 1;
            }
            int len1 = k - L + 1;
            int len2 = k - (lo + 1) + 1;
            if (len1 <= curGcd && curGcd <= len2) {
                good = false;
                break;
            }
            if (lo == -1)
                break;
            L = lo;
            curGcd = get(lo, k);
        }
        if (!good) {
            ++ans;
            st.clear();
        }
        cout << ans << ' ';
    }
}