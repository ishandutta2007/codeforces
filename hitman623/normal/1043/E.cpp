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
int n,m,sumx,ans[300005];
vector<pair<pii,pii>> v;
pii vals[300005];
vi a[300005];
void solve(){
    cin>>n>>m;
    rep(i,1,n+1){
        int x,y;
        cin>>x>>y;
        v.pb({{x-y,i},{x,y}});
        vals[i]={x,y};
        sumx+=x;
    }
    sort(all(v));
    reverse(all(v));
    rep(i,0,m){
        int u,V;
        cin>>u>>V;
        a[u].pb(V);
        a[V].pb(u);
    }
    int sumy=0,cnt=0;
    for(auto i:v){
        sumx-=i.y.x;
        int id=i.x.y;
        ans[id]+=cnt*i.y.x+sumy+(n-cnt-1)*i.y.y+sumx;
        for(auto j:a[id]){
            ans[id]-=min(vals[id].x+vals[j].y,vals[id].y+vals[j].x);
        }
        sumy+=i.y.y;
        cnt++;
    }
    rep(i,1,n+1){
        cout<<ans[i]<<" ";
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