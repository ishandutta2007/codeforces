#include <bits/stdc++.h>
#define pb          push_back
#define pii         pair<int,int>
#define vii         vector<pii>
#define x           first
#define y           second
#define endl        '\n'
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,a[500005],q,cnt=1,t[1000008],b[500005],r[500005],ans[500005],vis[500005];
vii v[500005];
void update(int p,int val){
    b[p]=val;
    p+=n;
    for(t[p]=p-n;p>1;p>>=1){
        if(b[t[p]]>b[t[p^1]]) t[p>>1]=t[p];
        else t[p>>1]=t[p^1];
    }
}
int query(int l,int r){
    int res=l;
    for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
        if(l&1){
            if(b[res]<b[t[l]]) res=t[l];
            l++;
        }
        if(r&1){
            --r;
            if(b[res]<b[t[r]]) res=t[r];
        }
    }
    return res;
}
void solve(){
    cin>>n;
    rep(i,0,n) cin>>a[i];
    for(int i=n-1;i>=0;i--){
        if(vis[a[i]]) r[i]=vis[a[i]];
        else r[i]=n;
        vis[a[i]]=i;
    }
    rep(i,0,n){
        if(vis[a[i]]==i) update(i,r[i]);
        else update(i,i);
    }
    cin>>q;
    rep(i,0,q){
        int l,r;
        cin>>l>>r;
        v[l-1].pb({r-1,i});
    }
    rep(i,0,n){
        for(auto j:v[i]){
            int d=query(i,j.x);
            if(b[d]>j.x) ans[j.y]=a[d];
        }
        if(r[i]<n) update(r[i],r[r[i]]);
    }
    rep(i,0,q) cout<<ans[i]<<endl;
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