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
vii v,edges;
void solve(){
    cin>>n;
    rep(i,1,n+1){
    	int d;
    	cin>>d;
    	v.pb({d,2*i-1});
    }
    sort(all(v));
    reverse(all(v));
    rep(i,1,n) edges.pb({v[i].y,v[i-1].y});
    rep(i,0,n){
    	int r=i+v[i].x-1;
    	edges.pb({v[i].y+1,v[r].y});
    	if(i+v[i].x==sz(v)) v.pb({0,v[i].y+1});
    }
    for(auto i:edges) cout<<i.x<<" "<<i.y<<endl;
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