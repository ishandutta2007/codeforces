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
int n;
mi f;
vii v,p;
vi ans[400005];
void solve(){
    cin>>n;
    rep(i,0,n){
        int x;
        cin>>x;
        f[x]++;
    }
    for(auto i:f){
        v.pb({i.y,i.x});
    }
    sort(all(v));
    p=v;
    rep(i,1,sz(p)) p[i].x=p[i].x+p[i-1].x;
    int mx=0,l=-1,b=-1;
    rep(i,1,sz(v)+1){
        int w=lower_bound(all(v),make_pair(i,-hell))-v.begin();
        int q=sz(v)-w;
        int e=q*i+(w?p[w-1].x:0);
        int m=e/i;
        if(i<=m and mx<i*m){
            l=i;
            b=m;
            mx=i*m;
        }
    }
    cout<<mx<<endl;
    cout<<l<<" "<<b<<endl;
    int w=lower_bound(all(v),make_pair(l,-hell))-v.begin();
    vi u;
    rep(i,w,sz(v)){
        rep(j,0,l) u.pb(v[i].y);
    }
    rep(i,0,w){
        rep(j,0,v[i].x){
            u.pb(v[i].y);
        }
    }
    rep(i,0,l) ans[i].resize(b);
    int cur=0;
    rep(i,0,b){
        int x=0,y=i;
        rep(j,0,l){
            ans[x][y]=u[cur++];
            x=(x+1)%l;
            y=(y+1)%b;
        }
    }
    rep(i,0,l){
        rep(j,0,b){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
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