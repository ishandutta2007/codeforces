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
int n,x[100005],y[100005],ans;
vi row[100005],col[100005];
vii pts;
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>x[i]>>y[i];
        pts.pb({x[i],y[i]});
        col[x[i]].pb(y[i]);
        row[y[i]].pb(x[i]);
    }
    sort(all(pts));
    rep(i,0,100005) sort(all(row[i]));
    rep(i,0,100005) sort(all(col[i]));
    for(auto i:pts){
        if(sz(row[i.y])<sz(col[i.x])){
            for(auto j:row[i.y]){
                if(j>i.x and binary_search(all(col[i.x]),i.y+j-i.x) and binary_search(all(pts),make_pair(j,i.y+j-i.x))) ans++;
            }
        }
        else{
            for(auto j:col[i.x]){
                if(j>i.y and binary_search(all(row[i.y]),i.x+j-i.y) and binary_search(all(pts),make_pair(i.x+j-i.y,j))) ans++;
            }
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