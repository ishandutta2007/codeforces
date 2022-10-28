#include <iostream>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> count(26);
    for(const auto &c : s){
        ++count[c - 'a'];
    }
    sort(count.begin(), count.end(), greater<int>());
    vector<int> canget(k);
    for(int i=0;i<k;i++){
        int mn = 0, mx = n;
        while(mn< mx){
            int mid = mn + mx + 1;
            mid>>=1;
            int ans =0;
            for(int j=0;j<26;j++){
                ans+=count[j]/mid;
            }
            if(ans>i){
                mn = mid; 
            }
            else{
                mx = mid-1;
            }
        }
        canget[i]=mn;
    }
    int ans = -1;
    for(int l=1;l<=n*k;l++){
        int colors = __gcd(l,k);
        int needed = l/colors;
        if(needed <= canget[colors-1]){
            ans = l;
        } 
    }
    cout<<ans<<"\n";
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