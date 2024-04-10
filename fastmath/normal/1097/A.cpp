#include <bits/stdc++.h>
using namespace std;
signed main() {
    #ifdef HOME
        //freopen("input.txt", "r", stdin);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
    #endif
    
    string s;
    cin >> s;

    for (int i = 0; i < 5; ++i) {
        string t;
        cin >> t;
        if (s[0] == t[0] || s[1] == t[1]) {
            cout << "Yes\n";
            exit(0);
        }   
    }   

    cout << "No\n";
}