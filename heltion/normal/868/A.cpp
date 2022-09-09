#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    int n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i += 1){
        string t;
        cin >> t;
        if(s == t) ans = 3;
        if(t[0] == s[1]) ans |= 1;
        if(t[1] == s[0]) ans |= 2;
    }
    cout << (ans == 3 ? "YES" : "NO");
    return 0;
}