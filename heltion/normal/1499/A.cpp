#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, k1, k2, w, b;
        cin >> n >> k1 >> k2 >> w >> b;
        if(w * 2 <= k1 + k2 and b * 2 <= n * 2 - k1 - k2) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}