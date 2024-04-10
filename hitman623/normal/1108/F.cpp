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
int n,m,par[200005],ans;
map<int,vii> mp;
int fp(int x){
    if(x==par[x]) return x;
    else return par[x]=fp(par[x]);
}
void merge(int x,int y){
    x=fp(x);
    y=fp(y);
    par[x]=y;
}
void solve(){
    cin>>n>>m;
    rep(i,1,n+1) par[i]=i;
    rep(i,0,m){
        int x,y,w;
        cin>>x>>y>>w;
        mp[w].pb({x,y});
    }
    for(auto i:mp){
        int cnt=0;
        for(auto j:i.y){
            if(fp(j.x)==fp(j.y)) continue;
            else cnt++;
        }
        for(auto j:i.y){
            if(fp(j.x)==fp(j.y)) continue;
            else cnt--,merge(j.x,j.y);
        }
        ans+=cnt;
    }
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