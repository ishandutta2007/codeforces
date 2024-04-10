#include <iostream>
#include <vector>
#include <set>
#include <assert.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(k);
    vector<int> whe(n);
    for(int i = 0; i < k; ++i) {
        int c;
        cin >> c;
        a[i].resize(c);
        for(int j = 0; j < c; ++j) {
            cin >> a[i][j];
            whe[a[i][j] - 1] = i;
        }
    }

    cout << '?' << ' ' << n << ' ';
    for(int i = 0; i < n; ++i)
        cout << i + 1 << ' ';
    cout << endl;
    int mx;
    cin >> mx;
    int l = 0, r = n;
    while(r - l > 1) {
        int m = (l + r) / 2;
        cout << '?' << ' ' << m << ' ';
        for(int i = 0; i < m; ++i)
            cout << i + 1 << ' ';
        cout << endl;
        int c;
        cin >> c;
        if (c == mx)
            r = m;
        else
            l = m;
    }
    vector<int> ans(k);
    int z = 0;
    for(int i = 0; i < k; ++i) {
        if (whe[l] != i)
            ans[i] = mx;
        else
            z = i;
    }
    set<int> o;
    for(int i = 0; i < n; ++i)
        o.insert(i);
    for(auto i: a[z])
        o.erase(i - 1);
    cout << '?' << ' ' << o.size() << ' ';
    for(auto i: o)
        cout << i + 1 << ' ';
    cout << endl;
    cin >> ans[z];
    cout << '!' << ' ';
    for(int i = 0; i < k; ++i)
        cout << ans[i] << ' ';
    cout << endl;
    string s;
    cin >> s;
}

int main() {
    int t;
    cin >> t;
    while(t--)
        solve();
}