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
vii pts;
mii color;
int query(int x,int y){
    cout<<x<<" "<<y<<endl;
    string c;
    cin>>c;
    return c=="black";
}
void solve(){
    cin>>n;
    pts.pb({0,0});
    color[{0,0}]=query(0,0);
    int lo=1,hi=1e9-2;
    rep(_,0,n-1){
        int mid;
        mid=(lo+hi)/2;
        int g=query(mid,0);
        if(color[pts.back()]==g){
            if(pts.back().x>mid) hi=mid;
            else lo=mid;
        }
        else{
            if(pts.back().x>mid) lo=mid;
            else hi=mid;
        }
        pts.pb({mid,0});
        color[pts.back()]=g;
    }
    sort(all(pts));
    if(color[pts[0]]==color[pts.back()]){
        cout<<1000000000<<" "<<0<<" "<<1000000000<<" "<<1<<endl;
        return;
    }
    rep(i,0,n-1){
        if(color[pts[i]]!=color[pts[i+1]]){
            cout<<pts[i].x+1<<" "<<1<<" "<<pts[i].x+2<<" "<<3<<endl;
            return;
        }
    }
}

signed main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}