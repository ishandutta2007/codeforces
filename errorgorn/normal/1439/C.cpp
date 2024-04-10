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

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

struct node{
	int s,e,m,len;
	ll val=0,lazy=0;
	ll mn=0,mx=0;
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
		if (lazy){
			val=lazy*len;
			mx=mn=lazy;
			if (s!=e){
				l->lazy=lazy;
				r->lazy=lazy;
			}
			lazy=0;
		}
	}
	
	void update(int i,int j,ll k){
		propo();
		
		if (s==i && e==j) lazy=k;
		else{
			if (j<=m) l->update(i,j,k);
			else if (m<i) r->update(i,j,k);
			else l->update(i,m,k),r->update(m+1,j,k);
			
			l->propo(),r->propo();
			val=l->val+r->val;
			mx=l->mx;
			mn=r->mn;
		}
	}
	
	ll query(int i,int j){
		propo();
		
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return l->query(i,m)+r->query(m+1,j);
	}
	
	ll find(ll val){
		propo();
		
		if (s==e) return s;
		if (l->mn<=val) return l->find(val);
		else return r->find(val);
	}
	
	ll find2(int st,ll val){
		propo();
		
		//cout<<"debug: "<<st<<" "<<val<<endl;
		if (st>m) return r->find2(st,val);
		if (s==e) return s;
		st=max(st,s);
		ll temp=l->query(st,m);
		if (temp<=val){
			val-=temp;
			r->propo();
			if (r->mx>val) return m;
			else return r->find2(st,val);
		}
		else return l->find2(st,val);
	}
} *root=new node(0,200005);

ll n,q;
int arr[200005];


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>q;
	rep(x,0,n) cin>>arr[x];
	rep(x,0,n) root->update(x,x,arr[x]);
	
	int a,b;
	while (q--){
		cin>>a;
		if (a==1){
			cin>>a>>b;
			a--;
			
			int lo=-1,hi=a+1,mi;
			while (hi-lo>1){
				mi=hi+lo>>1;
				
				if (root->query(mi,mi)<b) hi=mi;
				else lo=mi;
			}
			
			if (hi<=a) root->update(hi,a,b);
		}
		else{
			cin>>a>>b;
			
			ll pos=a-1;
			int curr=b;
			int ans=0;
			while (pos!=n){
				pos=max(pos,root->find(curr));
				if (pos>=n) break;
				
				ll npos=min(n-1,root->find2(pos,curr));
				
				//cout<<pos<<" "<<npos<<endl;
				
				curr-=root->query(pos,npos);
				
				ans+=npos-pos+1;
				pos=npos+1;
			}
			
			cout<<ans<<endl;
		}
		
		//rep(x,0,n) cout<<root->query(x,x)<<" "; cout<<endl;
	}
}