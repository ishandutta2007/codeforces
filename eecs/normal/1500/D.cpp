#include <bits/stdc++.h>
using namespace std;

const int maxn = 1510;
int n, q, tim, f[maxn], c[maxn][maxn], vis[maxn * maxn];
vector<pair<int, int>> S[maxn][maxn];

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
        }
    }
    for (int i = n; i; i--) {
        for (int j = n; j; j--) {
            vector<pair<int, int>> V = {{0, c[i][j]}};
            auto upd = [&](vector<pair<int, int>> &S) {
                vector<pair<int, int>> T(V.size() + S.size());
                merge(V.begin(), V.end(), S.begin(), S.end(), T.begin()), V = T;
            };
            upd(S[i][j + 1]), upd(S[i + 1][j]);
            upd(S[i + 1][j + 1]), tim++;
            for (auto p : V) if (vis[p.second] ^ tim) {
                vis[p.second] = tim;
                S[i][j].emplace_back(p.first + 1, p.second);
                if (S[i][j].size() > q) break;
            }
            int t = S[i][j].size() > q ? S[i][j][q].first : INT_MAX;
            f[1]++, f[min({n - i + 2, n - j + 2, t})]--;
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", f[i] += f[i - 1]);
    }
    return 0;
}