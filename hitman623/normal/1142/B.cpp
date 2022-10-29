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
int n,m,q,p[200005],a[200005],dp[20][200005],b[200005],pos[200005],mp[200005];
int get_nth_par(int node){
    int cur=n-1;
    rep(i,0,20){
        if((cur>>i)&1) node=dp[i][node];
    }
    return node;
}
const int N=200005;
int t[2*N];
void build(){
    for(int i=m-1;i>0;--i) t[i]=min(t[i<<1],t[i<<1|1]);
}
int query(int l,int r){
    int res=hell;
    for(l+=m,r+=m+1;l<r;l>>=1,r>>=1){
        if(l&1) res=min(res,t[l++]);
        if(r&1) res=min(res,t[--r]);
    }
    return res;
}
void solve(){
    cin>>n>>m>>q;
    rep(i,0,n){
        cin>>p[i];
        pos[p[i]]=i;
    }
    rep(i,1,m+1) cin>>a[i];
    rep(i,1,n+1) mp[i]=m+1;
    dp[0][m+1]=m+1;
    for(int i=m;i>=1;i--){
        dp[0][i]=mp[p[(pos[a[i]]+1)%n]];
        mp[a[i]]=i;
    }
    rep(i,1,20){
        rep(j,1,m+2){
            dp[i][j]=dp[i-1][dp[i-1][j]];
        }
    }
    rep(i,0,m) t[i+m]=get_nth_par(i+1);
    build();
    while(q--){
        int l,r;
        cin>>l>>r;
        if(query(l-1,r-1)<=r) cout<<1;
        else cout<<0;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}