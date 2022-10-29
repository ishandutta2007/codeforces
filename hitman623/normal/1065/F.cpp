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
int n,k,dp[20][1000006],height[1000006],entry[1000006],ext[1000006],tim;
vi a[1000006];
void dfs(int node,int par){
    height[node]=height[par]+1;
    dp[0][node]=par;
    entry[node]=++tim;
    for(auto i:a[node]){
        dfs(i,node);
    }
    ext[node]=tim;
}
void pre(){
    rep(i,1,20){
        rep(j,1,n+1){
            dp[i][j]=dp[i-1][dp[i-1][j]];
        }
    }
}
int find_kth_parent(int u,int l){
    if(height[u]<=l+1) return 1;
    for(int i=19;i>=0;i--){
        if((l>>i)&1) u=dp[i][u];
    }
    return u;
}
const int N=1000005;
int t[2*N],up[N];
void modify(int p,int val){
    for(t[p+=n]=val;p>1;p>>=1) t[p>>1]=min(t[p],t[p^1]);
}
int query(int l,int r){
    int res=hell;
    for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
        if(l&1) res=min(res,t[l++]);
        if(r&1) res=min(res,t[--r]);
    }
    return res;
}
int t2[2*N];
void modify2(int p,int val){
    for(t2[p+=n]=val;p>1;p>>=1) t2[p>>1]=max(t2[p],t2[p^1]);
}
int query2(int l,int r){
    int res=0;
    for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
        if(l&1) res=max(res,t2[l++]);
        if(r&1) res=max(res,t2[--r]);
    }
    return res;
}
void solve(){
    cin>>n>>k;
    rep(i,2,n+1){
        int x;
        cin>>x;
        a[x].pb(i);
    }
    dfs(1,1);
    pre();
    vii leaf;
    rep(i,1,n+1){
        if(sz(a[i])==0){
            leaf.pb({height[i],i});
        }
    }
    memset(t,1,sizeof t);
    sort(all(leaf));
    vii sorted_leafs;
    for(auto i:leaf){
        int d=find_kth_parent(i.y,k);
        up[i.y]=min(query(entry[d],ext[d]),height[d]);
        modify(entry[i.y],up[i.y]);
        sorted_leafs.pb({up[i.y],i.y});
    }
    sort(all(sorted_leafs));
    reverse(all(sorted_leafs));
    int ans=0;
    for(auto i:sorted_leafs){
        int d=find_kth_parent(i.y,height[i.y]-i.x);
        int h=query2(entry[d],ext[d])+1;
        modify2(entry[i.y],h);
        ans=max(ans,h);
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}