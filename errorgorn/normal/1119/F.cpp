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

struct node{
	int cnt=0;
	ll val=0;
	node *l=nullptr,*r=nullptr;
	
	node (){
	}
	
	void update(int i,int j,int k,int s=0,int e=1e6+5){
		int m=s+e>>1;
		
		cnt+=j,val+=k;
		
		if (s==e) return;
		if (i<=m){
			if (l==nullptr) l=new node();
			l->update(i,j,k,s,m);
		}
		else{
			if (r==nullptr) r=new node();
			r->update(i,j,k,m+1,e);
		}
	}
	
	ll query(ll num,int s=0,int e=1e6+5){
		int m=s+e>>1;
		
		if (s==e) return num*s;
		if (cnt==num) return val;
		if (l==nullptr) return r->query(num,m+1,e);
		else if (l->cnt>=num) return l->query(num,s,m);
		else return l->val+r->query(num-l->cnt,m+1,e);
	}
	
	void del(){
		if (l!=nullptr) l->del();
		if (r!=nullptr) r->del();
		delete(this);
	}
} *root[250005];


int n;
set<ii> al[250005];

ll k;

vector<ll> proc;
ll ss[250005];
bool can[250005];

ll vis[250005];

//how many dead people have a certain weight

ii dfs(ll i,ll p){
	vis[i]=k;
	vector<ll> deltas;
	ll tot=0;
	ll num=0;
	
	for (auto &it:al[i]){
		if (it.fi==p) continue;
		if (!can[it.fi]) continue;
		
		ii temp=dfs(it.fi,i);
		
		//cout<<"dfs: "<<i<<" "<<it.fi<<" "<<temp.fi<<" "<<temp.se<<endl;
		
		tot+=temp.se;
		ll delta=temp.fi-temp.se+it.se;
		if (delta<0) tot+=delta,num++;
		else deltas.pub(delta);
	}
	
	ii ret;
	
	for (auto &it:deltas) root[i]->update(it,1,it);
	
	//cout<<i<<" "<<p<<" "<<root[i]->cnt<<" "<<ss[i]-k<<" "<<num<<endl;
	if (ss[i]-k-1-num<=0) ret.fi=tot;
	else ret.fi=tot+root[i]->query(ss[i]-k-1-num);
	
	if (ss[i]-k-num<=0) ret.se=tot;
	else ret.se=tot+root[i]->query(ss[i]-k-num);
	
	for (auto &it:deltas) root[i]->update(it,-1,-it);
	
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	
	cin>>n;
	ll tot=0;
	
	int a,b,c;
	rep(x,0,n-1){
		cin>>a>>b>>c;
		a--,b--;
		tot+=c;
		
		al[a].insert(ii(b,c));
		al[b].insert(ii(a,c));
	}
	
	memset(vis,-1,sizeof(vis));
						 
	vector<ll> ans(n,0);
	ans[0]=tot;
	
	rep(x,0,n) ss[x]=sz(al[x]);
	rep(x,0,n) proc.pub(x),can[x]=true;
	sort(all(proc),[](int i,int j){
		return ss[i]>ss[j];
	});
	
	rep(x,0,n) root[x]=new node();
	
	rep(x,1,n){
		k=x;
		
		while (!proc.empty() && ss[proc.back()]<=x){
			int node=proc.back();
			//cout<<"delete: "<<node<<endl;
			can[node]=false;
			
			for (auto &it:al[node]){
				al[it.fi].erase(ii(node,it.se));
				root[it.fi]->update(it.se,1,it.se);
			}
			
			root[node]->del();
			proc.pob();
		}
		
		ll val=0;
		for (auto &it:proc){
			//cout<<"processing: "<<x<<" "<<it<<endl;
			if (vis[it]!=k) val+=dfs(it,-1).se;
		}
		
		ans[x]=val;
	}
	
	for (auto &it:ans) cout<<it<<" "; cout<<endl;
}