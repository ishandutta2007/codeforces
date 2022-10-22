#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <bitset>

using namespace std;
#define int long long

const int MOD = 1000 * 1000 * 1000 + 7;
const int MAXN = 1e5 + 7;
const int MAXV = (1 << 20);

int a[MAXN];
int ans[MAXN];
bool dp1[MAXV], dp2[MAXV];

vector <pair <int, int> > q[MAXN];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < m; ++i) {
        int l, x;
        cin >> l >> x;
        q[l - 1].push_back({x, i});
    }

    dp1[0] = 1;
    int val = 1;
    for (int i = 0; i < n; ++i) {
        if (dp1[a[i]]) {
            val *= 2;
            val %= MOD;
        }
        else {
            for (int j = 0; j < MAXV; ++j) dp2[j] = dp1[j] | dp1[j ^ a[i]];
            for (int j = 0; j < MAXV; ++j) dp1[j] = dp2[j];
        }

        for (pair <int, int> nq : q[i]) {
            ans[nq.second] = val * dp1[nq.first];
        }
    }

    for (int i = 0; i < m; ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}