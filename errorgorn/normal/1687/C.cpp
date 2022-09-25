// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
using namespace std;

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

int n,m;
int arr[200005];
int brr[200005];

vector<int> al[200005];
ii ranges[200005];
int cnt[200005];
set<int> diff;
vector<ii> q;

void proc(int i){
	for (auto it:al[i]){
		cnt[it]--;
		if (cnt[it]==0){
			q.pub(ranges[it]);
		}
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		
		cin>>n>>m;
		rep(x,1,n+1) cin>>arr[x];
		rep(x,1,n+1) cin>>brr[x];
		rep(x,0,n+1) al[x].clear();
		diff.clear();
		
		rep(x,0,m) cin>>ranges[x].fi>>ranges[x].se;
		rep(x,0,m) cnt[x]=2;
		rep(x,0,m) al[ranges[x].fi-1].pub(x),al[ranges[x].se].pub(x);
		
		rep(x,1,n+1) arr[x]+=arr[x-1];
		rep(x,1,n+1) brr[x]+=brr[x-1];
		
		// rep(x,1,n+1) cout<<arr[x]<<" "; cout<<endl;
		// rep(x,1,n+1) cout<<brr[x]<<" "; cout<<endl;
		
		rep(x,0,n+1){
			if (arr[x]!=brr[x]) diff.insert(x);
			else proc(x);
		}
		
		while (!q.empty()){
			int a,b;
			tie(a,b)=q.back(); q.pob();
			
			//cout<<a<<" "<<b<<endl;
			
			while (diff.lb(a)!=diff.end() && *diff.lb(a)<b){
				auto it=diff.lb(a);
				proc(*it);
				diff.erase(it);
			}
		}
		
		if (diff.empty()) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
}