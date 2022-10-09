#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>
#include <array>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> ans(n);
    int pos = -1;
    for (int i = 0; i < n - 1; i += 2) {
        cout << "? " << 2 << ' ' << i + 1 << ' ' << i + 2 << ' ' << 1 << endl;
        int c;
        cin >> c;
        if (c == 1) {
            ans[i] = 1, pos = i;
            break;
        } else if (c == 2) {
            cout << "? " << 2 << ' ' << i + 2 << ' ' << i + 1 << ' ' << 1 << endl;
            int c;
            cin >> c;
            if (c == 1) {
                ans[i + 1] = 1, pos = i + 1;
                break;
            }
        }
        if (i + 2 == n - 1)
            --i;
    }
    for (int i = 0; i < n; ++i) {
        if (i == pos)
            continue;
        cout << "? " << 1 << ' ' << pos + 1 << ' ' << i + 1 << ' ' << n - 1 << endl;
        int c;
        cin >> c;
        ans[i] = c;
    }
    cout << "! ";
    for (int i : ans)
        cout << i << ' ';
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
    // cout << 1 << '\n';
}