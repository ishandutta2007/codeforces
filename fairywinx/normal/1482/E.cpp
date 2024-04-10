#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <array>
#include <map>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while (t--) solve();

using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    int mx = 0;
    for (auto i : cnt) {
        mx = max(mx, i.second);
    }
    if (n % 2 == 0)
        cout << max(0, mx - (n - mx)) << '\n';
    else
        cout << max(1, mx - (n - mx)) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    SOLVE
}