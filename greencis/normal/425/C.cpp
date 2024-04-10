//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

constexpr int MAXN = 100'000;
vector<int> va[MAXN + 1];
vector<int> vb[MAXN + 1];
int prefMin[MAXN];
int newBest[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s, e;
    cin >> n >> m >> s >> e;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        va[x].push_back(i);
    }
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        vb[x].push_back(i);
    }

    fill_n(prefMin, n, -1);
    int ans = 0;
    for (int iter = 1; iter * e <= s; ++iter) {
        for (int val = 1; val <= MAXN; ++val) {
            int sz = (int)vb[val].size();
            int j = sz;
            for (int i : va[val]) {
                int curMin = prefMin[i];
                while (j > 0 && vb[val][j - 1] > curMin)
                    --j;
                newBest[i] = (j == sz ? m : vb[val][j]);
                if (newBest[i] < m && iter * e + (i + 1) + (newBest[i] + 1) <= s)
                    ans = iter;
            }
        }
        int curMin = m;
        for (int i = 0; i < n; ++i) {
            prefMin[i] = curMin;
            curMin = min(curMin, newBest[i]);
        }
    }
    cout << ans << '\n';
}