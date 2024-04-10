#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        LL n, k;
        cin >> n >> k;
        vector<LL> h(n);
        for(LL& x : h) cin >> x;
        LL L = 0, R = 0;
        for(int i = 1; i < n; i += 1){
            LL tL = L + h[i - 1] - k + 1, tR = R + k - 1 + h[i - 1]; 
            LL nL = max(tL - h[i], 0LL), nR = min(tR - h[i], k - 1);
            L = nL;
            R = nR;
            if(L > R) break;
        }
        if(L <= R and L == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}