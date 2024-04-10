#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int maxn = 1005;
int n, m, a[maxn], b[maxn];
array<int, 3> bit[maxn][maxn], dp[maxn][maxn];
vector<array<int, 3>> v;

void upd(int x, int y, int z) {
    array<int, 3> d = {z, x, y};
    for (int i = x; i < n; i = i | (i + 1))
        for (int j = y; j < m; j = j | (j + 1))
            bit[i][j] = max(bit[i][j], d);
}

array<int, 3> qry(int x, int y) {
    array<int, 3> ret = {0, -1, -1};
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
        for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
            ret = max(ret, bit[i][j]);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            bit[i][j] = {0, i, j};
            dp[i][j] = {0, -1, -1};
            if (a[i] == b[j])
                v.pb({a[i], i, j});
        }
    sort(all(v));
    array<int, 3> out = {1, 0, 0};
    vector<array<int, 3>> sto;
    for (int k = 0; k < v.size(); k++) {
        auto [x, i, j] = v[k];
        dp[i][j] = qry(i-1, j-1);
        dp[i][j][0]++;
        sto.pb({i, j, dp[i][j][0]});
        out = max(out, {dp[i][j][0]+1, i, j});
        if (k < v.size()-1 && x != v[k+1][0])
            while (!sto.empty()) {
                auto [x1, y, z] = sto.back(); sto.pop_back();
                upd(x1, y, z);
            }
    }
    cout << out[0]-1 << "\n";
    int i = out[1], j = out[2];
    vector<int> s;
    while (i >= 0 && j >= 0 && dp[i][j][0] > 0) {
        s.pb(a[i]);
        tie(i, j) = {dp[i][j][1], dp[i][j][2]};
    }
    reverse(all(s));
    for (auto& x : s)
        cout << x << " ";
}