//https://codeforces.com/problemset/problem/1316/C
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
   int n,m,p,a,x,y;
   cin>>n>>m>>p;
   for(int i=0;i<n;i++){
       cin>>a;
       if(a%p){
           x=i;
           cin.ignore( numeric_limits<streamsize>::max(),'\n');
           break;
       }
   }
   for(int i=0;i<m;i++){
       cin>>a;
       if(a%p){
           y=i;
           cin.ignore( numeric_limits<streamsize>::max(),'\n');
           break;
       }
   }
   cout<<x+y;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}