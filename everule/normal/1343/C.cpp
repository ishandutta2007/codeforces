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
    vector<int> seq(n);
    for(auto &x : seq){
        cin>>x;
    }
    pair<ll, int> pos=mp(0, 0), neg=mp(0, 0);
    for(auto &x : seq){
        if(x<0){
            if(neg.second<=pos.second){
                neg.second=pos.second+1;
                neg.first=pos.first+x;
            }
            else{
                neg.first=max(neg.first, pos.first+x);
            }
        }
        else{
            if(neg.second>=pos.second){
                pos.second=neg.second+1;
                pos.first=neg.first+x;
            }
            else{
                pos.first=max(pos.first, neg.first + x);
            }
        }
    }
    if(neg.second>pos.second){
        cout<<neg.first<<"\n";
    }
    else if(neg.second<pos.second){
        cout<<pos.first<<"\n";
    }
    else{
        cout<<max(pos.first, neg.first)<<'\n';
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