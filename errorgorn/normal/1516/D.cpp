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
#define debug(x) cout << #x << " is " << x << endl

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

const int B=320; //laziness

int n,q;
int arr[100005];
int nxt[100005];
int nxt2[100005];

vector<int> pf[100005];

bool has[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>q;
	rep(x,0,n) cin>>arr[x];
	
	rep(x,0,n){
		rep(y,2,B+5) if (arr[x]%y==0){
			pf[x].pub(y);
			while (arr[x]%y==0) arr[x]/=y;
		}
		if (arr[x]!=1) pf[x].pub(arr[x]);
	}
	
	int curr=0;
	rep(x,0,n){
		if (x) for (auto &it:pf[x-1]){
			has[it]=false;
		}
		
		while (curr<n){
			bool can=true;
			for (auto &it:pf[curr]) if (has[it]) can=false;
			
			if (!can) break;
			
			for (auto &it:pf[curr]) has[it]=true;
			curr++;
		}
		
		nxt[x]=curr;
	}
	
	nxt[n]=n+1;
	nxt[n+1]=n+1;
	
	memset(nxt2,-1,sizeof(nxt2));
	rep(x,0,n){
		int curr=x;
		rep(zzz,0,B) curr=nxt[curr];
		nxt2[x]=curr;
	}
	
	//rep(x,0,n) cout<<nxt[x]<<" "; cout<<endl;
	//rep(x,0,n) cout<<nxt2[x]<<" "; cout<<endl;
	
	int a,b;
	while (q--){
		cin>>a>>b;
		a--,b--;
		
		int ans=0;
		while (nxt2[a]!=n+1 && nxt2[a]<=b){
			ans+=B;
			a=nxt2[a];
		}
		while (a<=b){
			ans++;
			a=nxt[a];
		}
		
		cout<<ans<<endl;
	}
}