#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long int
ll ask(ll n,ll k){
    if(n==0)return k*(k+1)/2;
    ll p=ask(n/k,k),t=n%k;
    return k*(k+1)/2-t+max(0ll,min(k,(t+1)*k-p+1));
}
int main(){
    int T;cin>>T;
    while(T--){
        ll n,k,p,x;
        cin>>n>>k,x=(n-1)/(k*k+1),p=ask(x,k)+(k*k+1)*x;
        if(p==n)cout<<(x+1)*(k+1)<<'\n';
        else n=(n-(n>p)-1)%(k*k+1),cout<<x*k*(k+1)+n/k*(k+1)+n%k+1<<'\n';
    }
    return 0;
}