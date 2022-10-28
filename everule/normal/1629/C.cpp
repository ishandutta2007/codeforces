#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &x : a) cin>>x;
    vector<int> suffixMEX(n+1, 0);
    [&](){
        int currMEX = 0;
        vector<int> cnt(n + 1);
        for(int i=n-1;i>=0;--i){
            if(a[i] <= n) cnt[a[i]]++;
            while(cnt[currMEX] > 0) currMEX++;
            suffixMEX[i] = currMEX;
        }
    }();
    auto findR = [&](int l, int MEX){
        vector<int> cnt(MEX + 1);
        int currMEX = 0;
        for(int i=l;i<n;i++){
            if(a[i] <= MEX) cnt[a[i]]++;
            while(cnt[currMEX] > 0) currMEX++;
            if(currMEX == MEX) return i;
        }
    };
    vector<int> ans;
    int l = 0;
    while(l < n){
        int r = findR(l, suffixMEX[l]);
        ans.push_back(suffixMEX[l]);
        l = r + 1;
    }
    cout<<ans.size()<<"\n";
    for(auto &x : ans) cout<<x<<" ";
    cout<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}