//
//

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
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
int arr[105][105]; //split into halls
int brr[105][105];

vector<int> al[105];

int le[105];
bool vis[105];
bool dfs(int i){
	if (vis[i]) return false;
	vis[i]=true;
	
	for (auto &it:al[i]){
		if (le[it]==-1 || dfs(le[it])){
			le[it]=i;
			return true;
		}
	}
	return false;
}

int ans[105][10005];

int TIME;
void dfs2(int row,int pos){
	int cpos=pos;
	int val=arr[cpos][row];
	
	do{
		vis[cpos]=true;
		cpos=arr[cpos][row];
	} while (cpos!=pos);
	
	do{
		do{
			//if (row==0) cout<<"debug: "<<cpos<<" "<<TIME<<" "<<val<<endl;
			ans[(row+TIME)%n][TIME]=val;
			TIME++;
			
			cpos=(cpos+1)%n;
			
			if (cpos!=val && !vis[cpos]){
				if (arr[cpos][row]==cpos) continue;
				dfs2(row,cpos);
			}
		} while (cpos!=val);
		val=arr[cpos][row];
	} while (cpos!=pos);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,0,n) rep(y,0,n){
		cin>>brr[x][y];
		brr[x][y]--;
	}
	
	rep(x,0,n) rep(y,0,n){
		al[x].pub(brr[x][y]);
	}
	
	rep(y,0,n){
		memset(le,-1,sizeof(le));
		
		rep(x,0,n){
			memset(vis,false,sizeof(vis));
			dfs(x);
		}
		
		rep(x,0,n){
			int a=le[x];
			arr[a][y]=x;
			
			rep(z,0,n) if (al[a][z]==x){
				al[a].erase(al[a].begin()+z);
				break;
			}
		}
	}
	
	// rep(x,0,n){
		// rep(y,0,n) cout<<arr[x][y]<<" "; cout<<endl;
	// }
	
	rep(x,0,n) rep(y,0,10005) ans[(x+y)%n][y]=x;
	
	rep(x,0,n){
		TIME=0;
		
		memset(vis,false,sizeof(vis));
		vis[x]=true;
		dfs2(x,x);
	}
	
	cout<<n*n-n<<endl;
	rep(y,0,n*n-n) {
		 rep(x,0,n) cout<<ans[x][y]+1<<" "; cout<<endl;
	}
}