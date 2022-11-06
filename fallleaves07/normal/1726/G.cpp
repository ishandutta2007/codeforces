#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int M = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i].second;
    }
    auto solve = [&]() {
        sort(p.begin(), p.end());
        int val = p[0].first;
        if (p[0].second == 1) {
            for (int i = 1; i < n; i++) {
                if (p[i].first > p[0].first) {
                    ++val;
                }
            }
        }
        vector<int> lim(n);
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && p[i] == p[i + 1] && p[i].second == 1 && val > p[i].first) {
                return 0;
            }
            int d = val - p[i].first;
            if (d < 0) {
                return 0;
            }
            if (p[i].second == 0) {
                lim[i] = d;
            } else {
                int suf = p.end() - upper_bound(p.begin(), p.end(), p[i]);
                if (d < suf) {
                    return 0;
                }
                if (d == 0) {
                    if (suf) {
                        return 0;
                    } else {
                        lim[i] = -1;
                    }
                } else {
                    int pre = lower_bound(p.begin(), p.end(), p[i]) - p.begin();
                    if (pre < d - suf) {
                        return 0;
                    }
                    lim[i] = pre - (d - suf);
                }
            }
        }
        int ans = 1;
        for (int i = 0; i < n;) {
            int j = i, cnt = 0;
            map<int, int> pts;
            while (j < n && p[j] == p[i]) {
                if (lim[j] == -1) {
                    ++cnt;
                } else if (lim[j] <= i) {
                    ans = 1ll * ans * (++pts[lim[j]]) % M;
                } else {
                    return 0;
                }
                ++j;
            }
            for (int k = 1; k <= cnt; k++) {
                ans = 1ll * ans * (j - k + 1) % M;
            }
            i = j;
        }
        return ans;
    };
    printf("%d\n", (solve() % M + M) % M);
    return 0;
}