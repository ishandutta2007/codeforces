#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll d(ll n) {
    for(ll i=2; i<=sqrt(n); i++) {
        if(n%i==0) return n/i;
    }
    return 1;
}

int main(){
    int q; cin>>q; for(int l=1; l<=q; l++) {
        ll n; cin>>n; int x=0; ll tmp=n; while(tmp>0) { tmp/=2; x++; }
        ll p = 1LL<<x; if(n!=p-1) cout<<p-1; else cout<<d(n); cout<<endl;
    }
}