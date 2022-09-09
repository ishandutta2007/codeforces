#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        string s;
        cin >> s;
        int L = 0, R = s.size() - 1;
        while(L < (int)s.size() and (s[L] == '0' or (L == 0 or s[L - 1] == '0'))) L += 1;
        while(R >= 0 and (s[R] == '1' or (R == (int)s.size() - 1 or s[R + 1] == '1'))) R -= 1;
        if(L >= R) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}