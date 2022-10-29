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

int n,ans[100005],p[100005];
vi a[100005],postorder;
int val[100005][2];
void dfs(int node,int par){
    p[node]=par;
    for(auto i:a[node]){
        if(i!=par) dfs(i,node);
    }
    postorder.pb(node);
}
int f(int k){
    if(ans[k]!=-1) return ans[k];
    for(auto node:postorder){
        int mx1=0,mx2=0;
        val[node][0]=0;
        for(auto i:a[node]){
            if(i!=p[node]){
                val[node][0]+=val[i][0];
                if(val[i][1]>mx1){
                    mx2=mx1;
                    mx1=val[i][1];
                }
                else{
                    mx2=max(mx2,val[i][1]);
                }
            }
        }
        if(mx1+mx2+1>=k){
            val[node][0]++;
            val[node][1]=0;
        }
        else{
            val[node][1]=mx1+1;
        }
    }
    return ans[k]=val[1][0];
}
void sol(int l,int r,int lbnd,int ubnd){
    if(r-l<=1) return;
    if(lbnd==ubnd){
        rep(i,l,r+1) ans[i]=lbnd;
        return;
    }
    int m=(l+r)/2;
    sol(l,m,lbnd,f(m));
    sol(m+1,r,f(m+1),ubnd);
}
void solve(){
    scanf("%d",&n);
    rep(i,0,n-1){
        int u,v;
        scanf("%d %d",&u,&v);
        a[u].pb(v);
        a[v].pb(u);
    }
    memset(ans,-1,sizeof ans);
    dfs(1,0);
    int d=min(n,1000);
    rep(i,1,d+1) f(i);
    sol(d+1,n,f(d+1),f(n));
    rep(i,1,n+1){
        printf("%d\n",ans[i]);
    }
}

signed main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}