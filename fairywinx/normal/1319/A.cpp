#include <bits/stdc++.h>

#define int long long
#define SOLVE int t; cin >> t; while(t--) solve()

using namespace std;

void setup() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

const int INF = 2e9;
const int K = 22;

void ct(vector<int> &a) {
    for(auto i: a)
        cout << i << ' ';
    cout << '\n';
}

void ct(pair<int, int> &i) {
    cout << i.first << ':' << i.second << ' ';
}

void ct(vector<pair<int, int>> &a) {
    for(auto i: a)
        ct(i);
    cout << '\n';
}

void ct_ans(vector<pair<int, int>> &a) {
    for(auto i: a)
        cout << i.first << ' ' << i.second << '\n';
}

void solve() {

}

signed main() {
    setup();
    // SOLVE;
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for(auto &i: a)
        cin >> i;
    for(auto &i: b)
        cin >> i;

    int ans = 0, u = 0;
    for(int i = 0; i < n; ++i) {
        if (!b[i] && a[i])
            ++ans;
        if (b[i] && !a[i])
            ++u;
    }
    if (ans == 0) {
        cout << - 1;
        return 0;
    }

    cout << (u) / ans + 1;
}