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

const ll INF=1e18;

struct node{
	int s,e,m;
	ll sum;
	ll max1,max2,max_cnt;
	ll min1,min2,min_cnt;
	ll lazy_sum,lazy_max,lazy_min;
	node *l,*r;
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
			upd();
		}
		else{
			sum=2e9;
			max1=2e9,max2=-INF,max_cnt=1;
			min1=2e9,min2=INF,min_cnt=1;
		}
		
		lazy_sum=0;
		lazy_max=-INF;
		lazy_min=INF;
	}
	void propo(){ //propogate lazy tags to children (cfm exists)
		if (lazy_sum!=0) l->push_sum(lazy_sum),r->push_sum(lazy_sum);
		if (lazy_max!=-INF) l->push_max(lazy_max),r->push_max(lazy_max);
		if (lazy_min!=INF) l->push_min(lazy_min),r->push_min(lazy_min);
		lazy_sum=0,lazy_max=-INF,lazy_min=INF;
	}
	
	void upd(){ //update details based on children (cfm exists)
		sum=l->sum+r->sum;
		
		if (l->max1==r->max1){
			max1=l->max1;
			max_cnt=l->max_cnt+r->max_cnt;
			max2=max(l->max2,r->max2);
		}
		else if (l->max1>r->max1){
			max1=l->max1;
			max_cnt=l->max_cnt;
			max2=max(l->max2,r->max1);
		}
		else{
			max1=r->max1;
			max_cnt=r->max_cnt;
			max2=max(r->max2,l->max1);
		}
		
		if (l->min1==r->min1){
			min1=l->min1;
			min_cnt=l->min_cnt+r->min_cnt;
			min2=min(l->min2,r->min2);
		}
		else if (l->min1<r->min1){
			min1=l->min1;
			min_cnt=l->min_cnt;
			min2=min(l->min2,r->min1);
		}
		else{
			min1=r->min1;
			min_cnt=r->min_cnt;
			min2=min(r->min2,l->min1);
		}
	}
	
	void push_sum(ll k){
		sum+=(e-s+1)*k;
		
		max1+=k;
		if (max2!=-INF) max2+=k;
		if (lazy_max!=-INF) lazy_max+=k;
		min1+=k;
		if (min2!=INF) min2+=k;
		if (lazy_min!=INF) lazy_min+=k;
		lazy_sum+=k;
	}
	
	void push_max(ll k){ //we are garaunteed that max_cnt does not change
		if (k<=min1) return;
		
		sum+=(k-min1)*min_cnt;
		if (max2==min1) max2=k;
		if (max1==min1) max1=k;
		min1=k;
		if (lazy_min<k) lazy_min=k; //dont forget
		lazy_max=k;
	}
	
	void push_min(ll k){ //we are garaunteed that min_cnt does not change
		if (max1<=k) return;
		
		sum-=(max1-k)*max_cnt;
		if (min2==max1) min2=k;
		if (min1==max1) min1=k;
		max1=k;
		if (lazy_max>k) lazy_max=k; //dont forget
		lazy_min=k;
	}
	void update_sum(int i,int j,ll k){
		if (s==i && e==j){ //dont need to propogate
			push_sum(k);
		}
		else{
			propo();
		
			if (j<=m) l->update_sum(i,j,k);
			else if (m<i) r->update_sum(i,j,k);
			else l->update_sum(i,m,k),r->update_sum(m+1,j,k);
			
			upd();
		}
	}
	
	void update_max(int i,int j,ll k){
		if (k<=min1) return;
		else if (s==i && e==j && k<min2){ //dont need to propogate
			push_max(k);
		}
		else{
			propo();
		
			if (j<=m) l->update_max(i,j,k);
			else if (m<i) r->update_max(i,j,k);
			else l->update_max(i,m,k),r->update_max(m+1,j,k);
			
			upd();
		}
	}
	
	void update_min(int i,int j,ll k){
		if (max1<=k) return;
		else if (s==i && e==j && max2<k){ //dont need to propogate
			push_min(k);
		}
		else{
			propo();
		
			if (j<=m) l->update_min(i,j,k);
			else if (m<i) r->update_min(i,j,k);
			else l->update_min(i,m,k),r->update_min(m+1,j,k);
			
			upd();
		}
	}
	
	ll query_sum(int i,int j){
		if (s==i && e==j) return sum;
		else{
			propo();
			if (j<=m) return l->query_sum(i,j);
			else if (m<i) return r->query_sum(i,j);
			else return l->query_sum(i,m)+r->query_sum(m+1,j);
		}
	}
	ll query_max(int i,int j){
		if (s==i && e==j) return max1;
		else{
			propo();
			if (j<=m) return l->query_max(i,j);
			else if (m<i) return r->query_max(i,j);
			else return max(l->query_max(i,m),r->query_max(m+1,j));
		}
	}
	ll query_min(int i,int j){
		if (s==i && e==j) return min1;
		else{
			propo();
			if (j<=m) return l->query_min(i,j);
			else if (m<i) return r->query_min(i,j);
			else return min(l->query_min(i,m),r->query_min(m+1,j));
		}
	}
}*root=new node(0,300005);

struct node2{
	int s,e,m;
	int val=2e9;
	node2 *l,*r;
	
	node2 (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node2(s,m);
			r=new node2(m+1,e);
		}
	}
	
	void update(int i,int k){
		if (s==e) val=k;
		else{
			if (i<=m) l->update(i,k);
			else r->update(i,k);
			val=min(l->val,r->val);
		}
	}
	
	int query(int i,int j){
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return min(l->query(i,m),r->query(m+1,j));
	}
} *root2=new node2(0,300005);

int n,q,k;
int arr[300005];
int id[300005];
int last[300005];

struct Q{
	int l,r;
	int idx;
};

vector<Q> qu;

int ans[300005];

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>q>>k;
	rep(x,1,n+1) cin>>arr[x];
	rep(x,1,n+1) root2->update(x,arr[x]);
	
	int IDX=0;
	rep(x,1,k+1){
		for (int y=x;y<=n;y+=k) id[y]=IDX++;
		for (int y=x;y<=n;y+=k) last[y]=IDX-1;
	}
	
	int a,b;
	rep(x,0,q){
		cin>>a>>b;
		qu.pub(Q({a,b,x}));
	}
	
	sort(all(qu),[](Q i,Q j){
		return i.l<j.l;
	});
	
	//rep(x,1,n+1) cout<<id[x]<<" "; cout<<endl;
	
	int curr=n+1;
	while (!qu.empty()){
		while (curr!=qu.back().l){
			curr--;
			root->update_min(id[curr],id[curr],arr[curr]);
			if (id[curr]!=last[curr]) root->update_min(id[curr]+1,last[curr],root2->query(curr,min(curr+k,300005LL)));
		}
		
		int len=(qu.back().r-qu.back().l)/k;
		
		//cout<<qu.back().l<<" "<<qu.back().r<<" "<<len<<endl;
		
		ans[qu.back().idx]=root->query_sum(id[curr],id[curr]+len);
		
		qu.pob();
	}
	
	rep(x,0,q) cout<<ans[x]<<endl;
}