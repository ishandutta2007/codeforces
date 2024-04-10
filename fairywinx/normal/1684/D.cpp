#include <bits/stdc++.h>
 
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();
 
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<pair<int, int>> b;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b.emplace_back(a[i] + i, i);
    }
    sort(rall(b));
    b.resize(k);
    vector<int> good(n);
    for (auto i : b) {
        good[i.second] = 1;
    }
    long long ans = 0;
    int add = 0;
    for (int i = 0; i < n; ++i) {
        if (good[i]) {
            ++add;
        } else {
            ans += a[i] + add;
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