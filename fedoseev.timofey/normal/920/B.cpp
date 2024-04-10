#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>

using namespace std;

struct triple {
    int a, b, c;
};

void solve() {
    int n;
    cin >> n;
    vector <triple> s(n);
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        s[i] = {l, r, i};
    }
    int time = 0;
    vector <int> ans(n);
    for (int i = 0; i < n; ++i) {
        time = max(time, s[i].a);
        if (time > s[i].b) ans[s[i].c] = 0;
        else {
            ans[s[i].c] = time;
            ++time;
        }
    }
    for (auto e : ans) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}