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

ll MAX(ll a){return a;}
ll MIN(ll a){return a;}
template<typename... Args>
ll MAX(ll a,Args... args){return max(a,MAX(args...));}
template<typename... Args>
ll MIN(ll a,Args... args){return min(a,MIN(args...));}

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,q;
double arr[100005];

struct node{
	int s,e,m;
	double val;
	double a=1,b=0;//lazy
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
			
			val=l->val+r->val;
		}
		else{
			val=arr[s];
		}
	}
	
	void mul(double c,double d){
		a=a*c;
		b=b*c+d;
	}
	
	void propo(){
		val=val*a+b*(e-s+1);
		
		if (s!=e){
			l->mul(a,b),r->mul(a,b);
		}
		
		a=1,b=0;
	}
	
	void update(int i,int j,double t1,double t2){
		propo();
		
		if (s==i && e==j) mul(t1,t2);
		else{
			if (j<=m) l->update(i,j,t1,t2);
			else if (m<i) r->update(i,j,t1,t2);
			else l->update(i,m,t1,t2),r->update(m+1,j,t1,t2);
			
			l->propo(),r->propo();
			val=l->val+r->val;
		}
	}
	
	double query(int i,int j){
		propo();
		
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return l->query(i,m)+r->query(m+1,j);
	}
} *root;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>q;
	rep(x,1,n+1) cin>>arr[x];
	
	root=new node(1,n);
	
	int a,b,c,d;
	while (q--){
		cin>>a;
		
		if (a==1){
			cin>>a>>b>>c>>d;
			
			double l1=b-a+1,l2=d-c+1;
			double v1=root->query(a,b),v2=root->query(c,d);
			
			root->update(a,b,(l1-1)/l1,v2/l2/l1);
			root->update(c,d,(l2-1)/l2,v1/l1/l2);
			
			//rep(x,1,n+1) cout<<root->query(x,x)<<" ";cout<<endl;
		}
		else{
			cin>>a>>b;
			
			cout<<fixed<<setprecision(16)<<root->query(a,b)<<endl;
		}
	}
}