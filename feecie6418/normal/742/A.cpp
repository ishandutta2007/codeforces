#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll unsigned long long
using namespace std;
ll slowmulti(ll a,ll n,ll k) {
    ll ans=0;
    while(n>0) {
        if(n&1)ans=(ans+a)%k;
        n=n>>1;
        a=(a+a)%k;
    }
    return ans;
}
ll quickpower(ll a,ll n,ll k) {
    ll ans=1;
    while(n>0) {
        if(n&1)ans=slowmulti(ans,a,k);
        n=n>>1;
        a=slowmulti(a,a,k);
    }
    return ans;
}
int main() {
    ll n;
    cin>>n;
    cout<<quickpower(1378,n,10);
    return 0;
}