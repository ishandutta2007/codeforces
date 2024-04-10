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

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
int arr[300005];
vector<int> al[300005];
int w[300005];

vector<int> stk;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,0,n) cin>>arr[x];
	
	rep(x,0,n){
		bool bad=false;
		while(!stk.empty() && arr[stk.back()]<=arr[x]){
			if (!bad) al[stk.back()].push_back(x);
			if (arr[stk.back()]==arr[x]) bad=true;
			stk.pop_back();
		}
		if (!stk.empty() && !bad) al[stk.back()].push_back(x);
		stk.push_back(x);
	}
	stk.clear();
	
	rep(x,0,n){
		bool bad=false;
		while(!stk.empty() && arr[stk.back()]>=arr[x]){
			if (!bad) al[stk.back()].push_back(x);
			if (arr[stk.back()]==arr[x]) bad=true;
			stk.pop_back();
		}
		if (!stk.empty() && !bad) al[stk.back()].push_back(x);
		stk.push_back(x);
	}
	
	rep(x,0,n-1) al[x].push_back(x+1);
	
	memset(w,63,sizeof(w));
	w[0]=0;
	
	rep(x,0,n-1){
		for (auto &it:al[x]) w[it]=min(w[it],w[x]+1);
	}
	
	cout<<w[n-1]<<endl;
}