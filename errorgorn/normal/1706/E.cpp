//
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

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

struct node{
	int s,e,m;
	ii val={0,0};
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	ii merge(ii i,ii j){
		return {
			min(i.fi,j.fi),
			max(i.se,j.se)
		};
	}
	
	void update(int i,int k){
		if (s==e) val={k,k};
		else{
			if (i<=m) l->update(i,k);
			else r->update(i,k);
			val=merge(l->val,r->val);
		}
	}
	
	ii query(int i,int j){
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return merge(l->query(i,m),r->query(m+1,j));
	}
} *root=new node(0,100005);

int n,m,q;
int tkd[200005][20];
int w[200005];
ii range[200005];
vector<int> al[200005];

int p[200005];
int par(int i){
	if (p[i]==i) return i;
	else return p[i]=par(p[i]);
}

int _TIME;

void dfs(int i){
	if (i<=n){
		range[i]={_TIME,_TIME};
		root->update(i,_TIME++);
	}
	else{
		for (auto it:al[i]){
			int curr=tkd[it][0]=i;
			rep(x,0,19){
				if (curr==-1) break;
				curr=tkd[it][x+1]=tkd[curr][x];
			}
			dfs(it);
			
			if (it==al[i][0]) range[i].fi=range[it].fi;
			else range[i].se=range[it].se;
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
		cin>>n>>m>>q;
		
		rep(x,1,2*n+1) rep(y,0,20) tkd[x][y]=-1;
		rep(x,1,2*n+1) p[x]=x;
		int IDX=n;
		
		int a,b;
		rep(x,1,m+1){
			cin>>a>>b;
			a=par(a),b=par(b);
			if (a!=b){
				IDX++;
				w[IDX]=x;
				al[IDX]={a,b};
				p[a]=p[b]=IDX;
			}
		}
		
		_TIME=1;
		dfs(IDX);
		
		// rep(x,1,IDX+1) cout<<range[x].fi<<" "<<range[x].se<<" "<<w[x]<<endl;
		// cout<<endl;
		
		while (q--){
			cin>>a>>b;
			if (a==b){
				cout<<0<<" ";
				continue;
			}
			
			int curr=a;
			tie(a,b)=root->query(a,b);
			
			int ans=0;
			rep(x,20,0) if (tkd[curr][x]!=-1 && (a<range[tkd[curr][x]].fi || range[tkd[curr][x]].se<b)){
				ans+=1<<x;
				curr=tkd[curr][x];
			}
			
			cout<<w[tkd[curr][0]]<<" ";
		}
		cout<<endl;
	}
}