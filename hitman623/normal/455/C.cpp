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

struct DSU{
    int N,components;
    vi par,s,val;
    DSU(int n){
        N=n;
        components=n;
        par.resize(N+1);
        s.resize(N+1);
        s.assign(N+1,1);
        val.resize(N+1);
        iota(all(par),0);
    }
    int find_par(int node){
        if(node==par[node]) return node;
        else return par[node]=find_par(par[node]);
    }
    void merge(int u,int v){
        u=find_par(u);
        v=find_par(v);
        if(u==v) return;
        if(s[u]<s[v]) swap(u,v);
        par[v]=u;
        s[u]+=s[v];
        s[v]=0;
        val[u]=max({val[u],val[v],val[u]/2+val[v]/2+2});
        components--;
    }
};
int n,m,q,vis[300005],h[300005];
vi a[300005];
vi v;
int bfs(int node){
    v.clear();
    queue<int> Q;
    Q.push(node);
    int ans=-1;
    while(!Q.empty()){
        auto d=Q.front();
        Q.pop();
        vis[d]=1;
        ans=d;
        v.pb(d);
        for(auto i:a[d]){
            if(!vis[i]) Q.push(i),h[i]=h[d]+1;
        }
    }
    return ans;
}
void solve(){
    cin>>n>>m>>q;
    DSU obj(n);
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    rep(i,1,n+1){
        if(!vis[i]){
            int d=bfs(i);
            for(auto j:v) vis[j]=0,h[j]=0;
            d=bfs(d);
            for(auto j:v){
                obj.merge(j,i);
            }
            obj.val[obj.find_par(i)]=h[d]+1;
        }
    }
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int x;
            cin>>x;
            x=obj.find_par(x);
            cout<<obj.val[x]-1<<endl;
        }
        else{
            int x,y;
            cin>>x>>y;
            obj.merge(x,y);
        }
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