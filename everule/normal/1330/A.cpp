//https://codeforces.com/contest/1330/problem/A
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
   int n,x;
   cin>>n>>x;
   bool done[n+ x+ 1]={0};
   for(int i=0;i<n;i++){
       int a;
       cin>>a;
       done[a]=1;
   }
   int j=0;
   int ans=n+x;
   for(int i=1;i<=n+x;i++){
        if(!done[i]){
           j++;
        }
        if(j>x){
           ans=i-1;
           break;
        }
   }
   cout<<ans<<'\n';
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