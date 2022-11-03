#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9;
const int M = 1e9 + 7;
const int N = 2e5 + 13;

void solve() {
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    vector<int> a;
    int sum = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] != t[i]) {
            a.push_back(s[i] == '1' ? 1 : -1);
            sum += a.back();
        }
    }

    if(sum != 0) {
        cout << -1;
        return;
    }

    n = a.size();

    int ans = 0;
    int cur = 0;
    int mn = 0;
    for(int i = 0; i < n; i++) {
        cur += a[i];
        mn = min(mn, cur);
        ans = max(ans, cur - mn);
    }

    cur = 0;
    int mx = 0;
    for(int i = 0; i < n; i++) {
        cur += a[i];
        mx = max(mx, cur);
        ans = max(ans, mx - cur);
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}