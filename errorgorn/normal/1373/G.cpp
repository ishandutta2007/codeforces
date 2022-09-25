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

struct node{
	int s,e,m,len;
	int zeros;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		zeros=len=e-s+1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	void update(int i,int j){
		zeros+=j;
		
		if (s==e) return;
		else if (i<=m) l->update(i,j);
		else r->update(i,j);
	}
	
	int zf(){
		if (s==e) return s;
		if (l->zeros) return l->zf();
		else return r->zf();
	}
	
	int of(){
		if (s==e) return s;
		if (r->zeros!=r->len) return r->of();
		else return l->of();
	}
	
	int find(int i,int j){
		if (s==i && e==j){
			if (zeros==0) return -1;
			else return zf();
		}
		else if (j<=m) return l->find(i,j);
		else if (m<i) return r->find(i,j);
		else{
			int temp=l->find(i,m);
			
			if (temp!=-1) return temp;
			else return r->find(m+1,j);
		}
	}
} *root=new node(0,600005);

vector<int> stk;
int ans[200010];

struct node2{ //dnc on queries here
	int s,e,m;
	vector<int> val;
	node2 *l,*r;
	
	node2(int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node2(s,m);
			r=new node2(m+1,e);
		}
	}
	
	void update(int i,int j,int pp){
		if (s==i && e==j) val.push_back(pp);
		else if (j<=m) l->update(i,j,pp);
		else if (m<i) r->update(i,j,pp);
		else l->update(i,m,pp),r->update(m+1,j,pp);
	}
	
	void dfs(){
		int stk_sz=sz(stk);
		
		for (auto &it:val){
			int temp=root->find(it,600005);
			root->update(temp,-1);
			stk.push_back(temp);
		}
		
		if (s==e){
			ans[s]=root->of();
		}
		else{
			l->dfs();
			r->dfs();
		}
		
		while (sz(stk)!=stk_sz){
			root->update(stk.back(),1);
			stk.pop_back();
		}
	}
} *root2=new node2(0,200005);

int n,m,k;
map<ii,int> pnts;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k>>m;
	
	int a,b;
	rep(x,0,m){
		cin>>a>>b;
		
		if (pnts.count(ii(a,b))){
			//cout<<pnts[ii(a,b)]<<" "<<x-1<<" "<<b+abs(k-a)<<endl;
			root2->update(pnts[ii(a,b)],x-1,b+abs(k-a));
			pnts.erase(ii(a,b));
		}
		else{
			pnts[ii(a,b)]=x;
		}
	}
	
	for (auto &it:pnts){
		//cout<<it.se<<" "<<200005<<" "<<it.fi.se+abs(k-it.fi.fi)<<endl;
		root2->update(it.se,200005,it.fi.se+abs(k-it.fi.fi));
	}
	
	root2->dfs();
	
	rep(x,0,m) cout<<max(0,ans[x]-n)<<endl;
}