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
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int expo(int base,int exponent,int mod){
    if(base==0) return 0;
    int ans=1;
    while(exponent!=0){
        if(exponent&1) ans=(1LL*ans*base)%mod;
        base=(1LL*base*base)%mod;
        exponent>>=1;
    }
    return ans%mod;
}
int n,k,par[100005],s[100005];
int fp(int node){
    if(node==par[node]) return node;
    else return par[node]=fp(par[node]);
}
void merge(int u,int v){
    u=fp(u);
    v=fp(v);
    if(u==v) return;
    if(s[u]<s[v]) swap(u,v);
    par[v]=u;
    s[u]+=s[v];
    s[v]=0;
}

void solve(){
    cin>>n>>k;
    rep(i,1,n+1) par[i]=i,s[i]=1;
    rep(i,0,n-1){
        int x,y,c;
        cin>>x>>y>>c;
        if(c==0) merge(x,y);
    }
    int ans=expo(n,k,hell);
    rep(i,1,n+1) ans=(ans-expo(s[i],k,hell)+hell)%hell;
    cout<<ans<<endl;
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