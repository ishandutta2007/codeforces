#include <bits/stdc++.h>

#define int long long
#define SOLVE int t; cin >> t; while(t--) solve();

using namespace std;

void setup() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

const int N = 1e6;
const int U = 3e5;

vector<int> u[N];

signed main() {
    setup();
    // SOLVE();

    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        u[c - i + U].push_back(c);
    }
    int ans = 0;
    for(int i = 0; i < N; ++i) {
        int l_ans = 0;
        for(auto j: u[i]) {
            l_ans += j;
        }
        ans = max(ans, l_ans);
    }
    cout << ans;
}