#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define sz(x) (int)(x).size()
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(), x.end()
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<ll> b(n);
    rep(i,0,n) cin>>b[i];
    vector<ll> a(n);
    ll x=0;
    rep(i,0,n) {
        a[i] = b[i]+x;
        x=max(x,a[i]);
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    
}