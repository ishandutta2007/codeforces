//https://codeforces.com/contest/1341/problem/B
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
    int n,k;
    cin>>n>>k;
    vector<int> seq(n);
    for(auto &x : seq){
        cin>>x;
    }
    vector<int> prefixsum(n+1);
    prefixsum[0]=0;
    for(int i=0;i<n;i++){
        prefixsum[i+1]=prefixsum[i];
        if(i>0 && i<n-1){
            if(seq[i]>seq[i-1] && seq[i]>seq[i+1]){
                prefixsum[i+1]++;
            }
        }
    }
    int ans=0;
    int L;
    for(int l=0;l+k-1<n;l++){
        if(prefixsum[l+k-1]-prefixsum[l+1] + 1>ans){
            ans=prefixsum[l+k-1]-prefixsum[l+1]+1;
            L=l+1;
        }
    }
    cout<<ans<<" "<<L<<'\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >>t;
    //precompute();
    while(t--){
        //init();
        solve();
    }
}