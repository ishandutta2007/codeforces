#include<bits/stdc++.h>
using namespace std;
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int n;
    cin >> n;
    string s;
    cin >> s;

    int t = (n - 11) >> 1;
    int cnt = 0;
    for (char c : s) cnt += c == '8';
    if (cnt <= t) {
        cout << "NO\n";
        exit(0);
    }   
    
    int p = -1;
    int c = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '8') {
            if (c < t) ++c;
            else {
                p = i;
                break;
            }   
        }   
    }   
    
    if (p - t <= t) cout << "YES\n";
    else cout << "NO\n";

}