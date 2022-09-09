#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        vector<int> r(n);
        for(int& x : r) cin >> x;
        partial_sum(r.begin(), r.end(), r.begin());
        int m;
        cin >> m;
        vector<int> b(m);
        for(int& x : b) cin >> x;
        partial_sum(b.begin(), b.end(), b.begin());
        int ans = 0;
        for(int x : r) for(int y : b) ans = max(ans, max(0, x) + max(0, y));
        cout << ans << "\n";
    }
    return 0;
}