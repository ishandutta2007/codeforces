#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

const int N = 1e4 + 7;

vector <int> t[4 * N];

void modify(int ql, int qr, int x, int v, int l, int r) {
    if (r < ql || qr < l) return;
    if (ql <= l && r <= qr) {
        t[v].push_back(x);
    }
    else {
        int m = (l + r) >> 1;
        modify(ql, qr, x, 2 * v + 1, l, m);
        modify(ql, qr, x, 2 * v + 2, m + 1, r);
    }
}

bitset <N> ans;

void dfs(int l, int r, int v, bitset <N> cur) {
    for (auto x : t[v]) {
        cur |= (cur << x);
    }
    if (l == r) {
        ans |= cur;
    }
    else {
        int m = (l + r) >> 1;
        dfs(l, m, 2 * v + 1, cur);
        dfs(m + 1, r, 2 * v + 2, cur);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < q; ++i) {
        int l, r, x;
        cin >> l >> r >> x;
        --l, --r;
        modify(l, r, x, 0, 0, n - 1);
    }
    bitset <N> cur;
    cur[0] = 1;
    dfs(0, n - 1, 0, cur);
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        if (ans[i]) ++res;
    }
    cout << res << '\n';
    for (int i = 1; i <= n; ++i) {
        if (ans[i]) {
            cout << i << ' ';
        }
    }
}