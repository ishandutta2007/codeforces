#include <bits/stdc++.h>

//  ,  .....

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

// #define int long long

using namespace std;

const int N = 228 + 47 + 69;
const int inf = 2e9;

int A[N][N];
int pref1[N][N];
int pref2[N][N];

int t_normal, t_up, t_down;
int n, m, t;

bool check_coord(int a, int b) {
    if (a < 0 || a >= n || b < 0 || b >= m)
        return true;
    return false;
}

int cost(int a, int b, int c, int d) {
    if (check_coord(a, b) || check_coord(c, d))
        return 0;
    if (A[a][b] == A[c][d])
        return t_normal;
    if (A[a][b] > A[c][d])
        return t_up;
    if (A[a][b] < A[c][d])
        return t_down;
    return 228 * 47;
}

set<pair<int, int>> sum;
array<int, 5> inf_array = {inf, -1, -1, -1, -1};

array<int, 5> make_array(int val, int pos1, int pos2, int l_up, int l_down) {
    val = abs(val);
    return {val, min(l_up, l_down), min(pos1, pos2), max(l_up, l_down), max(pos1, pos2)};
}

array<int, 5> calc_ans(set<pair<int, int>>::iterator it, int dop, int pos, int l_up, int l_down) {
    array<int, 5> ans = inf_array;
    for (int i = 0; i < 2; ++i) {
        if (it == sum.end())
            break;
        if (abs(it->second - pos) != 1)
            ans = min(ans, make_array(it->first + dop - t, pos, it->second, l_up, l_down));
        ++it;
    }

    for (int i = 0; i < 4; ++i) {
        if (it != sum.end() && abs(it->second - pos) != 1)
            ans = min(ans, make_array(it->first + dop - t, pos, it->second, l_up, l_down));
        if (it == sum.begin())
            break;
        --it;
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> t;
    cin >> t_normal >> t_up >>t_down;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cin >> A[i][j];
    }

    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            pref1[i + 1][j] = pref1[i][j] + cost(i, j, i - 1, j);
        }
        for (int i = n - 1; i >= 0; --i) {
            pref2[i][j] = pref2[i + 1][j] + cost(i, j, i + 1, j);
        }
    }

    array<int, 5> ans = inf_array;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 2; j < n; ++j) {
            sum.clear();
            int mod = 0;
            sum.emplace(pref2[i][0] - pref2[j][0], 1);
            for (int k = 1; k < m; ++k) {
                int tmp = cost(i, k, i, k - 1) + cost(j, k - 1, j, k);
                mod += tmp;
                int C = pref1[j + 1][k] - pref1[i + 1][k];
                auto it = sum.lower_bound(make_pair(t - mod - C, -1));
                ans = min(ans, calc_ans(it, mod + C, k + 1, i + 1, j + 1));

                int val = pref2[i][k] - pref2[j][k] - mod;
                    sum.emplace(pref2[i][k] - pref2[j][k] - mod, k + 1);
            }
        }
    }
    if (ans[3] - ans[1] == 1 || ans[4] - ans[2] == 1)
        return 1;

    cout << ans[1] << ' ' << ans[2] << ' ' << ans[3] << ' ' << ans[4] << '\n';
}