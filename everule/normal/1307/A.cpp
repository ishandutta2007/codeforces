#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
void solve(){
    int n,d;
    cin>>n>>d;
    vector<int> seq(n);
    for(auto &x : seq){
        cin>>x;
    }
    int ans=seq[0];
    for(int i=1;i<n;i++){
        if(seq[i]>=d/i){
            ans+=d/i;
            break;
        }
        else{
            ans+=seq[i];
            d-=seq[i]*i;
        }
    }
    cout<<ans<<'\n';
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