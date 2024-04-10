// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define int long long
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

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,k;
int arr[100005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>k;
		rep(x,0,n) cin>>arr[x];
		
		set<int,greater<int> > s(arr,arr+n);
		priority_queue<int,vector<int>,greater<int> > rem;
		rep(x,0,2*n+5) if (!s.count(x)) rem.push(x);
		rep(x,0,k) rem.pop();
		
		map<int,int> m;
		rep(x,0,n) if (arr[x]>rem.top()) m[arr[x]]++;
		
		vector<int> v;
		for (auto [a,b]:m) v.pub(b);
		
		//for (auto it:v) cout<<it<<" "; cout<<endl;
		sort(all(v));
		reverse(all(v));
		while (!v.empty() && v.back()<=k){
			k-=v.back(); v.pob();
		}
		
		cout<<sz(v)<<endl;
	}
}