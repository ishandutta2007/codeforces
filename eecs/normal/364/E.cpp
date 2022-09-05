#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2510;
int n, m, K, s[maxn];
char str[maxn][maxn];
ll ans;
vector<int> lp, rp, V, L[maxn], R[maxn];

int main() {
    scanf("%d %d %d", &n, &m, &K);
    for (int i = 1; i <= n; i++) {
        scanf("%s", str[i] + 1);
    }
    function<void(int, int, int, int)> solve = [&](int l1, int r1, int l2, int r2) {
        if (l1 == r1) {
            for (int i = l2; i <= r2; i++) {
                for (int j = i, s = 0; j <= r2; j++) {
                    s += str[l1][j] == '1';
                    if (s == K) ans++;
                    if (s > K) break;
                }
            }
            return;
        }
        if (l2 == r2) {
            for (int i = l1; i <= r1; i++) {
                for (int j = i, s = 0; j <= r1; j++) {
                    s += str[j][l2] == '1';
                    if (s == K) ans++;
                    if (s > K) break;
                }
            }
            return;
        }
        if (r1 - l1 > r2 - l2) {
            int mid = (l1 + r1) / 2;
            for (int i = l2; i <= r2; i++) {
                L[i].clear(), R[i].clear();
                for (int j = mid; j >= l1 && L[i].size() <= K; j--) {
                    if (str[j][i] == '1') L[i].push_back(j);
                }
                for (int j = mid + 1; j <= r1 && R[i].size() <= K; j++) {
                    if (str[j][i] == '1') R[i].push_back(j);
                }
            }
            for (int i = l2; i <= r2; i++) {
                lp = {mid}, rp = {mid + 1};
                for (int j = i; j <= r2; j++) {
                    V.resize(lp.size() + L[j].size());
                    merge(lp.begin(), lp.end(), L[j].begin(), L[j].end(), V.begin(), greater<int>());
                    while (V.size() > K + 2) V.pop_back();
                    swap(lp, V), V.resize(rp.size() + R[j].size());
                    merge(rp.begin(), rp.end(), R[j].begin(), R[j].end(), V.begin());
                    while (V.size() > K + 2) V.pop_back();
                    swap(rp, V);
                    for (int k = 0; k < lp.size() && k <= K; k++) {
                        int _k = K - k;
                        if (_k >= rp.size()) continue;
                        ans += (lp[k] - (k + 1 == lp.size() ? l1 - 1 : lp[k + 1])) * ((_k + 1 == rp.size() ? r1 + 1 : rp[_k + 1]) - rp[_k]);
                    }
                }
            }
            solve(l1, mid, l2, r2), solve(mid + 1, r1, l2, r2);
        } else {
            int mid = (l2 + r2) / 2;
            for (int i = l1; i <= r1; i++) {
                L[i].clear(), R[i].clear();
                for (int j = mid; j >= l2 && L[i].size() <= K; j--) {
                    if (str[i][j] == '1') L[i].push_back(j);
                }
                for (int j = mid + 1; j <= r2 && R[i].size() <= K; j++) {
                    if (str[i][j] == '1') R[i].push_back(j);
                }
            }
            for (int i = l1; i <= r1; i++) {
                lp = {mid}, rp = {mid + 1};
                for (int j = i; j <= r1; j++) {
                    V.resize(lp.size() + L[j].size());
                    merge(lp.begin(), lp.end(), L[j].begin(), L[j].end(), V.begin(), greater<int>());
                    while (V.size() > K + 2) V.pop_back();
                    swap(lp, V), V.resize(rp.size() + R[j].size());
                    merge(rp.begin(), rp.end(), R[j].begin(), R[j].end(), V.begin());
                    while (V.size() > K + 2) V.pop_back();
                    swap(rp, V);
                    for (int k = 0; k < lp.size() && k <= K; k++) {
                        int _k = K - k;
                        if (_k >= rp.size()) continue;
                        ans += (lp[k] - (k + 1 == lp.size() ? l2 - 1 : lp[k + 1])) * ((_k + 1 == rp.size() ? r2 + 1 : rp[_k + 1]) - rp[_k]);
                    }
                }
            }
            solve(l1, r1, l2, mid), solve(l1, r1, mid + 1, r2);
        }
    };
    solve(1, n, 1, m);
    printf("%lld\n", ans);
	return 0;
}