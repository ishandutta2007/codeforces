#include<bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (s[0] == '<' && s[n -1 ] == '>') {
        int l = 0;
        while (s[l] == '<') ++l;
        int r = 0;
        while (s[n - 1 - r] == '>') ++r;
        cout << min(l, r) << '\n';
    }
    else {
        cout << "0\n";
    }   
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);            
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) solve();

}