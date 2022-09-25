#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int,int>
#define fi first
#define se second

#define puf push_front
#define pof pop_front
#define pub push_back
#define pob pop_back
#define lb lower_bound
#define ub upper_bound

#define rep(x,s,e) for (int x=(s)-((s)>(e));x!=(e)-((s)>(e));((s)<(e))?x++:x--)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int) (x).size()

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
int arr[5005];
int cnt[5005];
bool ok[5005][5005];
int ans[5005];

signed main(){
	cin.tie(0);
	cout.tie(0);
	cin.sync_with_stdio(false);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,1,n+1) cin>>arr[x];
		rep(x,1,n+1) rep(y,1,n+1) ok[x][y]=false;
		
		rep(x,1,n+1){
			int idx=0;
			memset(cnt,0,sizeof(cnt));
			rep(y,x,n+1){
				cnt[arr[y]]++;
				if (cnt[arr[y]]>cnt[idx]) idx=arr[y];
				
				if ((y-x)%2==1 && cnt[idx]*2<=y-x+1) ok[x][y]=true;
			}
		}
		
		rep(x,0,n+2) ans[x]=-1e9;
		ans[0]=0;
		rep(x,0,n+1) rep(y,x+1,n+2) if ((x+1==y || ok[x+1][y-1]) && (x==0 || y==n+1 || arr[x]==arr[y])){
			ans[y]=max(ans[y],ans[x]+1);
		}
		
		cout<<ans[n+1]-1<<endl;
	}
}