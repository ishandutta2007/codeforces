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
    int n, k;
    cin >> n >> k;
    const ll M=1e5+1;
    const ll B=M*M;
    vector<ll> caps(M,1);
    rep(j,2,M) {
        rep(l,0,k) {
            caps[j]*=j;
            if(caps[j]>B) {
                caps[j] = -1;
                break;
            }
        }
    }
    vector<int> count(M);
    vector<vector<ll>> factors(M);
    rep(p,2,M) {
        if(!factors[p].empty()) continue;
        // p is prime
        for(int j = p; j<M; j+=p) {
            factors[j].push_back(p);
        }
    }
    ll ans=0;
    rep(i,0,n) {
        ll a;
        cin >> a;
        ll b=1, c=a;
        for(ll p:factors[a]) {
            if(caps[p]==-1) {
                b=-1;
                break;
            }
            while(a%caps[p]==0) {
                a/=caps[p];
                c/=caps[p];
            }
            if(a%p==0) {
                b *= caps[p];
            }
            while(a%p==0) {
                a/=p;
                b/=p;
            }
        }
        if(b==-1) continue;
        // debug(b);
        // debug(c);
        if(b<M) {
            ans+=count[b];
        }
        ++count[c];
    }
    cout<<ans<<endl;
}