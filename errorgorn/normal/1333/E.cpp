#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << " is " << x << endl;

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

ll MAX(ll a){return a;}
ll MIN(ll a){return a;}
template<typename... Args>
ll MAX(ll a,Args... args){return max(a,MAX(args...));}
template<typename... Args>
ll MIN(ll a,Args... args){return min(a,MIN(args...));}

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

int arr[505][505];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	memset(arr,-1,sizeof(arr));
	
	int n;
	cin>>n;
	
	rep(x,0,n+2){
		arr[x][0]=0;
		arr[0][x]=0;
		arr[x][n+1]=0;
		arr[n+1][x]=0;
	}
	
	if (n<3) cout<<"-1"<<endl;
	else{
		// 0
		//1 3
		// 2
		ii pos;
		int dir;
		int curr=1;
		
		if (n&1) pos=ii(1,1),dir=3;
		else pos=ii(n,n),dir=1;
		
		while (pos!=ii((n-1)/2,n/2)){
			if (arr[pos.fi][pos.se]==-1)arr[pos.fi][pos.se]=curr++;
			
			if (dir==0){
				if (arr[pos.fi+1][pos.se]==-1) pos.fi++;
				else dir=1;
			}
			else if (dir==1){
				if (arr[pos.fi][pos.se-1]==-1) pos.se--;
				else dir=2;
			}
			else if (dir==2){
				if (arr[pos.fi-1][pos.se]==-1) pos.fi--;
				else dir=3;
			}
			else{
				if (arr[pos.fi][pos.se+1]==-1) pos.se++;
				else dir=0;
			}
		}
		
		arr[pos.fi][pos.se]=curr;
		arr[pos.fi+2][pos.se]=curr+1;
		arr[pos.fi][pos.se+2]=curr+2;
		arr[pos.fi+2][pos.se+1]=curr+3;
		arr[pos.fi+1][pos.se+1]=curr+4;
		arr[pos.fi][pos.se+1]=curr+5;
		arr[pos.fi+2][pos.se+2]=curr+6;
		arr[pos.fi+1][pos.se+2]=curr+7;
		arr[pos.fi+1][pos.se]=curr+8;
		
		
		rep(x,1,n+1){
			rep(y,1,n+1) cout<<arr[x][y]<<" ";
			cout<<endl;
		}
	}
}