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

#define ii pair<int,int>
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

struct FEN{
	int fen[500005];
	
	FEN(){
		memset(fen,0,sizeof(fen));
	}
	
	void upd(int i,int j){
		while (i<500005){
			fen[i]+=j;
			i+=i&-i;
		}
	}
	
	int query(int i){
		int res=0;
		while (i){
			res+=fen[i];
			i-=i&-i;
		}
		return res;
	}
} fval,fidx;

struct dat{
	struct node{
		ii val[1<<20];
		int lazy[1<<20];
		
		node(){
			rep(x,0,1<<20) val[x]={1e9,-1};
		}
		
		void propo(int u,int s,int e){
			if (lazy[u]==0) return;
			
			val[u].fi+=lazy[u];
			if (s!=e){
				lazy[u<<1]+=lazy[u];
				lazy[u<<1|1]+=lazy[u];
			}
			lazy[u]=0;
		}
		
		void update(int i,int j,int k,int u=1,int s=0,int e=(1<<19)-1){
			if (s==i && e==j) lazy[u]+=k;
			else{
				int m=s+e>>1;
				if (j<=m) update(i,j,k,u<<1,s,m);
				else if (m<i) update(i,j,k,u<<1|1,m+1,e);
				else update(i,m,k,u<<1,s,m),update(m+1,j,k,u<<1|1,m+1,e);
				
				propo(u<<1,s,m),propo(u<<1|1,m+1,e);
				val[u]=min(val[u<<1],val[u<<1|1]);
			}
		}
		
		void set(int i,int k,int u=1,int s=0,int e=(1<<19)-1){
			propo(u,s,e);
			if (s==e) val[u]={k,s};
			else{
				int m=s+e>>1;
				if (i<=m) set(i,k,u<<1,s,m);
				else set(i,k,u<<1|1,m+1,e);
				
				propo(u<<1,s,m),propo(u<<1|1,m+1,e);
				val[u]=min(val[u<<1],val[u<<1|1]);
			}
		}
	} root;
	
	struct node2{
		int val[1<<20];
		
		node2(){
			rep(x,0,1<<20) val[x]=-1e9;
		}
		
		void update(int i,int k,int u=1,int s=0,int e=(1<<19)-1){
			if (s==e) val[u]=k;
			else{
				int m=s+e>>1;
				if (i<=m) update(i,k,u<<1,s,m);
				else update(i,k,u<<1|1,m+1,e);
				
				val[u]=max(val[u<<1],val[u<<1|1]);
			}
		}
		
		ii query(int i,int key,int u=1,int s=0,int e=(1<<19)-1){ //find key<=val where i<=s
			if (e<i || val[u]<key) return {-1,-1};
			if (s==e) return {s,val[u]};
			else{
				int m=s+e>>1;
				
				auto temp=query(i,key,u<<1,s,m);
				if (temp!=ii(-1,-1)) return temp;
				else return query(i,key,u<<1|1,m+1,e);
			}
		}
	} root2;
	
	set<ii> s={ {500005,500005} };
	
	//root stores the values of each pair
	//root2 stores the left endpoint of each pair to add non-overlapping ranges
	//s stores the pairs are still alive so its easy to do searches
	
	dat *d; //we also store the other guy
	bool orien; //false for i->arr[i]
	
	int pp[500005];
	
	void push(int i,int j){
		pp[j]=i;
		root2.update(j,i);
	}
	
	void add(int i,int j){
		root2.update(j,-1e9);
		s.insert({i,j});
		
		int val;
		if (!orien) val=fval.query(j)-fidx.query(i);
		else val=fidx.query(j)-fval.query(i);
		
		root.set(j,val);
	}
	
	void del(int j){
		ii curr={-1,-1};
		int lim=500005;
		
		if (j!=-1){
			int i=pp[j];
			
			auto it=d->s.ub({j,1e9});
			d->root.update(i,(*it).se-1,-1);
			
			if (!orien) fidx.upd(i,-1),fval.upd(j,-1);
			else fval.upd(i,-1),fidx.upd(j,-1);
			
			it=s.find({i,j});
			if (it!=s.begin()) curr=*prev(it);
			lim=(*next(it)).se;
			s.erase(it);
			root.set(j,1e9);
			root2.update(j,-1e9);
		}
		
		while (true){
			auto temp=root2.query(curr.se,curr.fi);
			swap(temp.fi,temp.se);
			if (temp==ii(-1,-1) || lim<=temp.se) break;
			
			add(temp.fi,temp.se);
			curr=temp;
		}
	}
} l=dat(),r=dat();

int n;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	//cyclic mapping to each other
	l.d=&r;
	r.d=&l;
	
	r.orien=true;
	
	cin>>n;
	rep(x,1,n+1){
		int y;
		cin>>y;
		
		if (x<=y) l.push(x,y);
		else r.push(y,x);
	}
	
	rep(x,1,n+1) fidx.upd(x,1),fval.upd(x,1);
	l.del(-1);
	r.del(-1);
	
	int ans=0;
	
	rep(x,0,n){
		if (l.root.val[1].fi<=r.root.val[1].fi){
			ans=max(ans,l.root.val[1].fi);
			l.del(l.root.val[1].se);
		}
		else{
			ans=max(ans,r.root.val[1].fi);
			r.del(r.root.val[1].se);
		}
	}
	
	cout<<ans<<endl;
}