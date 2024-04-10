#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        LL n, k;
        cin >> n >> k;
        vector<LL> a(n);
        for(LL &x : a) cin >> x;
        for(k = min(k % 2 + 2, k); k; k -= 1){
            LL x = *max_element(a.begin(), a.end());
            for(LL& y : a) y = x - y;
        }
        for(LL x : a) cout << x << " ";
        cout << "\n";
    }
    return 0;
}