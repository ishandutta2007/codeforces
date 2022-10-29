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
pii v[3];
int lx=hell,rx=-1,ly=hell,ry=-1;
void solve(){
    rep(i,0,3) cin>>v[i].x>>v[i].y;
    sort(v,v+3);
    rep(i,0,3){
        lx=min(lx,v[i].x);
        rx=max(rx,v[i].x);
        ly=min(ly,v[i].y);
        ry=max(ry,v[i].y);
    }
    cout<<rx-lx+ry-ly+1<<endl;
    rep(i,ly,ry+1) cout<<v[1].x<<" "<<i<<endl;
    while(v[0].x!=v[1].x) cout<<v[0].x++<<" "<<v[0].y<<endl;
    while(v[2].x!=v[1].x) cout<<v[2].x--<<" "<<v[2].y<<endl;
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