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

int n,m,k;
vector<ii> al[100005];
ll w[100005];
int cnt[100005];

priority_queue<ii,vector<ii>,greater<ii> > pq;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m>>k;
	
	int ans=0;
	memset(w,63,sizeof(w));
	
	int a,b,c;
	rep(x,0,m){
		cin>>a>>b>>c;
		al[a].pub(ii(b,c));
		al[b].pub(ii(a,c));
	}
	
	rep(x,0,k){
		cin>>a>>b;
		if (w[a]>b){
			ans-=cnt[a];
			cnt[a]=1;
			ans++;
			w[a]=b;
			pq.push(ii(w[a],a));
		}
	}
	
	w[1]=0;
	pq.push(ii(w[1],1));
	
	ll weight,node;
	while (!pq.empty()){
		tie(weight,node)=pq.top(),pq.pop();
		
		if (weight>w[node]) continue;
		
		for (auto &it:al[node]){
			if (w[it.fi]>weight+it.se ||
				(w[it.fi]==weight+it.se && cnt[it.fi])){
				w[it.fi]=weight+it.se;
				ans-=cnt[it.fi];
				cnt[it.fi]=0;
				pq.push(ii(w[it.fi],it.fi));
			}
		}
	}
	
	cout<<k-ans<<endl;
}