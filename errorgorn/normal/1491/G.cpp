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
#define up upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
int arr[200005];
bool vis[200005];
vector<ii> ans;

void cswap(int i,int j){
	swap(arr[i],arr[j]);
	arr[i]=-arr[i],arr[j]=-arr[j];
	ans.pub(ii(i,j));
}

void swap_cyc(int i,int j){
	cswap(i,j);
	
	int curr=i;
	while (arr[-arr[curr]]>0){
		cswap(curr,-arr[curr]);
	}
	
	curr=-arr[curr];
	while (arr[-arr[curr]]>0){
		cswap(curr,-arr[curr]);
	}
	
	cswap(curr,-arr[curr]);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,1,n+1) cin>>arr[x];
	
	int p=-1;
	
	rep(x,1,n+1) if (!vis[x]){
		if (arr[x]==x) continue;
		
		int curr=x;
		do{
			vis[curr]=true;
			curr=arr[curr];
		} while (curr!=x);
		
		if (p==-1) p=x;
		else{
			swap_cyc(p,x);
			p=-1;
		}
	}
	
	if (p!=-1){
		bool can=false;
		rep(x,1,n+1) if (arr[x]==x){
			swap_cyc(p,x);
			can=true;
			break;
		}
		
		if (!can){
			int t1=arr[p],t2=arr[arr[p]];
			cswap(p,t1);
			swap_cyc(t1,t2);
		}
	}
	
	cout<<sz(ans)<<endl;
	for (auto &it:ans) cout<<it.fi<<" "<<it.se<<endl;
}