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
#define N 			100002
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,vis[100005];
vi d[100005],a[100005],p[100005];
void pre(){
	rep(i,1,N+1){
		for(int j=i;j<=N;j+=i){
			d[j].pb(i);
		}
	}
	rep(i,2,N+1){
		if(sz(p[i])) continue;
		for(int j=i;j<=N;j+=i){
			p[j].pb(i);
		}
	}
}
int query(int l,int r,int w){
	int cur=0;
	rep(i,0,1<<sz(p[w])){
		int g=1;
		rep(j,0,sz(p[w])){
			if((i>>j)&1) g*=p[w][j];
		}
		int y=upper_bound(all(a[g]),r)-lower_bound(all(a[g]),l);
		if(__builtin_popcount(i)%2) cur-=y;
		else cur+=y;
	}
	return cur;
}
void solve(){
	pre();
    cin>>n;
    rep(i,0,n){
    	int x;
    	cin>>x;
    	if(vis[x]) continue;
    	for(auto j:d[x]) vis[j]=1;
    }
    rep(i,1,N+1){
    	if(vis[i]==0) continue;
    	for(auto j:d[i]) a[j].pb(i);
    }
	ll ans=1;
	rep(i,2,N+1){
	    if(vis[i]==0) continue;
		int lo=1,hi=i;
		while(hi-lo>1){
			int mid=(lo+hi)/2;
			if(query(mid,i,i)) lo=mid;
			else hi=mid;
		}
		ans=max(ans,1LL*lo*i);
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