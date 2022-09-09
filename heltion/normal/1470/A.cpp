#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, m;
        cin >> n >> m;
        vector<int> k(n);
        for(int& x : k) cin >> x;
        vector<LL> c(m);
        for(LL& x : c) cin >> x;
        sort(k.begin(), k.end());
        sort(c.begin(), c.end());
        LL ans = 0;
        for(int i = n - 1, j = 0; i >= 0; i -= 1){
            if(j >= k[i]) ans += c[k[i] - 1];
            else ans += c[j ++];
        }
        cout << ans << "\n";
    }
    return 0;
}