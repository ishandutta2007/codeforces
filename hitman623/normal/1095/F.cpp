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
int n,m,par[200005];
ll ans;
vector<pair<ll,int>> v;
int fp(int x){
    if(par[x]==x) return x;
    else return par[x]=fp(par[x]);
}
void merge(int x,int y){
    x=fp(x);
    y=fp(y);
    par[x]=y;
}
mi mp;
void solve(){
    cin>>n>>m;
    rep(i,1,n+1){
        par[i]=i;
        ll x;
        cin>>x;
        v.pb({x,i});
    }
    if(n==1){
        cout<<0<<endl;
        return;
    }
    sort(all(v));
    rep(i,0,sz(v)) mp[v[i].y]=i;
    priority_queue<pair<ll,pii>,vector<pair<ll,pii>>,greater<pair<ll,pii>>> pq;
    rep(i,0,m){
        int x,y;
        ll w;
        cin>>x>>y>>w;
        pq.push({w,{x,y}});
    }
    rep(i,1,n){
        pq.push({v[0].x+v[i].x,{v[0].y,v[i].y}});
    }
    int f=n-1;
    while(!pq.empty() and f){
        auto d=pq.top();
        pq.pop();
        int x=d.y.x,y=d.y.y;
        if(fp(x)!=fp(y)){
            merge(x,y);
            f--;
            ans+=d.x;
        }
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