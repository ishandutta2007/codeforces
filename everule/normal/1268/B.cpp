#include <iostream>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
void solve(){
    int n;
    cin>>n;
    int even=0, odd=0;
    ll ans = 0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        ans+=x/2;
        if(x&1){
            if(i&1){
                ++odd;
            }
            else{
                ++even;
            }
        }
    }
    ans+=min(odd, even);
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}