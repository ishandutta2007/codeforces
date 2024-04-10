#include <bits/stdc++.h>
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();
 
using namespace std;

int per(int l1, int r1, int l2, int r2) {
    int L = max(l1, l2), R = min(r1, r2);
    if ((L == l1 && R == r1) || (l2 == L && r2 == R))
        return 0;
    if (max(l1, l2) <= min(r1, r2))
        return 1;
    return 0;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(k);
    set<int> used;
    for (int i = 0; i < k; ++i) {
        cin >> a[i].first >> a[i].second;
        if (a[i].second < a[i].first) {
            swap(a[i].first, a[i].second);
        }
        used.insert(a[i].first);
        used.insert(a[i].second);
    }
    vector<int> f;
    for (int i = 1; i <= 2 * n; ++i) {
        if (!used.count(i))
            f.push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < (int) f.size() / 2; ++i) {
        int x = f[i], y = f[i + f.size() / 2];
        a.emplace_back(x, y);
    }
    for (int i = 0; i < (int) a.size(); ++i) {
        for (int j = i + 1; j < (int) a.size(); ++j) {
            if (per(a[i].first, a[i].second, a[j].first, a[j].second)) {
                ++ans;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    SOLVE
}