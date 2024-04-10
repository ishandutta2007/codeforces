#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int K = 20;

bool hv[1 << K];
int best[1 << K];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        int mask = 0;
        for (int ln = 1; ln <= K && i + ln <= n; ++ln) {
            if (mask & (1 << (s[i + ln - 1] - 'a'))) break;
            mask |= (1 << (s[i + ln - 1] - 'a'));
            hv[mask] = 1;
        }
    }
    for (int mask = 0; mask < (1 << K); ++mask) {
        if (hv[mask]) best[mask] = max(best[mask], __builtin_popcount(mask));
        for (int i = 0; i < K; ++i) best[mask | (1 << i)] = max(best[mask | (1 << i)], best[mask]);
    }
    int ans = 0;
    for (int mask = 0; mask < (1 << K); ++mask) {
        ans = max(ans, best[mask] + best[((1 << K) - 1) ^ mask]);
    }
    cout << ans << '\n';
}