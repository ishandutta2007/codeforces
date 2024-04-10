#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, K, m, a[maxn];
long long ans, inc, sum;
vector<pair<int, int>> st;

int main() {
    scanf("%d %d %d", &n, &K, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (st.empty() || st.back().first ^ a[i]) st.emplace_back(a[i], 1);
        else ++st.back().second %= K;
        if (!st.back().second) st.pop_back();
    }
    for (auto p : st) ans += p.second;
    int l = 0, r = (int)st.size() - 1;
    while (l < r && st[l].first == st[r].first && (st[l].second + st[r].second) % K == 0) {
        inc += st[l].second + st[r].second;
        l++, r--;
    }
    if (l == r) {
        sum -= 1LL * st[l].second * m / K * K;
        if (1LL * st[l].second * m % K == 0) sum -= inc;
    } else if (st[l].first == st[r].first) {
        inc += (st[l].second + st[r].second) / K * K;
    }
    printf("%lld\n", sum + m * ans - inc * (m - 1));
    return 0;
}