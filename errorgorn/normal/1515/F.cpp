// Super Idol
//    
//  
//    
//  105C
// 

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

ll n,m,k;
ll arr[300005];
int p[300005];
vector<ii> al[300005];

int par(int i){
	if (i==p[i]) return i;
	else return p[i]=par(p[i]);
}

void rage(){
	cout<<"NO"<<endl;
	exit(0);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m>>k;
	rep(x,0,n) cin>>arr[x];
	
	ll a,b;
	rep(x,1,m+1){
		cin>>a>>b;
		a--,b--;
		al[a].pub({b,x});
		al[b].pub({a,x});
	}
	
	rep(x,0,n) p[x]=x;
	
	priority_queue<ii> pq;
	rep(x,0,n) pq.push({arr[x],x});
	
	vector<int> ans;
	
	while (!pq.empty()){
		tie(a,b)=pq.top(),pq.pop();
		if (arr[b]!=a) continue;
		if (par(b)!=b) continue;
		
		bool flag=false;
		while (!al[b].empty()){
			if (par(al[b].back().fi)==par(b)) al[b].pob();
			else{
				a=par(al[b].back().fi);
				ans.pub(al[b].back().se);
				al[b].pob();
				flag=true;
				
				if (arr[a]+arr[b]<k) rage();
				
				p[a]=b;
				arr[b]=arr[b]+arr[a]-k;
				
				if (sz(al[a])>sz(al[b])) swap(al[a],al[b]);
				for (auto &it:al[a]) al[b].pub(it);
				
				pq.push({arr[b],b});
				break;
			}
		}
		
		if (!flag) rage();
		
		if (sz(ans)==n-1) break;
	}
	
	cout<<"YES"<<endl;
	for (auto &it:ans) cout<<it<<endl;
}