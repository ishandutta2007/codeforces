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
#define ii pair<int,int>
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

struct fen{
	int arr[200005];
	
	void update(int i,int j){
		while (i<200005){
			arr[i]+=j;
			i+=i&-i;
		}
	}
	
	int query(int i){
		int res=0;
		while (i){
			res+=arr[i];
			i-=i&-i;
		}
		return res;
	}
} fen1,fen2;

struct node{
	int s,e,m;
	int val=0,lazy=0;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	void propo(){
		if (lazy==0) return;
		
		val+=lazy;
		if (s!=e){
			l->lazy+=lazy;
			r->lazy+=lazy;
		}
		lazy=0;
	}
	
	void update(int i,int j,int k){
		if (i>j) return;
		if (s==i && e==j) lazy+=k;
		else{
			if (j<=m) l->update(i,j,k);
			else if (m<i) r->update(i,j,k);
			else l->update(i,m,k),r->update(m+1,j,k);
			
			l->propo(),r->propo();
			val=min(l->val,r->val);
		}
	}
	
	int find(int i,int j){
		if (i>j) return -1;
		propo();
		if (val>0) return -1;
		if (s==e) return s;
		if (j<=m) return l->find(i,j);
		else if (m<i) return r->find(i,j);
		else{
			int temp=l->find(i,m);
			if (temp!=-1) return temp;
			else return r->find(m+1,j);
		}
	}
} *root1=new node(0,200005),*root2=new node(0,200005);

int n;
int l[100005];
int d[100005];
int r[100005];
int u[100005];

vector<set<int> > v;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,0,n) cin>>l[x]>>d[x]>>r[x]>>u[x];
	
	//coordinate compression on everything first
	vector<int> uni={-1};
	rep(x,0,n) uni.pub(l[x]),uni.pub(r[x]);
	sort(all(uni));
	rep(x,0,n) l[x]=lb(all(uni),l[x])-uni.begin();
	rep(x,0,n) r[x]=lb(all(uni),r[x])-uni.begin();
	
	uni={-1};
	rep(x,0,n) uni.pub(d[x]),uni.pub(u[x]);
	sort(all(uni));
	rep(x,0,n) d[x]=lb(all(uni),d[x])-uni.begin();
	rep(x,0,n) u[x]=lb(all(uni),u[x])-uni.begin();
	
	set<int> s;
	rep(x,0,n) s.insert(x);
	v.pub(s);
	
	while (!v.empty()){
		s=v.back(); v.pob();
		//cout<<sz(s)<<endl;
		if (sz(s)==1) continue;
		
		set<ii> L,D;
		set<ii,greater<ii> > R,U;
		for (auto it:s){
			L.insert({l[it],it});
			D.insert({d[it],it});
			R.insert({r[it],it});
			U.insert({u[it],it});
			
			root1->update(l[it]+1,r[it]-1,1);
			root2->update(d[it]+1,u[it]-1,1);
			fen1.update(l[it],1);
			fen2.update(d[it],1);
		}
		
		while (!s.empty()){
			set<int> rem;
			
			if (sz(s)==1){
				rem=s;
			}
			else if (root1->find((*L.begin()).fi+1,(*R.begin()).fi-1)!=-1){
				int temp=root1->find((*L.begin()).fi+1,(*R.begin()).fi-1);
				
				if (fen1.query(temp-1)<=sz(s)/2){ //remove left
					auto it=L.begin();
					while ((*it).fi<temp){
						rem.insert((*it).se);
						it=next(it);
					}
				}
				else{ //remove right
					auto it=R.begin();
					while ((*it).fi>temp){
						rem.insert((*it).se);
						it=next(it);
					}
				}
			}
			else if (root2->find((*D.begin()).fi+1,(*U.begin()).fi-1)!=-1){
				int temp=root2->find((*D.begin()).fi+1,(*U.begin()).fi-1);
				
				if (fen2.query(temp-1)<=sz(s)/2){ //remove down
					auto it=D.begin();
					while ((*it).fi<temp){
						rem.insert((*it).se);
						it=next(it);
					}
				}
				else{ //remove up
					auto it=U.begin();
					while ((*it).fi>temp){
						rem.insert((*it).se);
						it=next(it);
					}
				}
			}
			else{
				cout<<"NO"<<endl;
				return 0;
			}
			
			for (auto it:rem){
				s.erase(it);
				L.erase({l[it],it});
				D.erase({d[it],it});
				R.erase({r[it],it});
				U.erase({u[it],it});
				
				root1->update(l[it]+1,r[it]-1,-1);
				root2->update(d[it]+1,u[it]-1,-1);
				fen1.update(l[it],-1);
				fen2.update(d[it],-1);
			}
			
			v.pub(rem);
		}
	}
	
	cout<<"YES"<<endl;
}