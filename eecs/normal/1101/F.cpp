#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 410;
int n, m, a[maxn], f[maxn][maxn];
vector<tuple<int, int, int>> Q[maxn];
long long ans;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    while (m--) {
        int s, t, c, r;
        scanf("%d %d %d %d", &s, &t, &c, &r);
        Q[s].emplace_back(t, c, min(r, t - s));
    }
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            f[0][j] = a[j] - a[i];
        }
        for (int d = 1; d <= n - i; d++) {
            vector<int> st;
            for (int j = i, _j = i; j <= n; j++) {
                while (_j < j && f[d - 1][_j] < a[j] - a[_j]) _j++;
                f[d][j] = f[d - 1][j];
                if (_j > i) f[d][j] = min(f[d][j], a[j] - a[_j - 1]);
                if (_j < j) {
                    auto it = lower_bound(st.begin(), st.end(), _j);
                    f[d][j] = min(f[d][j], f[d - 1][*it]);
                }
                while (!st.empty() && f[d - 1][st.back()] > f[d - 1][j]) st.pop_back();
                st.push_back(j);
            }
        }
        for (auto &p : Q[i]) {
            ans = max(ans, 1LL * get<1>(p) * f[get<2>(p)][get<0>(p)]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}