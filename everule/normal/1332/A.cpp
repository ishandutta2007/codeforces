//https://codeforces.com/contest/1332/problem/A
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
   ll a,b,c,d;
   cin>>a>>b>>c>>d;
   ll x,y,x1,x2,y1,y2;
   cin>>x>>y>>x1>>y1>>x2>>y2;
   if((x1==x2 && (a!=0 || b!=0)) || (y1==y2 && (c!=0 || d!=0))){
        cout<<"No\n";
   }
   else if(x+b-a<=x2 && x+b-a>=x1 && y+d-c<=y2 && y+d-c>=y1){
        cout<<"Yes\n";
   }
   else{
        cout<<"No\n";
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