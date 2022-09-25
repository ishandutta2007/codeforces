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
#define debug(x) cout << #x << " is " << x << endl;

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,q;
vector<ii> al[200005];
ll w[200005];

int pa[200005];
int id[200005];
int d[200005];

void dfs(int i,int p){
	for (auto &it:al[i]){
		if (it.fi==p) continue;
		
		pa[it.fi]=i;
		id[it.fi]=it.se;
		d[it.fi]=d[i]+1;
		dfs(it.fi,i);
	}
}

int p[200005];
int find(int i){
	if (p[i]==i) return i;
	else return p[i]=find(p[i]);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	rep(x,0,200005) p[x]=x;
	
	cin>>n>>q;
	
	ll a,b,c;
	rep(x,1,n){
		cin>>a>>b>>c;
		al[a].push_back(ii(b,x));
		al[b].push_back(ii(a,x));
		w[x]=c;
	}
	
	dfs(1,-1);
	
	while (q--){
		cin>>a;
		
		if (a==1){
			cin>>a>>b>>c;
			a=find(a),b=find(b);
			
			while (a!=b && c){
				if (d[a]<d[b]) swap(a,b);
				
				if (w[id[a]]==1){
					p[a]=pa[a];
					a=find(a);
				}
				else{
					c/=w[id[a]];
					a=find(pa[a]);
				}
			}
			
			cout<<c<<endl;
		}
		else{
			cin>>a>>b;
			w[a]=b;
		}
	}
}