#include <bits/stdc++.h>

#define int         long long
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
ll cross(pii A, pii B, pii C){
    return (B.x-A.x)*(C.y-A.y)-(B.y-A.y)*(C.x-A.x);
}
void convex_hull(vector<pii> pts, vector<pii>& hull) {
    hull.clear();
    sort(pts.begin(),pts.end());
    rep(i,0,sz(pts)){
        while(sz(hull)>=2 && cross(hull[sz(hull)-2],hull.back(),pts[i])<=0) hull.pop_back();
        hull.pb(pts[i]);
    }
}
vii v,hull;
void solve(){
    cin>>n;
    rep(i,0,n){
        int x,y;
        cin>>x>>y;
        v.pb({x+2e6,x*x-y+2e6});
    }
    convex_hull(v,hull);
    if(sz(hull)>=2 and hull.back().x==hull[sz(hull)-2].x) hull.pop_back();
    cout<<sz(hull)-1<<endl;
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