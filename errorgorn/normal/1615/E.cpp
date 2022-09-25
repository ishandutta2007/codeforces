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
	ii val;
	ll lazy=0;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		val={0,s};
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	void propo(){
		if (lazy){
			val.fi+=lazy;
			
			if (s!=e){
				l->lazy+=lazy;
				r->lazy+=lazy;
			}
			lazy=0;
		}
	}
	
	void update(int i,int j,ll k){
		if (s==i && e==j) lazy+=k;
		else{
			if (j<=m) l->update(i,j,k);
			else if (m<i) r->update(i,j,k);
			else l->update(i,m,k),r->update(m+1,j,k);
			
			l->propo(),r->propo();
			val=max(l->val,r->val);
		}
	}
} *root=new node(0,200005);

ll n,k;

ll TIME=0;
int pp[200005];
int in[200005];
int out[200005];
int d[200005];
bool leaf[200005];

bool vis[200005];

vector<int> al[200005];

vector<int> leaves={-1};

void dfs(int i,int p){
	leaf[i]=true;
	
	for (auto &it:al[i]){
		if (it==p) continue;
		
		leaf[i]=false;
		d[it]=d[i]+1;
		pp[it]=i;
		dfs(it,i);
		if (!in[i]) in[i]=in[it];
		out[i]=out[it];
	}
	
	if (leaf[i]){
		leaves.pub(i);
		in[i]=out[i]=++TIME;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>k;
	
	int a,b;
	rep(x,1,n){
		cin>>a>>b;
		al[a].pub(b);
		al[b].pub(a);
	}
	
	d[1]=1;
	dfs(1,-1);
	
	//rep(x,1,n+1) cout<<in[x]<<" "<<out[x]<<endl;
	
	rep(x,1,n+1) if (leaf[x]){
		root->update(in[x],out[x],d[x]);
		//cout<<in[x]<<" "<<d[x]<<endl;
	}
	
	if (k>=TIME){
		k=max(min(k,n/2),TIME); //BRUH MOMENT
		cout<<k*(n-k)<<endl;
		return 0;
	}
	
	ll w=n;
	
	rep(x,0,k){
		auto temp=root->val;
		int curr=leaves[temp.se];
		
		w-=temp.fi;
		while (true){
			root->update(in[curr],out[curr],-1);
			vis[curr]=true;
			
			if (curr==1 || vis[pp[curr]]) break;
			curr=pp[curr];
		}
	}
	
	//cout<<w<<" "<<k<<endl;
	
	ll blue=min(w,n/2);
	cout<<(n-k-blue)*(k-blue)<<endl;
}