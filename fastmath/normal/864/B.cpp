#include <bits/stdc++.h>

using namespace std;

#define int long long

bool bad(char c) {
    return 'A' <= c && c <= 'Z';
}   

signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    string s;
    cin >> s;

    set <char> ms;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (bad(s[i])) {
            ms.clear();
        }   
        else {
            ms.insert(s[i]);
        }   
        ans = max(ans, (int)ms.size());
    }   

    cout << ans << '\n';

    return 0;
}