#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int t, n, m, x, L, R, l, r;
    for(cin >> t; t; t -= 1){
        cin >> n >> x;
        L = R = x;
        for(cin >> m; m; m -= 1){
            cin >> l >> r;
            if(r < L || l > R) continue;
            L = min(L, l);
            R = max(R, r);
        }
        cout << R - L + 1 << "\n";
    }
}