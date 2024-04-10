#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n;
vector<int> g[1005];
set<int> my, his;
int ans;

void dfs(int v, int p = -1) {
    if (ans != -1) {
        return;
    }
    if (my.count(v)) {
        int ver_in_his;
        cout << "A " << v << endl;
        cin >> ver_in_his;
        if (his.count(ver_in_his))
            ans = v;
        else
            ans = -2;
    }
    for (int to : g[v]) {
        if (p == to)
            continue;
        if (ans != -1)
            return;
        dfs(to, v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            g[i].clear();
        }
        for (int i = 1; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        my.clear();
        his.clear();
        int k1, k2;
        cin >> k1;
        for (int i = 0; i < k1; ++i) {
            int x;
            cin >> x;
            my.insert(x);
        }
        cin >> k2;
        for (int i = 0; i < k2; ++i) {
            int x;
            cin >> x;
            his.insert(x);
        }
        cout << "B " << *his.begin() << endl;
        int ver2;
        cin >> ver2;
        ans = -1;
        dfs(ver2);
        if (ans == -2)
            ans = -1;
        cout << "C " << ans << endl;
    }
}