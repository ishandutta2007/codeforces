#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

#define die return void(cout << "NO")

void solve() {
    int n;
    cin >> n;
    set<int> add;
    for (int i = 0; i < n; i++) add.insert(i);
    vt<int> buy(n + 1);
    vt<vt<int>> buy_q(n);
    int idx = -1;
    for (int i = 0; i < n * 2; i++) {
        char c;
        cin >> c;
        
        if (c == '+') idx++;
        else {
            int x;
            cin >> x;
            buy[x] = idx;
            if (~idx) buy_q[idx].push_back(x);
        }
    }

    vt<int> ans(n);
    for (int i = 1; i <= n; i++) {
        auto it = add.upper_bound(buy[i]);
        if (it == add.begin()) die;
        
        it--;
        ans[*it] = i;
        add.erase(it);
    }

    priority_queue<int> shu;
    for (int i = 0; i < n; i++) {
        shu.push(-ans[i]);
        for (int x : buy_q[i]) {
            int cur = -shu.top();
            shu.pop();
            if (x != cur) die;
        }
    }

    cout << "YES\n";
    for (int x : ans) cout << x << ' ';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}