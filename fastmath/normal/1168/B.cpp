#include<bits/stdc++.h>
using namespace std;
#define int long long

bool check(string s) {
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        for (int k = 1; i + 2 * k < n; ++k) {
            if (s[i] == s[i + k] && s[i] == s[i + 2 * k]) return 0;
        }   
    }   
    return 1;
}   

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    
    string s;
    cin >> s;
    int n = s.size();
    int ans = n * (n + 1) / 2;
    for (int len = 1; len <= 8; ++len) {
        for (int i = 0; i + len - 1 < n; ++i) {
            if (check(s.substr(i, len))) --ans;
        }   
    }   
    cout << ans << '\n';

}