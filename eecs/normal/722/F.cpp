#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, k[maxn], num[maxn], g[41][41];
multiset<int> S[41];
vector<array<int, 2>> V[maxn];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &k[i]);
        for (int j = 0, x; j < k[i]; j++) {
            scanf("%d", &x), V[x].push_back({i, j});
        }
    }
    for (int i = 1; i <= 40; i++) {
        for (int j = 1; j <= 40; j++) g[i][j] = __gcd(i, j);
    }
    auto chk = [&]() {
        for (int i = 1; i <= 40; i++) {
            if (S[i].empty()) num[i] = -1;
            else if (*S[i].begin() ^ *S[i].rbegin()) return 0;
            else num[i] = *S[i].begin();
        }
        for (int i = 1; i <= 40; i++) if (~num[i]) {
            for (int j = i + 1; j <= 40; j++) if (~num[j]) {
                if ((num[i] - num[j]) % g[i][j]) return 0;
            }
        }
        return 1;
    };
    for (int x = 1; x <= m; x++) {
        auto &vec = V[x];
        int ans = 0;
        for (int l = 0, r = 0; l < vec.size(); l++) {
            for (; r < vec.size() && vec[r][0] == vec[l][0] + r - l; r++) {
                S[k[vec[r][0]]].insert(vec[r][1]);
                if (!chk()) { S[k[vec[r][0]]].erase(S[k[vec[r][0]]].find(vec[r][1])); break; }
            }
            ans = max(ans, r - l);
            S[k[vec[l][0]]].erase(S[k[vec[l][0]]].find(vec[l][1]));
        }
        printf("%d\n", ans);
    }
    return 0;
}