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

mt19937 rng(128705);

const int SQRTN=300;

int n,m,q;
vector<ii> edges[100005];
vector<ii> qq[100005];
vector<ii> qu;

map<ii,int> id;
int pos[100005];

int ans[100005];

int p[100005];

int find(int i){
	if (p[i]==i) return i;
	else return find(p[i]);
}

void unions(int i,int j){
	i=find(i),j=find(j);
	
	if (i==j) return;
	p[j]=i;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	rep(x,0,100005) p[x]=x;
	
	cin>>n>>m;
	
	int a,b,c;
	rep(x,0,m){
		cin>>a>>b>>c;
		edges[c].push_back(ii(a,b));
	}
	
	cin>>q;
	rep(x,0,q){
		cin>>a>>b;
		if (a>b) swap(a,b);
		
		if (!id.count(ii(a,b))) id[ii(a,b)]=x;
		pos[x]=id[ii(a,b)];
		
		qq[a].push_back(ii(b,x));
		qu.push_back(ii(a,b));
	}
	
	rep(x,0,100005) sort(all(qq[x]));
	
	rep(col,0,100005) if (sz(edges[col])){
		vector<int> vertices;
		for (auto &it:edges[col]){
			unions(it.fi,it.se);
			vertices.push_back(it.fi);
			vertices.push_back(it.se);
		}
		
		sort(all(vertices));
		vertices.erase(unique(all(vertices)),vertices.end());
		
		if (sz(edges[col])<=SQRTN){
			rep(x,0,sz(vertices)){
				rep(y,x+1,sz(vertices)){
					int u=vertices[x],v=vertices[y];
					
					if (find(u)!=find(v)) continue;
					
					auto temp=lower_bound(all(qq[u]),ii(v,0));
					if (temp==qq[u].end() || (*temp).fi!=v) continue;
					
					ans[(*temp).se]++;
				}
			}
		}
		else{
			rep(x,0,sz(qu)){
				if (find(qu[x].fi)==find(qu[x].se)){
					ans[x]++;
				}
			}
		}
		
		for (auto &it:vertices) p[it]=it;
	}
	
	rep(x,0,q) cout<<ans[pos[x]]<<endl;
}