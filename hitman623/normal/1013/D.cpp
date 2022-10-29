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
int n,m,q,par[500005];
int fp(int x){
	if(par[x]==x) return x;
	else return par[x]=fp(par[x]);
}
void solve(){
	cin>>n>>m>>q;
	int ans=n+m-1;
	rep(i,1,500000) par[i]=i;
	rep(i,0,q){
		int x,y;
		cin>>x>>y;
		x=fp(x);
		y+=200005;
		y=fp(y);
		if(x!=y){
			par[x]=y;
			ans--;
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