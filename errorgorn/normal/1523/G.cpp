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
#define ii pair<int,int>
#define iii pair<int,ii>
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

const iii INF=iii(1e9,ii(-1,-1));

int n,m;
ii arr[100005];
vector<int> proc;

ii lca(int s,int e,int l,int r){
	int m=s+e>>1;
	if (l<=m && m<r) return ii(s,e);
	else if (r<=m) return lca(s,m,l,r);
	else return lca(m+1,e,l,r);
}

struct node{
	int s,e,m;
	iii val=INF;
	node *l=nullptr,*r=nullptr;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
	}
	
	bool inside(int i){
		return s<=i && i<=e;
	}
	
	void update(int i,iii k){
		if (s==e) val=min(val,k);
		else{
			if (i<=m){
				if (l==nullptr) l=new node(i,i);
				else if (!l->inside(i)){
					ii temp;
					if (l->e < i){
						temp=lca(s,e,l->e,i);
						auto c=l;
						l=new node(temp.fi,temp.se); 
						l->l=c;
					}
					else{
						temp=lca(s,e,i,l->s);
						auto c=l;
						l=new node(temp.fi,temp.se); 
						l->r=c;
					}
				}
				l->update(i,k);
			}
			else{
				if (r==nullptr) r=new node(i,i);
				else if (!r->inside(i)){
					ii temp;
					if (r->e < i){
						temp=lca(s,e,r->e,i);
						auto c=r;
						r=new node(temp.fi,temp.se);
						r->l=c;
					}
					else{
						temp=lca(s,e,i,r->s);
						auto c=r;
						r=new node(temp.fi,temp.se);
						r->r=c;
					}
					 
				}
				r->update(i,k);
			}
			
			val=min((l==nullptr?INF:l->val),(r==nullptr?INF:r->val));
		}
	}
	
	iii query(int i,int j){
		if (i<=s && e<=j) return val;
		else if (j<=m) return (l==nullptr?INF:l->query(i,j));
		else if (m<i) return (r==nullptr?INF:r->query(i,j));
		else return min((l==nullptr?INF:l->query(i,m)),(r==nullptr?INF:r->query(m+1,j)));
	}
};

struct node2{
	node *val=new node(0,100005);
	node2 *l,*r;
	
	node2 (int s,int e){
		int m=s+e>>1;
		
		if (s!=e){
			l=new node2(s,m);
			r=new node2(m+1,e);
		}
	}
	
	void update(int i1,int i2,iii k,int s=0,int e=100005){
		int m=s+e>>1;
		
		val->update(i2,k);
		if (s==e) return;
		if (i1<=m) l->update(i1,i2,k,s,m);
		else r->update(i1,i2,k,m+1,e);
	}
	
	iii query(int i1,int j1,int i2,int j2,int s=0,int e=100005){
		int m=s+e>>1;
		
		if (s==i1 && e==j1) return val->query(i2,j2);
		else if (j1<=m) return l->query(i1,j1,i2,j2,s,m);
		else if (m<i1) return r->query(i1,j1,i2,j2,m+1,e);
		else return min(l->query(i1,m,i2,j2,s,m),r->query(m+1,j1,i2,j2,m+1,e));
	}
} *root=new node2(0,100005);

int rec(int l,int r){
	if (r<l) return 0;
	
	auto temp=root->query(l,r,l,r);
	
	if (temp.fi==1e9) return 0;
	else return (temp.se.se-temp.se.fi+1)+rec(l,temp.se.fi-1)+rec(temp.se.se+1,r);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m;
	rep(x,0,m){
		cin>>arr[x].fi>>arr[x].se;
	}
	rep(x,0,m) proc.pub(x);
	
	sort(all(proc),[](int i,int j){
		return arr[i].se-arr[i].fi<arr[j].se-arr[j].fi;
	});
	
	vector<int> ans;
	
	int p=0;
	rep(x,n+1,1){
		bool change=false;
		while (!proc.empty() && arr[proc.back()].se-arr[proc.back()].fi+1==x){
			int u=proc.back();
			root->update(arr[u].fi,arr[u].se,iii(u,arr[u]));
			proc.pob();
			change=true;
		}
        
		ans.pub(rec(1,n));
	}
	
	reverse(all(ans));
	for (auto &it:ans) cout<<it<<" "; cout<<endl;
}