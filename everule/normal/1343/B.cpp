//https://codeforces.com/contest/1343/problem/B
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
    int n;
    cin>>n;
    if(n%4!=0){
        cout<<"NO\n";
        return;
    }
    vector<int> odds, evens;
    cout<<"YES\n";
    for(int i=0, x = 0;i<n/4;i++, x+=10){
        odds.pb(x+1), odds.pb(x+5);
        evens.pb(x+2), evens.pb(x+4);
    }
    for(auto &x : evens){
        cout<<x<<" ";
    }
    for(auto &x : odds){
        cout<<x<<" ";
    }
    cout<<'\n';
    return;
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