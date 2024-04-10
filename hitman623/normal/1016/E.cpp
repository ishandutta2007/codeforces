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
double s,a,b,p[200005];
int q,n;
vector<pair<double,ll>> v;
void solve(){
    cin>>s>>a>>b;
    cin>>n;
    rep(i,0,n){
        int l,r;
        cin>>l>>r;
        v.pb({l,r});
    }
    rep(i,0,n){
        p[i]=(v[i].y-v[i].x);
        if(i) p[i]+=p[i-1];
    }
    cin>>q;
    while(q--){
        int x,y;
        double d=0;
        cin>>x>>y;
        double l=a-s*(a-x)/(s-y),r=b-s*(b-x)/(s-y);
        if(l>v.back().y || r<v[0].x){
            cout<<d<<endl;
            continue;
        }
        pair<double,ll> g={l,-1e12};
        int u=lower_bound(all(v),g)-v.begin()-1;
        u=max(u,0);
        g={r,1e12};
        int e=upper_bound(all(v),g)-v.begin()+1;
        e=min(e,sz(v)-1);
        while(u<sz(v) and v[u].y<l) u++;
        if(v[u].x<l){
            d+=min(r,1.0*v[u].y)-l;
            u++;
        }
        while(e>=0 and v[e].x>r) e--;
        if(e>=u and v[e].y>r){
            d+=r-max(v[e].x,l);
            e--;
        }
        if(u<=e) d+=p[e]-(u?p[u-1]:0);
        cout<<d*(y-s)/y<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed<<setprecision(10);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}