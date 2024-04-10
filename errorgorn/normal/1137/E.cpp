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

#define ld long double
#define di pair<ld,int>

const ld EPS=1e-13;
const ld INF=1e100;

struct node{
	int s,e,m;
	di val=di(-INF,0);
	ld lazy=0;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		val.se=s;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	void propo(){
		if (lazy!=0){
			val.fi+=lazy;
			
			if (s!=e){
				l->lazy+=lazy;
				r->lazy+=lazy;
			}
			lazy=0;
		}
	}
	
	void update(int i,int j,ld k){
		if (s==i && e==j) lazy+=k;
		else{
			if (j<=m) l->update(i,j,k);
			else if (m<i) r->update(i,j,k);
			else l->update(i,m,k),r->update(m+1,j,k);
			
			l->propo(),r->propo();
			val=max(l->val,r->val);
		}
		
		propo();
	}
	
	void update2(int i,ld k){
		propo();
		
		if (s==e) val.fi=k;
		else{
			if (i<=m) l->update2(i,k);
			else r->update2(i,k);
			
			l->propo(),r->propo();
			val=max(l->val,r->val);
		}
	}
} *root=new node(0,600010);

const int RS=1e9+5;
struct node2{
	int s,e,m;
	ll val=0,lazy=0;
	node2 *l=nullptr,*r=nullptr;
	
	node2(int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
	}
	
	void make(){
		if (l==nullptr){
			l=new node2(s,m);
			r=new node2(m+1,e);
		}
	}
	
	void propo(){
		if (lazy){
			val+=lazy*(e-s+1);
			
			make();
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
			make();
			
			if (j<=m) l->update(i,j,k);
			else if (m<i) r->update(i,j,k);
			else l->update(i,m,k),r->update(m+1,j,k);
			
			l->propo(),r->propo();
			val=l->val+r->val;
		}
	}
	
	ll query(int i,int j){
		propo();
		
		if (s==i && e==j) return val;
		else{
			make();
			if (j<=m) return l->query(i,j);
			else if (m<i) return r->query(i,j);
			else return l->query(i,m)+r->query(m+1,j);
		}
	}
} *root2=new node2(-RS,RS);

int n,q;
int dll[600010];
int dlr[600010];
int pos[600010];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>q;
	
	//we maintain the first and last value
	//then implictly maintain the diff
	
	int l=1,r=n;
	int l2=300005,r2=300005;
	
	dlr[l2]=0;
	dll[0]=l2;
	pos[l2]=l;
	
	ll a,b;
	rep(x,0,q){
		cin>>a;
		
		if (a==1){
			cin>>a;
			
			l-=a;
			l2--;
			pos[l2]=l;
			
			int temp=l2+1;
			
			ll val=root2->query(-RS,pos[temp]);
			ll val2=root2->query(-RS,pos[l2]);
			
			root->update2(temp,(val-val2)/(ld)(pos[temp]-pos[l2]));
			
			dll[temp]=l2;
			dlr[l2]=temp;
		}
		else if (a==2){
			cin>>a;
			
			r+=a;
			r2++;
			pos[r2]=r-a+1;
			
			int temp=dll[0];
			
			ll val=root2->query(-RS,pos[r2]);
			ll val2=root2->query(-RS,pos[temp]);
			
			root->update2(r2,(val-val2)/(ld)(pos[r2]-pos[temp]));
			
			dll[0]=r2;
			dlr[r2]=0;
			
			dll[r2]=temp;
			dlr[temp]=r2;
		}
		else{
			cin>>a>>b;
			
			root2->update(l,l,a);
			root2->update(r+1,r+1,(l-r)*b-a);
			if (l!=r) root2->update(l+1,r,b);
			
			root->update(l2,r2,b);
		}
		
		while (root->val.fi> -EPS){
			//cout<<"debug: "<<root->val.fi<<" "<<root->val.se<<endl;
			
			int idx=dlr[root->val.se];
			root->update2(dll[idx],-INF); //reset
			int l=dll[dll[idx]];
			
			//cout<<"upd: "<<pos[idx]<<" "<<pos[l]<<endl;
			
			dll[idx]=l;
			dlr[l]=idx;
			
			if (idx!=0){
				ll val=root2->query(-RS,pos[idx]);
				ll val2=root2->query(-RS,pos[l]);
				
				root->update2(idx,(val-val2)/(ld)(pos[idx]-pos[l]));
			}
		}
		
		//rep(x,l,r+1) cout<<root2->query(-RS,x)<<" "; cout<<endl;
		//cout<<root->val.fi<<endl;
		cout<<pos[dll[0]]-l+1<<" "<<root2->query(-RS,pos[dll[0]])<<endl;
		//cout<<endl;
	}
}