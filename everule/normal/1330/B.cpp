//https://codeforces.com/contest/1330/problem/B
#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
ll solve(){
    int n;
    cin>>n;
    int mx=-1;
    int seq[n];
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>seq[i];
        arr[n-i-1]=seq[i];
        mx=max(mx,seq[i]);
    }
    sort(seq,seq+mx);
    sort(seq+mx,seq+n);
    sort(arr,arr+mx);
    sort(arr+mx,arr+n);
    bool ans1=1,ans2=1;
    int ans=0;
    for(int i=0;i<mx;i++){
        ans1&=(seq[i]==i+1);
    }
    for(int i=mx;i<n;i++){
        ans1&=(seq[i]==i+1-mx);
    }
    for(int i=0;i<mx;i++){
        ans2&=(arr[i]==i+1);
    }
    for(int i=mx;i<n;i++){
        ans2&=(arr[i]==i+1-mx);
    }
    if(ans1){
        ans++;
    }
    if(ans2){
        ans++;
    }
    if(mx==n-mx && ans==2){
        --ans;
    }
    cout<<ans<<"\n";
    if(mx!=n-mx){
        if(ans1){
            cout<<mx<<" "<<n-mx<<'\n';
        }
        if(ans2){
            cout<<n-mx<<" "<<mx<<'\n';
        }
    }
    else{
        if(ans1 || ans2){
            cout<<mx<<" "<<n-mx<<'\n';
        }
    }
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