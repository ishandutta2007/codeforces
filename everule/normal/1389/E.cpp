#include <iostream>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
void solve(){
    ll m,d,w;
    cin>>m>>d>>w;
    w/=__gcd(w,d-1);
    ll x = min(m,d);
    ll count = x/w;
    ll excess = x%w;
    ll ans = count*(count-1)/2 * (w - excess) + count*(count+1)/2 * excess;
    cout<<ans<<"\n";
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