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
   int n,m;
   cin>>n>>m;
   if((n&1) && (m&1)){
       int x=1;
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(x&1){
                   cout<<"B";
               }
               else{
                   cout<<"W";
               }
               ++x;
           }
           cout<<'\n';
       }
       return;
   }
    int x=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 && j==1){
                cout<<"B";
                ++x;
               continue;
           }
           if(x&1){
               cout<<"W";
           }
           else{
               cout<<"B";
           }
           ++x;
       }
       cout<<'\n';
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