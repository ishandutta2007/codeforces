#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,m,k,a[300005];
ll rui[300005];
deque<P>deq[10];
signed main(){
    cin >> n >> m >> k;
    rep(i,n) cin>>a[i];
   
    rep(i,n){
        rui[i] = a[i];
        if(i > 0) rui[i] += rui[i-1];
        ll R = rui[i] - (i/m+1)*k;
        while(deq[i%m].size() && deq[i%m][deq[i%m].size()-1].fi <= R) deq[i%m].pop_back();
        deq[i%m].pb(mp(R,i));
    }
    ll ans = 0;
    rep(i,n){
        rep(j,m){
            if(deq[j].empty()) continue;
            ll x = deq[j][0].sc; //cout << i << " " << x << endl;
            if(x < i) continue;// cout << i << " " << x << endl;
            int cnt = (x-i+1);
            ll sum = rui[x]; if(i) sum -= rui[i-1]; //cout << i << " " << x << endl;
            ans = max(ans,sum-1LL*k*((cnt+m-1)/m));
        }
        if(deq[i%m].size() && deq[i%m][0].sc == i) deq[i%m].pop_front();
    }
    cout << ans << endl;
}