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

struct dat{
	int a=0,b=0,c=0;
};

dat merge(dat a,dat b){
	return dat({
		a.a+b.a,
		a.a*b.c+a.b+b.b,
		a.c+b.c
	});
}

struct node{
	int s,e,m,len;
	int val1=0,val2=0;
	dat lazy;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		len=e-s+1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	void propo(){
		if (lazy.a==0 && lazy.b==0 && lazy.c==0) return; //hopefull speedup lol
		
		val1=val1+val2*lazy.a+len*lazy.b;
		val2=val2+len*lazy.c;
		
		if (s!=e){
			l->lazy=merge(lazy,l->lazy); //this order seems correct
			r->lazy=merge(lazy,r->lazy); 
		}
		
		lazy={0,0,0};
	}
	
	void update(int i,int j,dat k){
		propo();
		if (s==i && e==j) lazy=merge(lazy,k);
		else{
			if (j<=m) l->update(i,j,k);
			else if (m<i) r->update(i,j,k);
			else l->update(i,m,k),r->update(m+1,j,k);
			
			l->propo(),r->propo();
			val1=l->val1+r->val1;
			val2=l->val2+r->val2;
		}
	}
	
	int query(int i,int j){
		propo();
		if (s==i && e==j) return val1;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return l->query(i,m)+r->query(m+1,j);
	}
} *root=new node(0,200005);

struct node2{
	int s,e,m;
	ii val;
	node2 *l,*r;
	
	node2 (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		val={0,s};
		
		if (s!=e){
			l=new node2(s,m);
			r=new node2(m+1,e);
		}
	}
	
	void update(int i,int k){
		if (s==e) val.fi=k;
		else{
			if (i<=m) l->update(i,k);
			else r->update(i,k);
			
			val=max(l->val,r->val);
		}
	}
	
	ii query(int i,int j){
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return max(l->query(i,m),r->query(m+1,j));
	}
} *root2=new node2(0,200005);

int n,q;
int arr[200005];
int pos[200005];
vector<int> fac[200005];
vector<iii> upd[200005];
vector<iii> que;

// int lazy[200005];
// int val[200005];

int ans[1000005];

void init(int l,int r){
	if (r<l) return;
	
	int m=root2->query(l,r).se;
	
	vector<ii> v;
	for (auto it:fac[arr[m]]){
		int a=pos[it],b=pos[arr[m]/it];
		
		if (a==b || min(a,b)<l || r<max(a,b)) continue;
		
		v.pub({min({a,b,m}),max({a,b,m})});
	}
	
	sort(all(v),[](ii i,ii j){
		if (i.se!=j.se) return i.se<j.se;
		else return i.fi>j.fi;
	});
	
	// cout<<l<<" "<<m<<" "<<r<<endl;
	// for (auto it:v) cout<<it.fi<<"_"<<it.se<<" "; cout<<endl;
	
	int pp=l-1;
	for (auto it:v){
		if (pp<it.fi){
			upd[it.se].pub(iii(ii(pp+1,it.fi),1));
			pp=it.fi;
		}
	}
	if (pp!=l-1) upd[r+1].pub(iii(ii(l,pp),-1));
	
	init(l,m-1);
	init(m+1,r);
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>q;
	rep(x,1,n+1) cin>>arr[x];
	rep(x,1,n+1) pos[arr[x]]=x;
	
	int a,b;
	rep(x,0,q){
		cin>>a>>b;
		que.pub(iii(ii(a,b),x));
	}
	
	rep(x,1,n+1){
		for (int y=x;y<=n;y+=x) fac[y].pub(x);
	}
	
	rep(x,1,n+1) root2->update(x,arr[x]);
	
	init(1,n);
	
	sort(all(que),[](iii i,iii j){
		return i.fi.se<j.fi.se;
	});
	
	int curr=0;
	for (auto it:que){
		//cout<<"proc: "<<it.fi.fi<<" "<<it.fi.se<<" "<<it.se<<endl;
		while (curr<it.fi.se){
			curr++;
			for (auto it2:upd[curr]){
				//cout<<curr<<" "<<it2.fi.fi<<" "<<it2.fi.se<<" "<<it2.se<<endl;
				root->update(it2.fi.fi,it2.fi.se,{0,0,it2.se});
				//rep(x,it2.fi.fi,it2.fi.se+1) lazy[x]+=it2.se;
			}
			root->update(0,200005,{1,0,0});
			//rep(x,1,6) cout<<root->query(x,x)<<" "; cout<<endl;
			//rep(x,1,n+1) val[x]+=lazy[x];
		}
		
		ans[it.se]=root->query(it.fi.fi,it.fi.se);
		//rep(x,it.fi.fi,it.fi.se+1) ans[it.se]+=val[x];
	}
	
	rep(x,0,q) cout<<ans[x]<<endl;
}