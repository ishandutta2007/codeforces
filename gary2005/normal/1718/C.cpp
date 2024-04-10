/**
 *    author:  gary
 *    created: 20.08.2022 13:33:30
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=2e5+20;
int n,q,a[MAXN];
void solve(){
    cin>>n>>q;
    rb(i,1,n) cin>>a[i];
    vector<int> pr;
    int x=n;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            pr.push_back(i);
            while(x%i==0) x/=i;
        }
    }
    if(x>=2) pr.push_back(x);
    for(auto &it:pr) it=n/it;
    vector<vector<LL> > sum(pr.size());
    vector<multiset<LL> > st(pr.size());
    rep(i,pr.size()) sum[i].resize(pr[i]);
    rb(i,1,n){
        rep(j,pr.size()) sum[j][i%pr[j]]+=a[i];
    }
    rep(j,pr.size()) rep(k,pr[j]) st[j].insert(sum[j][k]);
    LL ans;
    ans=-1e18;
    rep(j,pr.size()) check_max(ans,1ll*(*st[j].rbegin())*pr[j]);
    cout<<ans<<'\n';
    while(q--){
        int p,x;
        cin>>p>>x;
        rep(j,pr.size()) st[j].erase(st[j].find(sum[j][p%pr[j]])),sum[j][p%pr[j]]-=a[p];
        a[p]=x;
        rep(j,pr.size()) sum[j][p%pr[j]]+=a[p],st[j].insert(sum[j][p%pr[j]]);
        ans=-1e18;
        rep(j,pr.size()) check_max(ans,1ll*(*st[j].rbegin())*pr[j]);
        cout<<ans<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}