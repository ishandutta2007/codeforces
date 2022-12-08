#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define trav(a,x) for(auto &a:x)
using ll = long long;
using vi = vector<int>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin>>n>>m;
    vector<int> l(m);
    rep(i,0,m) cin>>l[i];
    ll sum=0;
    int d = INT_MAX;
    rep(i,0,m) {
        d=min(d,n-l[i]-i);
        sum+=l[i];
    }
    if(sum<n || d<0) cout<<"-1\n";
    else {
        ll p = 1;
        rep(i,0,m) {
            cout<<p<<" ";
            ++p;
            ll x = min(d,l[i]-1);
            d -= x;
            p += x;
        }
        cout<<"\n";
    }
}