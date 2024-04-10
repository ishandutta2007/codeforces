#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
ll solve(vi x, const vector<vector<ll>> &binom) {
    int n=0;
    rep(i,0,10) n+=x[i];
    ll pos=1;
    rep(i,0,10) {
        pos*=binom[n][x[i]];
        n-=x[i];
    }
    return pos;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    const int M=21;
    vector<vector<ll>> binom(M);
    binom[0] = vector<ll>{1};
    rep(i,1,M) {
        binom[i] = vector<ll>(i+1);
        rep(j,0,i) binom[i][j]+=binom[i-1][j];
        rep(j,0,i) binom[i][j+1]+=binom[i-1][j];
    }
    vi cnt(10);
    while(n) {
        ++cnt[n%10];
        n/=10;
    }
    vi x(10,1);
    bool done=false;
    ll ans=0;
    while(!done) {
        vi y(10);
        rep(i,0,10) if(cnt[i]) y[i] = x[i];
        ll a=solve(y,binom);
        if(y[0]) {
            --y[0];
            a-=solve(y,binom);
        }
        ans+=a;
        done=true;
        rep(j,0,10) if(cnt[j]) {
            if(x[j]<cnt[j]) {
                ++x[j];
                done=false;
                break;
            }
            else {
                x[j]=1;
            }
        }
    }
    cout<<ans<<"\n";
}