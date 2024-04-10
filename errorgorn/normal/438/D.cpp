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

#define rep(x,start,end) for(auto x=start-(start>end);x!=end-(start>end);x+=(start<end?1:-1))
#define all(x) x.begin(),x.end()

ll MAX(ll a){return a;}
ll MIN(ll a){return a;}
template<typename... Args>
ll MAX(ll a,Args... args){return max(a,MAX(args...));}
template<typename... Args>
ll MIN(ll a,Args... args){return min(a,MIN(args...));}

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
struct node{
	int s,e,m;
	ll val;
	int maxi;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	void update(int i,int j){
		if (s==e) val=maxi=j;
		else{
			if (i<=m) l->update(i,j);
			else r->update(i,j);
			
			val=l->val+r->val;
			maxi=max(l->maxi,r->maxi);
		}
	}
	
	void update_mod(int i,int j,int k){
		if (maxi<k) return;
		if (s==e){
			val%=k;
			maxi=val;
		}
		else{
			if (j<=m) l->update_mod(i,j,k);
			else if (m<i) r->update_mod(i,j,k);
			else l->update_mod(i,m,k),r->update_mod(m+1,j,k);
			
			val=l->val+r->val;
			maxi=max(l->maxi,r->maxi);
		}
		
	}
	
	ll query(int i,int j){
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return l->query(i,m)+r->query(m+1,j);
	}
}*root=new node(0,100005);

int n,m;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	
	rep(x,1,n+1){
		int temp;
		cin>>temp;
		root->update(x,temp);
	}
	
	int a,b,c;
	while (m--){
		cin>>a;
		if (a==1){
			cin>>a>>b;
			cout<<root->query(a,b)<<endl;
		}
		else if (a==2){
			cin>>a>>b>>c;
			root->update_mod(a,b,c);
		}
		else{
			cin>>a>>b;
			root->update(a,b);
		}
	}
}