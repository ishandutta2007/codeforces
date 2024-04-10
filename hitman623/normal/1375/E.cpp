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
int n,a[1003],b[1003],vis[1003][1003];
vi f[1003];
vii res;
void solve(){
	cin>>n;
	rep(i,1,n+1) cin>>a[i];
	rep(i,1,n+1) b[i]=a[i];
	int cnt=0;
	rep(i,1,n+1){
		rep(j,1,i){
			if(a[j]>a[i]){
				f[i].pb(j);
				cnt++;
			}
		}
	}
	for(int i=n;i>=1;i--){
		vii v;
		for(auto j:f[i]){
			v.pb({a[j],j});
		}
		sort(all(v));
		for(auto j:v){
			if(a[j.y]<a[i]){
				;
			}
			else if(a[j.y]==a[i]){
				if(vis[j.y][i]==0){
					res.pb({j.y,i});
					vis[j.y][i]=1;
				}
			}
			else{
				assert(vis[j.y][i]==0);
				swap(a[j.y],a[i]);
				res.pb({j.y,i});
				vis[j.y][i]=1;
			}
		}
		rep(j,0,sz(f[i])){
			rep(k,1,n+1){
				int x=f[i][j];
				int y=k;
				if(x==y) continue;
				if(x>y) swap(x,y);
				if(b[x]>b[y] and a[x]==a[y] and vis[x][y]==0){
					res.pb({x,y});
					vis[x][y]=1;
				}
			}
		}
	}
	rep(i,1,n){
		if(a[i]>a[i+1]){
			while(1);
			cout<<-1<<endl;
			return;
		}
	}
	cout<<sz(res)<<endl;
	for(auto i:res) cout<<i.x<<" "<<i.y<<endl;
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