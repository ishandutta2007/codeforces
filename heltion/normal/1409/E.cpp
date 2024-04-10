#include<bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int n, k;
        cin >> n >> k;
        vector<int> v(n), w(n), nxt(n);
        for(int &x : v) cin >> x;
        for(int &y : w) cin >> y;
        sort(v.begin(), v.end());
        for(int i = 0, j = 0; i < n; i += 1){
            while(j < n and v[j] - v[i] <= k) j += 1;
            nxt[i] = j;
            w[i] = j - i;
        }
        int ans = 0;
        for(int i = n - 1; i >= 0; i -= 1){
            ans = max(w[i] + (nxt[i] == n ? 0 : w[nxt[i]]), ans);
            w[i] = max(w[i], i == n - 1 ? 0 : w[i + 1]);
        }
        cout << ans << "\n";
    }
    return 0;
}