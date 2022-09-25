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

struct UFDS{
	int p[300005];
	
	UFDS(){
		rep(x,0,300005) p[x]=x;
	}
	
	int parent(int i){
		if (i==p[i]) return i;
		else return p[i]=parent(p[i]);
	}
	
	bool unions(int i,int j){
		i=parent(i),j=parent(j);
		if (i==j) return false;
		p[i]=j;
		return true;
	}
} ufds;

int n,m,q;
vector<int> al[300005];
int pp[300005];
int d[300005];

void dfs(int i,int p){
	for (auto &it:al[i]){
		if (it==p) continue;
		
		d[it]=d[i]+1;
		pp[it]=i;
		dfs(it,i);
	}
}

int par[300005];
vector<vector<int> > ans;

int glob=0;

int dfs2(int i,int p){
	int con=0;
	for (auto &it:al[i]){
		if (it==p) continue;
		
		int temp=dfs2(it,i);
		if (temp){
			if (con) glob--;
			con^=temp;
		}
	}
	
	//cout<<i<<" "<<con<<" "<<par[i]<<endl;
	if (con!=par[i] && par[i]){
		glob++;
	}
	
	return par[i];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m;
	
	int a,b;
	rep(x,0,m){
		cin>>a>>b;
		if (ufds.unions(a,b)){
			al[a].pub(b);
			al[b].pub(a);
		}
	}
	
	dfs(1,-1);
	
	cin>>q;
	while (q--){
		cin>>a>>b;
		
		vector<int> vf={a},vb={b};
		
		while (a!=b){
			if (d[a]>d[b]){
				par[a]^=1;
				a=pp[a];
				if (a!=b){
					vf.pub(a);
				}
			}
			else{
				par[b]^=1;
				b=pp[b];
				if (b!=a){
					vb.pub(b);
				}
			}
		}
		
		reverse(all(vb));
		
		ans.pub(vector<int>());
		for (auto &it:vf) ans.back().pub(it);
		for (auto &it:vb) ans.back().pub(it);
	}
	
	bool can=true;
	rep(x,1,n+1) if (par[x]) can=false;
	
	//rep(x,1,n+1) cout<<par[x]<<" "; cout<<endl;
	
	if (can){
		cout<<"YES"<<endl;
		for (auto &it:ans){
			cout<<sz(it)<<endl;
			for (auto &it2:it) cout<<it2<<" "; cout<<endl;
		}
	}
	else{
		cout<<"NO"<<endl;
		dfs2(1,-1);
		cout<<glob<<endl;
	}
}