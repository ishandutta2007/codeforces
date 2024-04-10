#include <bits/stdc++.h>

using namespace std;

const int MAXN = 207;
const int C = 26;

void solve() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if (s[0] == s.back()) {
        cout << "-1\n";
    }   
    else {
        cout << s << '\n';
    }   
}   

signed main() {
    #ifdef HOME
        //freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }   

    return 0;
}