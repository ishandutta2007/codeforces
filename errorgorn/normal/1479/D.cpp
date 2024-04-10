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

struct node{
	int s,e,m;
	ll val=0;
	node *l,*r;
	
	node(int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	node(node *i){
		s=i->s,e=i->e,m=i->m;
		val=i->val;
		l=i->l,r=i->r;
	}
	
	void update(int i,ll k){
		val^=k;
		
		if (s==e) return;
		if (i<=m){
			l=new node(l);
			l->update(i,k);
		}
		else{
			r=new node(r);
			r->update(i,k);
		}
	}
	
	ll query(int i){
		if (s==e) return val;
		else if (i<=m) return l->query(i);
		else return r->query(i);
	}
} *root[300005];

int n,q;
int arr[300005];
vector<int> al[300005];

ll hh[300005];
int d[300005];
int tkd[300005][20];

void dfs(int i,int p){
	root[i]->update(arr[i],hh[arr[i]]);
	
	for (auto &it:al[i]){
		if (it==p) continue;
		
		d[it]=d[i]+1;
		int curr=tkd[it][0]=i;
		rep(x,0,20){
			if (curr==-1) break;
			curr=tkd[it][x+1]=tkd[curr][x];
		}
		
		root[it]=new node(root[i]);
		dfs(it,i);
	}
}

int mov(int i,int j){
	rep(x,0,20) if (j&(1<<x)) i=tkd[i][x];
	return i;
}

int lca(int i,int j){
	if (d[i]<d[j]) swap(i,j);
	i=mov(i,d[i]-d[j]);
	if (i==j) return i;
	
	rep(x,20,0) if (tkd[i][x]!=tkd[j][x]) i=tkd[i][x],j=tkd[j][x];
	return tkd[i][0];
}

ll cost(int l,int r,int i){
	if (l<=arr[i] && arr[i]<=r) return hh[arr[i]];
	else return 0;
}

int search(node *a,node *b,int l,int r,int i){
	if ((a->val^b->val^cost(a->s,a->e,i))==0) return -1;
	
	if (a->s==a->e) return l;
	
	if (r<=a->m) return search(a->l,b->l,l,r,i);
	else if (a->m<l) return search(a->r,b->r,l,r,i);
	else{
		int temp=search(a->l,b->l,l,a->m,i);
		if (temp==-1) return search(a->r,b->r,a->m+1,r,i);
		else return temp;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	rep(x,0,300005) hh[x]=rng();
	
	cin>>n>>q;
	rep(x,1,n+1) cin>>arr[x];
	
	int a,b,c,d;
	rep(x,1,n){
		cin>>a>>b;
		
		al[a].pub(b);
		al[b].pub(a);
	}
	
	root[1]=new node(0,300005);
	memset(tkd,-1,sizeof(tkd));
	dfs(1,-1);
	
	while (q--){
		cin>>a>>b>>c>>d;
		
		//cout<<a<<" "<<b<<" "<<lca(a,b)<<endl;
		
		cout<<search(root[a],root[b],c,d,lca(a,b))<<endl;
	}
}