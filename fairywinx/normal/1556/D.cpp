#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();
#define int long long

using namespace std;

long long ask(int i, int j) {
    cout << "or " << i + 1 << ' ' << j + 1 << endl;
    long long res;
    cin >> res;
    cout << "and " << i + 1 << ' ' << j + 1 << endl;
    int a;
    cin >> a;
    res += a;
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 1; i < n; ++i) {
        a[i] = ask(i, 0);
    }
    int A0 = (a[1] + a[2] - ask(1, 2)) / 2;
    for (int i = 1; i < n; ++i)
        a[i] = (a[i] - A0);
    a[0] = A0;
    // for (auto i : a)
    //     cout << i << ' ';
    // cout << '\n';
    sort(all(a));
    cout << "finish " << a[k - 1] << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    // SOLVE
}