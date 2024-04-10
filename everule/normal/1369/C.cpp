#include <iostream>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> seq(n);
    vector<int> weight(k);
    for(auto &x : seq){
        cin>>x;
    }
    for(auto &x : weight){
        cin>>x;
    }
    sort(seq.begin(), seq.end());
    sort(weight.begin(), weight.end());
    ll ans = 0;
    for(int i=0;i<k;i++){
        ans+=seq.back();
        --weight[i];
        if(weight[i]==0){
            ans+=seq.back();
        }
        seq.pop_back();
    }
    reverse(weight.begin(), weight.end());
    while(weight.back()==0){
        weight.pop_back();
        --k;
    }
    int idx = 0;
    for(int i=0;i<k;i++){
        ans+=seq[idx];
        idx+=weight[i];
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