
// Problem: A. Anu Has a Function
// Contest: Codeforces - Codeforces Round #618 (Div. 1)
// URL: https://codeforces.com/contest/1299/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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
int arr[100005];
int cnt[30];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,0,n) cin>>arr[x];
	rep(x,0,n) rep(y,0,30) if (arr[x]&(1<<y)) cnt[y]++;
	
	int idx=0;
	int best=0;
	
	rep(x,0,n){
		int val=0;
		rep(y,0,30) if ((arr[x]&(1<<y)) && cnt[y]==1) val|=(1<<y);
		
		if (best<val){
			best=val;
			idx=x;
		}
	}
	
	cout<<arr[idx]<<" "; rep(x,0,n) if (x!=idx) cout<<arr[x]<<" "; cout<<endl;
}