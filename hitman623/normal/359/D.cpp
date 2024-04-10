#include <bits/stdc++.h>

#define ll          long long
#define pb          emplace_back
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
int n,a[300005],f[1000006],vis[1000006],r[1000006];
int t[600005];
void build(){
    for(int i=n-1;i>0;--i) t[i]=__gcd(t[i<<1],t[i<<1|1]);
}
int query(int l,int r){
    int res=0;
    for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
        if(l&1) res=__gcd(t[l++],res);
        if(r&1) res=__gcd(t[--r],res);
    }
    return res;
}
vi ans;
int ml=-1;
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>a[i];
        t[i+n]=a[i];
    }
    memset(vis,127,sizeof vis);
    for(int i=n-1;i>=0;--i){
        r[i]=vis[a[i]];
        vis[a[i]]=i;
    }
    build();
    rep(i,0,n){
        int lo=i,hi=n-1;
        while(hi-lo>1){
            int mid=(lo+hi)/2;
            int d=query(i,mid);
            if(vis[d]<n and query(i,vis[d])==d){
                lo=mid;
            }
            else{
                hi=mid;
            }
        }
        int w;
        if(vis[query(i,hi)]<=hi){
            w=hi;
        }
        else w=lo;
        if(w-i>ml){
            ml=w-i;
            ans={i+1};
        }
        else if(w-i==ml){
            ans.pb(i+1);
        }
        vis[a[i]]=r[i];
    }
    cout<<sz(ans)<<" "<<ml<<endl;
    for(auto i:ans){
        cout<<i<<" ";
    }
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