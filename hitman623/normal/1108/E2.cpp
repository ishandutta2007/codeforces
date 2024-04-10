#include <bits/stdc++.h>

#define ll          long long
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
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,l[303],r[303],a[100003];
int c1[100005];
int c2[100005];
pii ans;
vii v1,v2;
int res=-hell,pos=-1;
int ans1[303];
int ans2[303];
void solve(){
    cin>>n>>m;
    rep(i,1,n+1) cin>>a[i],c1[i]=c2[i]=a[i];
    rep(i,1,m+1){
        cin>>l[i]>>r[i];
        v1.pb({r[i],l[i]});
        v2.pb({l[i],r[i]});
    }
    sort(all(v1));
    sort(all(v2));
    int mn=hell;
    rep(i,1,n+1) mn=min(mn,a[i]);
    rep(i,0,sz(v1)){
        rep(j,v1[i].y,v1[i].x+1){
            c1[j]--;
            mn=min(mn,c1[j]);
        }
        ans1[i]=mn;
    }
    mn=hell;
    rep(i,1,n+1) mn=min(mn,a[i]);
    for(int i=sz(v2)-1;i>=0;i--){
        rep(j,v2[i].x,v2[i].y+1){
            c2[j]--;
            mn=min(mn,c2[j]);
        }
        ans2[i]=mn;
    }
    mn=hell;
    rep(i,1,n+1) mn=min(mn,a[i]);
    rep(i,1,n+1){
        int cur=mn;
        pii t1={i,-hell};
        int L=upper_bound(all(v1),t1)-v1.begin()-1;
        if(L>=0) cur=min(cur,ans1[L]);
        pii t2={i,hell};
        int R=upper_bound(all(v2),t2)-v2.begin();
        if(R<sz(v2)) cur=min(cur,ans2[R]);
        if(res<a[i]-cur){
            res=a[i]-cur;
            pos=i;
        }
    }
    vi w;
    rep(k,1,m+1){
        if(l[k]<=pos and pos<=r[k]) continue;
        w.pb(k);
    }
    cout<<res<<endl;
    cout<<sz(w)<<endl;
    for(auto i:w) cout<<i<<" ";
    cout<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}