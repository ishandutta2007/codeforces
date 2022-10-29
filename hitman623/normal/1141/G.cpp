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
int n,k,deg[200005],colors,col[200005];
vi v;
vii a[200005];
void dfs(int node,int par,int parcol){
    int c=1;
    for(auto i:a[node]){
        if(i.x!=par){
            if(c==parcol){
                c++;
                if(c>colors) c-=colors;
            }
            col[i.y]=c;
            dfs(i.x,node,c);
            c++;
            if(c>colors) c-=colors;
        }
    }
}
void solve(){
    cin>>n>>k;
    rep(i,0,n-1){
        int x,y;
        cin>>x>>y;
        a[x].pb({y,i});
        a[y].pb({x,i});
        deg[x]++;
        deg[y]++;
    }
    rep(i,1,n+1) v.pb(deg[i]);
    sort(all(v));
    reverse(all(v));
    colors=v[k];
    dfs(1,0,0);
    cout<<colors<<endl;
    rep(i,0,n-1) cout<<col[i]<<" ";
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