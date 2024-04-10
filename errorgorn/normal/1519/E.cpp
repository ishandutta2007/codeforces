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

int n;
vector<ii> al[400005];

map<ii,int> m;
int IDX=0;
int pos(ll i,ll j){
	ll g=__gcd(i,j);
	i/=g,j/=g;
	if (!m.count(ii(i,j))) m[ii(i,j)]=IDX++;
	return m[ii(i,j)];
}

vector<ii> ans;
bool used[200005];
bool vis[400005];

void dfs(int i,int pe){
	vis[i]=true;
	vector<int> v;
	for (auto &it:al[i]){
		if (it.se==pe) continue;
		if (!vis[it.fi]) dfs(it.fi,it.se);
		
		if (!used[it.se]) v.pub(it.se);
	}
	
	while (sz(v)>=2){
		ans.pub(ii(v[sz(v)-2],v[sz(v)-1]));
		used[v[sz(v)-2]]=used[v[sz(v)-1]]=true;
		v.pob(),v.pob();
	}
	if (sz(v)==1 && pe!=-1){
		ans.pub(ii(v[0],pe));
		used[v[0]]=used[pe]=true;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	
	ll a,b,c,d;
	rep(x,0,n){
		cin>>a>>b>>c>>d;
		
		int u=pos((a+b)*d,c*b);
		int v=pos(a*d,(c+d)*b);
		
		//cout<<u<<" "<<v<<endl;
		
		al[u].pub(ii(v,x));
		al[v].pub(ii(u,x));
	}
	
	rep(x,0,400005) if (!vis[x]){
		dfs(x,-1);
	}
	
	cout<<sz(ans)<<endl;
	for (auto &it:ans) cout<<it.fi+1<<" "<<it.se+1<<endl;
}