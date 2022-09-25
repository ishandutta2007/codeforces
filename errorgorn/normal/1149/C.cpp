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

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

struct node{
	int s,e,m;
	int a=0,b=0,c=0,ab=0,bc=0,abc=0,lazy=0;
	node *l,*r;
	
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	void propo(){
		if (lazy){
			a+=lazy;
			b-=2*lazy;
			c+=lazy;
			
			ab-=lazy;
			bc-=lazy;
			
			if (s!=e){
				l->lazy+=lazy;
				r->lazy+=lazy;
			}
			lazy=0;
		}
	}
	
	void update(int i,int j,int k){
		if (s==i && e==j) lazy+=k;
		else{
			if (j<=m) l->update(i,j,k);
			else if (m<i) r->update(i,j,k);
			else l->update(i,m,k),r->update(m+1,j,k);
			
			l->propo(),r->propo();
			
			a=max(l->a,r->a);
			b=max(l->b,r->b);
			c=max(l->c,r->c);
			ab=max({l->ab,r->ab,l->a+r->b});
			bc=max({l->bc,r->bc,l->b+r->c});
			abc=max({l->abc,r->abc,l->ab+r->c,l->a+r->bc});
		}
	}
} *root=new node(0,200005);

int n,q;
string s;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>q;
	cin>>s;
	
	s="$"+s;
	int curr=0;
	rep(x,1,sz(s)){
		if (s[x]=='(') curr++;
		else curr--;
		
		root->update(x,x,curr);
	}
	
	root->propo();
	cout<<root->abc<<endl;
	
	int a,b;
	while (q--){
		cin>>a>>b;
		if (a>b) swap(a,b);
		if (s[a]=='(') root->update(a,b-1,-2);
		else root->update(a,b-1,2);
		
		swap(s[a],s[b]);
		
		root->propo();
		cout<<root->abc<<endl;
	}
}