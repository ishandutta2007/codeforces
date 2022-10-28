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
    ll u,v;
    cin>>u>>v;
    if((u-v)%2!=0){
        cout<<"-1"<<"\n";
        return;
    }
    if(u==0 && v==0){
        cout<<"0";
        return;
    }
    if(u==v){
        cout<<"1\n"<<u;
        return;
    }
    if(u>v){
        cout<<"-1"<<'\n';
        return;
    }
    ll x=v-u;
    x>>=1;
    if((x & u) == 0){
        cout<<"2"<<"\n";
        cout<<x+u<<" "<<x;
        return;
    }
    cout<<"3"<<"\n";
    cout<<u<<" "<<x<<" "<<x;
    return;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}