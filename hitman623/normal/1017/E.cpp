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
int n,m;
vii v1,v2,h1,h2;
multiset<pii> s1,s2; 
int cross(pii A, pii B, pii C){
    return (B.x-A.x)*(C.y-A.y)-(B.y-A.y)*(C.x-A.x);
}
void convex_hull(vector<pii> pts, vector<pii>& hull) {
    hull.clear();
    sort(pts.begin(), pts.end());
    rep(i,0,sz(pts)){
        while(sz(hull)>=2 && cross(hull[sz(hull)-2],hull.back(),pts[i])<=0) hull.pop_back();
        hull.pb(pts[i]);
    }
    int s=sz(hull);
    for(int i=pts.size()-2;i>=0;i--){
        while(sz(hull)>=s+1 && cross(hull[sz(hull)-2],hull.back(),pts[i])<=0) hull.pop_back();
        hull.pb(pts[i]);
    }
    hull.pop_back();
}
void solve(){
    cin>>n>>m;
    rep(i,0,n){
        int x,y;
        cin>>x>>y;
        v1.pb({x,y});
    }
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        v2.pb({x,y});
    }
    convex_hull(v1,h1);
    convex_hull(v2,h2);
    n=sz(h1);
    rep(i,0,n){
        int l=i;
        int r=(i+1)%n;
        int h=(i+2)%n;
        long long d=(h1[l].x-h1[r].x)*(h1[l].x-h1[r].x)+(h1[l].y-h1[r].y)*(h1[l].y-h1[r].y);
        long long c=cross(h1[l],h1[r],h1[h]);
        s1.insert({d,c});
    }
    m=sz(h2);
    rep(i,0,m){
        int l=i;
        int r=(i+1)%m;
        int h=(i+2)%m;
        long long d=(h2[l].x-h2[r].x)*(h2[l].x-h2[r].x)+(h2[l].y-h2[r].y)*(h2[l].y-h2[r].y);
        long long c=cross(h2[l],h2[r],h2[h]);
        s2.insert({d,c});
    }
    if(s1==s2){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
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