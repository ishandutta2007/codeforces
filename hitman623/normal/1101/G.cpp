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
int n,a[200005];
vi basis;
void add(int x){
	rep(i,0,sz(basis)){
		x=min(x,basis[i]^x);
	}
	if(x) basis.pb(x);
}
void solve(){
	basis.pb(0);
    cin>>n;
    rep(i,1,n+1) cin>>a[i];
    rep(i,1,n+1) a[i]^=a[i-1];
    if(a[n]==0){
    	cout<<-1<<endl;
    	return;
    }
    rep(i,1,n+1) if(a[i]) add(a[i]);
    cout<<sz(basis)-1<<endl;
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