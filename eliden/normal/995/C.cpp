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
ll sqn(ll x, ll y) {
    return x*x+y*y;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<tuple<ll,ll,ll,int>> es;
    rep(i,0,n) {
        ll x, y;
        cin >> x >> y;
        es.emplace_back(sqn(x,y),x,y,i);
    }
    sort(all(es));
    vi c(n);
    vector<ll> x(n), y(n);
    vi id(n);
    rep(i,0,n) x[i]=get<1>(es[i]);
    rep(i,0,n) y[i]=get<2>(es[i]);
    rep(i,0,n) id[i] = get<3>(es[i]);
    ll ax = x[0], ay=y[0];
    c[id[0]] = 1;
    int i=1;
    if(n%2==0) {
        ++i;
        ll x1 = ax+x[1], y1 = ay+y[1];
        ll x2 = ax-x[1], y2=ay-y[1];
        if(sqn(x2,y2)<sqn(x1,y1)) {
            ax = x2;
            ay = y2;
            c[id[1]] = -1;
        }
        else {
            ax = x1;
            ay = y1;
            c[id[1]] = 1;
        }
    }
    while(i<n) {
        vi co1{1,1,-1,-1}, co2{1,-1,1,-1};
        int best=-1;
        ll bestn=-1, bestx0, besty0;
        rep(j,0,4) {
            ll x0=x[i]*co1[j]+x[i+1]*co2[j];
            ll y0=y[i]*co1[j]+y[i+1]*co2[j];
            ll cand = sqn(ax+x0,ay+y0);
            if(best==-1 || cand<bestn) {
                bestn=cand;
                best=j;
                bestx0=x0;
                besty0=y0;
            }
        }
        ax+=bestx0;
        ay+=besty0;
        c[id[i]]=co1[best];
        c[id[i+1]]=co2[best];
        i+=2;
    }
    rep(i,0,n) cout << c[i] << " ";
    cout << "\n";
}