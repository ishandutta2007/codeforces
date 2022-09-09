#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = -1;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, q;
        string s;
        cin >> n >> q >> s;
        for(int i = 0; i < q; i += 1){
            int l, r;
            cin >> l >> r;
            l -= 1;
            r -= 1;
            int ok = 0;
            for(int i = 0; i < l; i += 1) if(s[i] == s[l]) ok = 1;
            for(int i = r + 1; i < n; i += 1) if(s[i] == s[r]) ok = 1;
            cout << (ok ? "YES\n" : "NO\n");
        }
    }
    return 0;
}