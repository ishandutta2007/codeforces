#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll f(ll n, ll k) {
    if(n==0) return k*(k+1)/2;
    ll p=f(n/k, k), s=n%k, len=k*k+1, pivot=p%len==0?len:p%len;
    if(s*k<pivot-k) return (n/k)*len*k+k*k*s+k*(k+1)/2;
    else if(s*k<pivot) return (n/k)*len*k+k*k*s+k*(k+1)/2+k+s*k-pivot+1;
    else return (n/k)*len*k+k*k*s+(k+1)*(k+2)/2-1;
}

ll solve(ll n, ll k) {
    ll seg=(n-1)/(k*k+1);
    ll last=f(seg, k);
    if (last<n) return (n-seg-1)+(n-seg-2)/k;
    else if(last==n) return (seg+1)*(k+1);
    else return (n-seg)+(n-seg-1)/k;
}

int32_t main() {
    int q; cin>>q; while(q--) {
        ll n, k; cin>>n>>k; cout<<solve(n, k)<<endl;
    }
}