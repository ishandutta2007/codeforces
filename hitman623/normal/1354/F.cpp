#include <bits/stdc++.h>

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000000000000007LL
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,k,dp[88][88],a[88],b[88];
vi add,rem,idxs;
int go(int pos,int taken){
    if(pos==n){
        if(taken==k) return 0;
        else return -hell;
    }
    int &ans=dp[pos][taken];
    if(ans!=-1) return ans;
    ans=-hell;
    if(taken+1<=k) ans=max(ans,a[idxs[pos]]+b[idxs[pos]]*taken+go(pos+1,taken+1));
    ans=max(ans,b[idxs[pos]]*(k-1)+go(pos+1,taken));
    return ans;
}
void trace(int pos,int taken){
    if(pos==n) return;
    int val=go(pos,taken);
    if(taken+1<=k and val==a[idxs[pos]]+b[idxs[pos]]*taken+go(pos+1,taken+1)){
        add.pb(idxs[pos]+1);
        trace(pos+1,taken+1);
        return;
    }
    if(val==b[idxs[pos]]*(k-1)+go(pos+1,taken)){
        rem.pb(idxs[pos]+1);
        trace(pos+1,taken);
        return;
    }
}
void solve(){
    memset(dp,-1,sizeof dp);
    idxs.clear();
    add.clear();
    rem.clear();
    cin>>n>>k;
    rep(i,0,n) cin>>a[i]>>b[i];
    rep(i,0,n) idxs.pb(i);
    sort(all(idxs),[](int l,int r){
        return b[l]<b[r];
    });
    trace(0,0);
    cout<<sz(add)+2*sz(rem)<<endl;
    rep(i,0,sz(add)-1) cout<<add[i]<<" ";
    rep(i,0,sz(rem)) cout<<rem[i]<<" "<<-rem[i]<<" ";
    cout<<add.back()<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}