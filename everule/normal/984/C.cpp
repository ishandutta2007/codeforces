#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
void solve(){
    ll p,q,b;
    cin>>p>>q>>b;
    if(p==0 || q==1){
        cout<<"Finite\n";
        return;
    }
    q/=__gcd(p,q);
    while(__gcd(b,q)!=1){
        ll x =__gcd(b,q); 
        while(q%x == 0){
            q/=x;
        }
    }
    if(q==1){
        cout<<"Finite\n";
    }
    else{
        cout<<"Infinite\n";
    }
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