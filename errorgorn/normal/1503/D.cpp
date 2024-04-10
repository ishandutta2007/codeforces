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

int n;
vector<ii> v;

struct node{
	int s,e,m;
	ll val=0;
	bool kill=false;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	void propo(){
		if (kill){
			val=0;
			if (s!=e){
				l->kill=r->kill=true;
			}
			kill=false;
		}
	}
	
	void update(int i,int j,ll k){
		propo();
		
		if (s==i && e==j) val=max(val,k);
		else if (j<=m) l->update(i,j,k);
		else if (m<i) r->update(i,j,k);
		else l->update(i,m,k),r->update(m+1,j,k);
	}
	
	ll query(int i){
		propo();
		
		if (s==e) return val;
		else{
			if (i<=m) return max(val,l->query(i));
			else return max(val,r->query(i));
		}
	}
} *root[2]={new node(0,400010),new node(0,400010)};


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,0,n){
		int a,b;
		cin>>a>>b;
		v.pub(ii(a,b));
	}
	
	ll mn=1e9,mx=-1e9;
	for (auto &it:v){
		mn=min(mn,max(it.fi,it.se));
		mx=max(mx,min(it.fi,it.se));
	}
	
	if (mn<mx){
		cout<<"-1"<<endl;
		return 0;
	}
	
	sort(all(v),[](ii i,ii j){
		return min(i.fi,i.se)<min(j.fi,j.se);
	});
	
	//for (auto &it:v) cout<<it.fi<<" "<<it.se<<endl;
	
	int pos[2]={200005,200005};
	rep(x,0,2) root[x]->update(pos[x],400010,1e9);
	
	int p=1e9;
	for (auto &it:v){
		int val=max(it.fi,it.se);
		int pos0=1e9,pos1=1e9;
		
		int lo,hi,mi;
		
		lo=0,hi=400011,mi;
		while (hi-lo>1){
			mi=hi+lo>>1;
			
			if (root[0]->query(mi)<val) lo=mi;
			else hi=mi;
		}
		
		if (hi!=400011) pos1=hi-pos[0]+pos[1];
		
		lo=0,hi=400011,mi;
		while (hi-lo>1){
			mi=hi+lo>>1;
			
			if (root[1]->query(mi)<val) lo=mi;
			else hi=mi;
		}
		
		if (hi!=400011) pos0=hi-pos[1]+pos[0];
		
		if (p<val) root[0]->kill=true,root[1]->kill=true;
		
		if (pos0<=400010) root[0]->update(pos0,400010,p);
		if (pos1<=400010) root[1]->update(pos1,400010,p);
		
		if (it.fi<it.se) pos[0]--;
		else pos[1]--;
		
		p=val;
		
		//rep(x,0,5) cout<<root[0]->query(pos[0]+x)<<" "; cout<<endl;
		//rep(x,0,5) cout<<root[1]->query(pos[1]+x)<<" "; cout<<endl;
		//cout<<endl;
	}
	
	int ans=0;
	
	rep(x,0,200000){
		if (root[0]->query(pos[0]+x)!=0 || root[1]->query(pos[1]+x)){
			cout<<x<<endl;
			return 0;
		}
	}
	
	cout<<"-1"<<endl;
}