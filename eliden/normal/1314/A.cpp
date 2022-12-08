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
    int n;
    cin>>n;
    vector<pair<ll,ll>> ps;
    vector<ll> aa(n), tt(n);
    rep(i,0,n) cin>>aa[i];
    rep(i,0,n) cin>>tt[i];
    rep(i,0,n) {
        ps.emplace_back(aa[i],tt[i]);
    }
    sort(all(ps));
    ll ans = 0;
    ll x=-1;
    priority_queue<ll> costs;
    ll costsum = 0;
    rep(i,0,n) {
        ll a, t;
        tie(a,t) = ps[i];
        while(!costs.empty() && x<a) {
            costsum -= costs.top();
            costs.pop();
            ans += costsum;
            ++x;
        }
        x = a;
        costs.push(t);
        costsum += t;
    }
    while(!costs.empty()) {
        costsum -= costs.top();
        costs.pop();
        ans += costsum;
    }
    cout<<ans<<endl;
}