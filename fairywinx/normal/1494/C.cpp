#include <algorithm>
#include <iostream>
#include <vector>

#define all(a) a.begin(), a.end()

using namespace std;

int solve(vector<int> a, vector<int> pos, int res) {
    if (!a.size())
        return 0;
    int it = upper_bound(all(pos), a[0]) - pos.begin();
    int r = 1;
    int ans = res;
    if (*lower_bound(all(pos), a[0]) == a[0])
        --res;
    // cout << "<Meow\n";
    // for (int i : pos)
    //     cout << i << ' ';
    // cout << '\n';
    // for (int i : a)
    //     cout << i << ' ';
    // cout << '\n';
    while (it + 1 < (int) pos.size()) {
        while (r < (int) a.size() && pos[it] + r >= a[r]) {
            if (*lower_bound(all(pos), a[r]) == a[r])
                --res;
            ++r;
        }
        int z = lower_bound(all(pos), pos[it] + min(r, (int) a.size())) - pos.begin();
        // cout << it << ' ' << r << ' ' << z << ' ' << res << '\n';
        ans = max(ans, res + (z) - it);
        ++it;
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> pos(m + 1, -2e9 - 228);
    vector<int> a(n);
    int s = n;
    int res1 = 0, res2 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > 0 && s == n)
            s = i;
    }
    for (int j = 1; j <= m; ++j)
        cin >> pos[j];
    pos.push_back(2e9 + 228);
    for (int i = 0; i < n; ++i) {
        if (a[i] < 0 && *lower_bound(all(pos), a[i]) == a[i])
            ++res2;
        else if (a[i] > 0 && *lower_bound(all(pos), a[i]) == a[i])
            ++res1;
    }

    vector<int> a1;
    for (int i = s; i < n; ++i)
        a1.push_back(a[i]);
    int ans1 = solve(a1, pos, res1);
    // cout << "! " << ans1 << '\n';
    a1.clear();
    for (int i = s - 1; i >= 0; --i)
        a1.push_back(a[i]);
    for (int &i : a1)
        i = -i;
    for (int &i : pos)
        i = -i;
    reverse(all(pos));
    int ans2 = solve(a1, pos, res2);
    cout << ans1 + ans2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}