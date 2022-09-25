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

struct UFDS{
	int p[100005];
	int s[100005];
	int par[100005];
	vector<ii> ops;
	
	UFDS(){
		rep(x,0,100005){
			p[x]=x;
			s[x]=1;
			par[x]=0;
		}
	}
	
	ii find(int i){
		if (i==p[i]) return ii(i,0);
		else{
			auto temp=find(p[i]);
			return ii(temp.fi,temp.se^par[i]);
		}
	}
	
	bool unions(int i,int j){
		ii vi=find(i),vj=find(j);
		
		if (vi.fi==vj.fi) return vi.se==vj.se;
		
		if (s[vi.fi]<s[vj.fi]) swap(vi,vj);
		p[vj.fi]=vi.fi;
		par[vj.fi]=vi.se^vj.se^1;
		s[vi.fi]+=s[vj.fi];
		
		ops.push_back(ii(vi.fi,vj.fi));
		
		return false;
	}
	
	void roll(int ss){
		while (sz(ops)!=ss){
			p[ops.back().se]=ops.back().se;
			s[ops.back().fi]-=s[ops.back().se];
			ops.pop_back();
		}
	}
} ufds;

int n,q;
map<ii,int> m;
int ans[100010];

struct node{
	int s,e,m;
	vector<ii> edges;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	void update(int i,int j,ii k){
		if (s==i && e==j) edges.push_back(k);
		else if (j<=m) l->update(i,j,k);
		else if (m<i) r->update(i,j,k);
		else l->update(i,m,k),r->update(m+1,j,k);
	}
	
	void dfs(){
		bool ok=true;
		int curr=sz(ufds.ops);
		
		for (auto &it:edges){
			if (ufds.unions(it.fi,it.se)){
				ok=false;
				break;
			}
		}
		
		if (!ok){
			rep(x,s,e+1) ans[x]=true;
		}
		else if (s==e){
			ans[s]=false;
		}
		else{
			l->dfs();
			r->dfs();
		}
		
		ufds.roll(curr);
	}
} *root=new node(0,100005);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>q;
	
	int a,b;
	rep(x,0,q){
		cin>>a>>b;
		if (a>b) swap(a,b);
		
		if (m.count(ii(a,b))){
			root->update(m[ii(a,b)],x-1,ii(a,b));
			m.erase(ii(a,b));
		}
		else{
			m[ii(a,b)]=x;
		}
	}
	
	for (auto &it:m){
		root->update(it.se,100005,it.fi);
	}
	
	root->dfs();
	
	rep(x,0,q){
		if (ans[x]) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;	
	}
}