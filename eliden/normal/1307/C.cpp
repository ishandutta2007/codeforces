#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define debug(x) cerr<<#x<<": "<<x<<endl
using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin>>s;
    const int M=26;
    vector<ll> a(M);
    vector<vector<ll>> b(M,vector<ll>(M));
    for(char c:s) {
        int x = c-'a';
        rep(i,0,M) b[i][x] += a[i];
        ++a[x];
    }
    ll ans = 0;
    rep(i,0,M) ans=max(ans,a[i]);
    rep(i,0,M) rep(j,0,M) ans=max(ans,b[i][j]);
    cout<<ans<<"\n";
}