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
int n,a[505],s;
vi one,two,path;
vii edges;
void solve(){
    cin>>n;
    rep(i,1,n+1){
    	cin>>a[i];
    	if(a[i]==1) one.pb(i);
    	else two.pb(i);
    	s+=a[i];
    }
    if(s<2*n-2){
    	cout<<"No"<<endl;
    	return;
    }
    int l,r,ans=sz(two);
    if(sz(one)) l=one.back(),one.pop_back(),ans++;
    else l=two.back(),two.pop_back();
    if(sz(one)) r=one.back(),one.pop_back(),ans++;
    else r=two.back(),two.pop_back();
    path.pb(l);
    for(auto i:two) path.pb(i);
    path.pb(r);
	int cur=0;
	for(auto i:path){
		while(cur<sz(one) and a[i]>2) edges.pb({one[cur++],i}),a[i]--;
	}
	cout<<"Yes "<<ans-1<<endl;
	cout<<n-1<<endl;
	rep(i,0,sz(path)-1){
		cout<<path[i]<<" "<<path[i+1]<<endl;
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