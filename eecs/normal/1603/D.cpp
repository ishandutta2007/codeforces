#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, U = 100000;
int T, phi[maxn];
long long pre[maxn], f[18][maxn];
vector<pair<int, int>> d[maxn];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    for (int i = 1; i <= U; i++) {
        pre[i] = pre[i - 1] + (phi[i] += i);
        for (int j = i; j <= U; j += i) {
            d[j].emplace_back(i, 0);
            if (j > i) phi[j] -= phi[i];
        }
    }
    for (int i = 1; i <= U; i++) {
        d[i].emplace_back(U + 1, 0);
        for (int j = d[i].size() - 2; ~j; j--) {
            d[i][j].second = d[i][j + 1].second + phi[i / d[i][j].first];
        }
    }
    auto calc = [&](int l, int r) {
        static int pl = 1, pr = 1;
        static long long cur = 1;
        while (pl > l) cur += pre[pr / --pl];
        while (pr < r) pr++, cur += lower_bound(d[pr].begin(), d[pr].end(), make_pair(pl, 0))->second;
        while (pl < l) cur -= pre[pr / pl++];
        while (pr > r) cur -= lower_bound(d[pr].begin(), d[pr].end(), make_pair(pl, 0))->second, pr--;
        return cur;
    };
    memset(f, 0x3f, sizeof(f)), f[0][0] = 0;
    for (int k = 1; k < 18; k++) {
        function<void(int, int, int, int)> solve = [&](int l, int r, int ql, int qr) {
            if (l > r) return;
            int mid = (l + r) / 2, p;
            for (int i = ql; i <= qr && i < mid; i++) if (f[k - 1][i] < f[k][mid]) {
                long long v = f[k - 1][i] + calc(i + 1, mid);
                if (v < f[k][mid]) f[k][mid] = v, p = i;
            }
            solve(l, mid - 1, ql, p), solve(mid + 1, r, p, qr);
        };
        solve(k, U, 0, U);
    }
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        cout << (k >= 18 ? n : f[k][n]) << '\n';
    }
    return 0;
}