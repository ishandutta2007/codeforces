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

const int L1=30,L2=2;

int n;
int arr[2005][2005];
int ans[2005];

int memo[2][2005][L2+1];

signed main(){
	cin.tie(0);
	cout.tie(0);
	cin.sync_with_stdio(false);
	
	cin>>n;
	rep(x,1,n+1) rep(y,x+1,n+1){
		cin>>arr[x][y];
		arr[y][x]=arr[x][y];
	}
	
	ii idx={1,2};
	rep(x,1,n+1) rep(y,x+1,n+1){
		if (arr[x][y]<arr[idx.fi][idx.se]) idx={x,y};
	}
	
	//cout<<idx.fi<<" "<<idx.se<<endl;
	
	memset(memo,63,sizeof(memo));
	memset(ans,63,sizeof(ans));
	
	int mn=arr[idx.fi][idx.se];
	ans[idx.fi]=ans[idx.se]=mn*(n-1);
	
	int a=0,b=1;
	memo[a][idx.fi][0]=memo[a][idx.se][0]=0;
	
	rep(i,1,L1){
		memset(memo[b],63,sizeof(memo[b]));
		
		rep(x,1,n+1) rep(y,0,L2) rep(z,1,n+1) if (x!=z){
			memo[b][z][y+1]=min(memo[b][z][y+1],memo[a][x][y]);
			int temp=memo[a][x][y]+(y+1)*arr[x][z];
			memo[b][z][0]=min(memo[b][z][0],temp);
			ans[z]=min(ans[z],temp+(n-1-i)*mn);
		}
		
		swap(a,b);
	}
	
	rep(x,1,n+1) cout<<ans[x]<<endl;
}