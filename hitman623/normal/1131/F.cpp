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
int n,par[150005];
vi a[150005];
int fp(int x){
    if(par[x]==x) return x;
    else return par[x]=fp(par[x]);
}
void solve(){
    cin>>n;
    rep(i,1,n+1) a[i].pb(i),par[i]=i;
    rep(i,0,n-1){
        int x,y;
        cin>>x>>y;
        x=fp(x);
        y=fp(y);
        if(sz(a[x])>sz(a[y])){
            for(auto j:a[y]){
                a[x].pb(j);
            }
            par[y]=x;
            a[y].clear();
        }
        else{
            for(auto j:a[x]){
                a[y].pb(j);
            }
            par[x]=y;
            a[x].clear();
        }
    }
    int root=fp(1);
    for(auto i:a[root]) cout<<i<<" ";
    cout<<endl;
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