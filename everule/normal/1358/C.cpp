//https://codeforces.com/contest/1358/problem/C
#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define mp make_pair
#define int long long
#define pb push_back
#define vi vector<int>
using namespace std;
void solve(){
    int x1, x2, y1, y2;
    cin>>x1>>y1>>x2>>y2;
    int dx = x2 - x1;
    int dy = y2 - y1;
    if(dx==dy){
        cout<<dx*dx + 1<<"\n";
    }
    else{
        int ans=min(dx,dy)*std::abs(dy-dx);
        ans+=min(dx,dy)*min(dx,dy);
        cout<<ans+1<<"\n";
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}