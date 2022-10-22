#include <bits/stdc++.h>

using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;

    int a = 0, b = 0;
    for (char c: s) {
        a += (c == '-');
        b += (c == 'o');
    }
    
    if (b == 0 || a % b == 0) cout << "YES\n";
    else cout << "NO\n";
     
    return 0;
}