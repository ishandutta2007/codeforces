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
int n,m;
vii v;
void solve(){
    cin>>n>>m;
    pii l={1,1},r={n,m};
    rep(i,0,n*m){
        v.pb(l);
        if(r==l) break;
        v.pb(r);
        l.y++;
        if(l.y==m+1) l.x++,l.y=1;
        if(l==r) break;
        r.y--;
        if(r.y==0) r.x--,r.y=m;
    }
    for(auto i:v) cout<<i.x<<" "<<i.y<<endl;
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