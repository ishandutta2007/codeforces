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

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

const int MOD=3883975770039597613;

int n;
vector<int> al[100005];
int ss[100005];

void dfs(int i,int p){
	ss[i]=1;
	for (auto it:al[i]){
		if (it==p) continue;
		dfs(it,i);
		ss[i]+=ss[it];
	}
}

int d[100005];
map<int,vector<int> > m;

int dep[100005];
int droot[100005];
int h[100005];
int in[100005];
int out[100005];
int TIME=0;

void dfs2(int i,int p){
	in[i]=++TIME;
	
	vector<int> v;
	for (auto it:al[i]){
		if (it==p) continue;
		droot[it]=droot[i]+1;
		dfs2(it,i);
		v.pub(h[it]);
		dep[i]=max(dep[i],dep[it]+1);
	}
	
	if (v.empty()) v.pub(0);
	h[i]=1;
	for (auto it:v) h[i]=(__int128)h[i]*(it+d[dep[i]])%MOD;
	
	m[h[i]].pub(i);
	out[i]=TIME;
}

int pref[100005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	rep(x,0,100005) d[x]=rng()%MOD;
	
	cin>>n;
	
	int a,b;
	rep(x,1,n){
		cin>>a>>b;
		al[a].pub(b);
		al[b].pub(a);
	}
	
	dfs(1,-1);
	
	int curr=1,currp=-1;
	while (true){
		bool done=true;
		for (auto it:al[curr]){
			if (it==currp) continue;
			if (ss[it]>=(n+1)/2){
				currp=curr;
				curr=it;
				done=false;
				break;
			}
		}
		if (done) break;
	}
	
	dfs2(curr,-1);
	
	int extra=0;
	for (auto [a,b]:m){
		extra++;
		if (sz(b)==1) pref[in[b[0]]]++,pref[out[b[0]]+1]--;
	}
	rep(x,1,100005) pref[x]+=pref[x-1];
	
	int ans=-1;
	int best=-1;
	rep(x,1,n+1){
		int temp=extra+droot[x]-pref[in[x]];
		if (best<temp){
			ans=x;
			best=temp;
		}
	}
	
	cout<<ans<<endl;
}