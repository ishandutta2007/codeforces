#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        sum += b[i];
    }
    long long val = n * (n + 1) / 2;
    if (sum % val != 0) {
        cout << "NO\n";
        return;
    }
    vector<int> ans;
    sum = sum / val;
    for (int i = 0; i < n; ++i) {
        long long tmp = b[(i - 1 + n) % n] - b[i] + sum;
        if (tmp > 0 && tmp % n == 0) {
            ans.push_back(tmp / n);
        } else {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';
}

signed main() {
    #ifdef DEBUG
        freopen("main/in.txt", "r", stdin);
    #endif
    #ifndef LOCAL
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif

    SOLVE;
}