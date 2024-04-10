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
int n,m,cnt=1;
vi a[1001];
void solve(){
    cin>>n>>m;
    rep(i,0,m){
        int x,y;
        cin>>x>>y;
        a[x].pb(cnt);
        a[y].pb(cnt);
        cnt++;
    }
    rep(i,1,n+1){
    	if(sz(a[i])==0) a[i].pb(cnt++);
    	cout<<sz(a[i])<<endl;
    	for(auto j:a[i]){
    		cout<<i<<" "<<j<<endl;
    	}
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