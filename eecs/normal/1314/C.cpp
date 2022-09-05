#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1010;
int n, m, lcp[maxn][maxn];
char s[maxn];
ll K, ways[maxn][maxn];
vector<int> cand[maxn];

void inc(ll &x, ll y) {
    if ((x += y) > K) x = K;
}

int main() {
    scanf("%d %d %lld %s", &n, &m, &K, s + 1);
    for (int i = n; i; i--) {
        for (int j = n; j; j--) {
            if (s[i] == s[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
        }
    }
    auto comp = [&](pair<int, int> p1, pair<int, int> p2) {
        int k = lcp[p1.first][p2.first];
        int t1 = p1.second - p1.first, t2 = p2.second - p2.first;
        if (k >= min(p1.second - p1.first + 1, p2.second - p2.first + 1)) {
            return t1 < t2 ? -1 : t1 == t2 ? 0 : 1;
        } else {
            return s[p1.first + k] < s[p2.first + k] ? -1 : 1;
        }
    };
    vector<pair<int, int>> V;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) V.emplace_back(i, j);
    }
    sort(V.begin(), V.end(), [&](pair<int, int> p1, pair<int, int> p2) { return comp(p1, p2) >= 0; });
    auto chk = [&](int l0, int r0) {
        memset(ways, 0, sizeof(ways)), ways[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            cand[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            int v = comp({i, n}, {l0, r0});
            if (v >= 0) cand[i + min({lcp[i][l0], r0 - l0})].push_back(i - 1);
        }
        for (int i = 1; i <= m; i++) {
            ll s = 0;
            for (int j = 1; j <= n; j++) {
                for (int k : cand[j]) inc(s, ways[i - 1][k]);
                inc(ways[i][j], s);
            }
        }
        return ways[m][n];
    };
    int l = 0, r = V.size() - 1, ans;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (chk(V[mid].first, V[mid].second) >= K) r = (ans = mid) - 1;
        else l = mid + 1;
    }
    for (int i = V[ans].first; i <= V[ans].second; i++) putchar(s[i]);
    return 0;
}