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
int n,s[200005],mx,mn;
vii a[200005];
void dfs(int node,int par,int w){
    s[node]=1;
    for(auto i:a[node]){
        if(i.x!=par){
            dfs(i.x,node,i.y);
            s[node]+=s[i.x];
        }
    }
    if(s[node]%2) mn+=w;
    mx+=w*min(s[node],n-s[node]);
}
void solve(){
    cin>>n;
    n*=2;
    rep(i,1,n+1){
        s[i]=0;
        a[i].clear();
    }
    mn=mx=0;
    rep(i,0,n-1){
        int x,y,w;
        cin>>x>>y>>w;
        a[x].pb({y,w});
        a[y].pb({x,w});
    }
    dfs(1,-1,0);
    cout<<mn<<" "<<mx<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}