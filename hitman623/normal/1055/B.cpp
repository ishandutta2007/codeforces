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
struct DSU{
    int N,components;
    vi par,s;
    DSU(int n){
        N=n;
        components=n;
        par.resize(N+1);
        s.resize(N+1);
        s.assign(N+1,1);
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
        components--;
    }
};
int n,m,l,cnt,a[100005];
void solve(){
    cin>>n>>m>>l;
    rep(i,1,n+1) cin>>a[i],cnt+=a[i]<=l;
    DSU obj(n);
    rep(i,2,n+1) if(a[i]>l and a[i-1]>l) obj.merge(i,i-1);
    while(m--){
        int type;
        cin>>type;
        if(type==0){
            cout<<obj.components-cnt<<endl;
        }
        else{
            int x,y;
            cin>>x>>y;
            if(a[x]<=l and a[x]+y>l) cnt--;
            a[x]+=y;
            if(a[x]>l and a[x-1]>l) obj.merge(x,x-1);
            if(a[x]>l and a[x+1]>l) obj.merge(x,x+1);
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