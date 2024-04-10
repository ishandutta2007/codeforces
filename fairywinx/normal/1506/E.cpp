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
    vector<int> st(n, -1);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (st[a - 1] == -1)
            st[a - 1] = i;
    }
    vector<int> ans(n);
    vector<int> used(n);
    for (int i = n - 1; i >= 0; --i) {
        if (st[i] != -1)
            ans[st[i]] = i + 1, used[i] = 1;
    }
    {
        vector<int> ans1 = ans;
        int l = 0;
        for (int i = 0; i < n; ++i) {
            if (ans1[i] == 0) {
                while (used[l])
                    ++l;
                ans1[i] = ++l;
            }
        }
        for (int i : ans1)
            cout << i << ' ';
        cout << '\n';
    }
    {
        vector<int> ans1 = ans;
        set<int> can;
        for (int i = 0; i < n; ++i) {
            if (!used[i])
                can.insert(i + 1);
        }
        int mx = 0;
        for (int i = 0; i < n; ++i) {
            mx = max(mx, ans1[i]);
            if (!ans1[i]) {
                int c = *(--can.upper_bound(mx));
                can.erase(c);
                ans1[i] = c;
            }
        }
        for (int i : ans1)
            cout << i << ' ';
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    SOLVE
}