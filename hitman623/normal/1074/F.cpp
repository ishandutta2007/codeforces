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
#define SQRT        650
#define BLOCKS      200000/SQRT
#define hell        1000000007
#define M           200001
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,q,ent[200005],ext[200005],tim,height[200005],dp[20][200005];
vi a[200005];
void dfs(int node,int par){
    height[node]=height[par]+1;
    ent[node]=++tim;
    dp[0][node]=par;
    for(auto i:a[node]){
        if(i!=par){
            dfs(i,node);
        }
    }
    ext[node]=tim;
}
void pre(){
    rep(j,1,20){
        rep(i,1,n+1){
            dp[j][i]=dp[j-1][dp[j-1][i]];
        }
    }
}
int lca(int u,int v){
    if(height[u]>height[v])swap(u,v);
    for(int i=19;i>=0;i--){
        if(height[v]-(1<<i)>=height[u])v=dp[i][v];
    }
    if(u==v)return u;
    for(int i=19;i>=0;i--){
        if(dp[i][u]!=dp[i][v])u=dp[i][u],v=dp[i][v];
    }
    return dp[0][u];
}
int just_par(int u,int v){
    for(int j=19;j>=0;j--){
        if(height[dp[j][v]]>height[u]) v=dp[j][v];
    }
    return v;
}

int freq[BLOCKS][400005];
int val[200005];
int lazy[BLOCKS];

void update(int l,int r,int x){
    int bl=l/SQRT,br=r/SQRT;
    if(bl==br){
        rep(i,l,r+1){
            freq[bl][M+val[i]]--;
            val[i]+=x;
            freq[bl][M+val[i]]++;
        }
    }
    else{
        rep(i,l,(bl+1)*SQRT){
            freq[bl][M+val[i]]--;
            val[i]+=x;
            freq[bl][M+val[i]]++;            
        }
        rep(i,br*SQRT,r+1){
            freq[br][M+val[i]]--;
            val[i]+=x;
            freq[br][M+val[i]]++;            
        }
        rep(i,bl+1,br) lazy[i]+=x;
    }
}

int query(){
    int ans=0;
    rep(i,0,n/SQRT+1){
        ans+=freq[i][M-lazy[i]];
    }
    return ans;
}

mii mp;

void solve(){
    cin>>n>>q;
    rep(i,0,n-1){
        int u,v;
        cin>>u>>v;
        a[u].pb(v);
        a[v].pb(u);
    }
    dfs(1,1);
    pre();
    rep(i,0,n/SQRT) freq[i][M]=SQRT;
    freq[n/SQRT][M]=n%SQRT;
    while(q--){
        int l,r;
        cin>>l>>r;
        if(height[l]>height[r]) swap(l,r);
        if(height[l]==height[r] and l>r) swap(l,r); 
        if(mp[{l,r}]==0){
            if(lca(l,r)!=l){
                update(1,n,1);
                update(ent[l],ext[l],-1);
                update(ent[r],ext[r],-1);
            }
            else{
                int g=just_par(l,r);
                update(ent[g],ext[g],1);
                update(ent[r],ext[r],-1);
            }
            mp[{l,r}]=1;
        }
        else{
            if(lca(l,r)!=l){
                update(1,n,-1);
                update(ent[l],ext[l],1);
                update(ent[r],ext[r],1);
            }
            else{
                int g=just_par(l,r);
                update(ent[g],ext[g],-1);
                update(ent[r],ext[r],1);
            }
            mp[{l,r}]=0;            
        }
        cout<<query()<<endl;
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