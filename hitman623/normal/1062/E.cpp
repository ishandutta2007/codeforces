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
int n,q,t[200005],height[100005],dp[20][100005],entry[100005],tim;
vi a[100005];
void dfs(int node,int par){
    height[node]=height[par]+1;
    dp[0][node]=par;
    entry[node]=++tim;
    for(auto i:a[node]){
        dfs(i,node);
    }
}
void pre(){
    rep(j,1,20){
        rep(i,1,n+1){
            dp[j][i]=dp[j-1][dp[j-1][i]];
        }
    }
}
int lca(int u,int v){
    if(u==0 or v==0) return u+v; 
    if(height[u]>height[v])swap(u,v);
    for(int i=17;i>=0;i--){
        if(height[v]-(1<<i)>=height[u])v=dp[i][v];
    }
    if(u==v)return u;
    for(int i=17;i>=0;i--){
        if(dp[i][u]!=dp[i][v])u=dp[i][u],v=dp[i][v];
    }
    return dp[0][u];
}
void build(){
    for(int i=n-1;i>0;--i) t[i]=lca(t[i<<1],t[i<<1|1]);
}
int query(int l,int r){
    int res=0;
    for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
        if(l&1){
            if(res==0) res=t[l++];
            else res=lca(res,t[l++]);
        }
        if(r&1){
            if(res==0) res=t[--r];
            else res=lca(res,t[--r]);
        }
    }
    return res;
}
int tmx[200005];
void buildmx(){
    for(int i=n-1;i>0;--i){
        if(entry[tmx[i<<1]]>entry[tmx[i<<1|1]]){
            tmx[i]=tmx[i<<1];
        }
        else tmx[i]=tmx[i<<1|1];
    }
}
int querymx(int l,int r){
    int res=0;
    for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
        if(l&1){
            if(entry[tmx[l++]]>entry[res]) res=tmx[l-1];
        }
        if(r&1){
            if(entry[tmx[--r]]>entry[res]) res=tmx[r];
        }
    }
    return res;
}
int tmn[200005];
void buildmn(){
    for(int i=n-1;i>0;--i){
        if(entry[tmn[i<<1]]<entry[tmn[i<<1|1]]){
            tmn[i]=tmn[i<<1];
        }
        else tmn[i]=tmn[i<<1|1];
    }
}
int querymn(int l,int r){
    int res=n+1;
    for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
        if(l&1){
            if(entry[tmn[l++]]<entry[res]) res=tmn[l-1];
        }
        if(r&1){
            if(entry[tmn[--r]]<entry[res]) res=tmn[r];
        }
    }
    return res;
}
void solve(){
    cin>>n>>q;
    rep(i,2,n+1){
        int x;
        cin>>x;
        a[x].pb(i);
    }
    dfs(1,1);
    pre();
    entry[n+1]=hell;
    rep(i,1,n+1) t[i+n]=tmx[i+n]=tmn[i+n]=i;
    build();
    buildmx();
    buildmn();
    while(q--){
        int l,r;
        cin>>l>>r;
        int MAX=querymx(l,r),MIN=querymn(l,r);
        int mxcand=lca(query(l,MAX-1),query(MAX+1,r));
        int mncand=lca(query(l,MIN-1),query(MIN+1,r));
        if(height[mxcand]<height[mncand]){
            cout<<MIN<<" "<<height[mncand]-1<<endl;
        }
        else{
            cout<<MAX<<" "<<height[mxcand]-1<<endl;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}