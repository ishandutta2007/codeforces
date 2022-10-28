#include <iostream>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
void solve(){
    ll l,r;
    cin>>l>>r;
    ll x = r/2;
    ll y = 2*x;
    if(x<l){
        cout<<"-1 -1\n";
        return;
    }
    cout<<x<<" "<<y<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}