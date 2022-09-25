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

const ll INF=1e18;

struct node{
	int s,e,m;
	ll val=0;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	void update(int i,ll j){
		if (s==e) val=j;
		else{
			if (i<=m) l->update(i,j);
			else r->update(i,j);
			
			val=l->val+r->val;
		}
	}
	
	ll query(int i,int j){
		if (j<i) return 0; //too lazy rn
	
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return l->query(i,m)+r->query(m+1,j);
	}
}*root=new node(0,500005);

void rage(){
	cout<<"NO"<<endl;
	exit(0);
}

int n;
int arr[500005];
vector<int> pos[500005];
vector<int> to_pop;
ll cost[500005];
int m;
int brr[500005];

ll ans[500005];
map<int,ll> costs;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	
	rep(x,0,n){
		cin>>arr[x];
		pos[arr[x]].push_back(x);
		to_pop.push_back(x);
	}
	
	sort(all(to_pop),[](int i,int j){
		return arr[i]>arr[j];
	});
	
	rep(x,0,n){
		cin>>cost[x];
		root->update(x,cost[x]);
	}
	
	cin>>m;
	rep(x,0,m){
		cin>>brr[x];
		
		if (pos[brr[x]].empty()) rage();
	}
	
	for (auto &it:pos[brr[0]]){
		ans[it]=root->query(0,it-1);
	}
	
	rep(x,1,m){
		while (arr[to_pop.back()]<=brr[x-1]){
			if (cost[to_pop.back()]>0) root->update(to_pop.back(),0);
			to_pop.pop_back();
		}
		
		vector<int> &curr=pos[brr[x-1]];
		costs.clear();
		
		costs[curr[0]]=ans[curr[0]];
		rep(y,1,sz(curr)){
			costs[curr[y]]=min(ans[curr[y]],costs[curr[y-1]]+root->query(curr[y-1]+1,curr[y]));
		}
		
		for (auto &it:pos[brr[x]]){
			auto ptr=costs.lower_bound(it);
			
			if (ptr==costs.begin()){
				ans[it]=INF;
				continue;
			}
			
			ptr--;
			
			ans[it]=ptr->se+root->query(ptr->fi+1,it-1);
		}
	}
	
	while (!to_pop.empty() && arr[to_pop.back()]<=brr[m-1]){
		if (cost[to_pop.back()]>0) root->update(to_pop.back(),0);
		to_pop.pop_back();
	}
	
	ll best=INF;
	
	rep(x,0,n) if (arr[x]==brr[m-1]){
		best=min(best,ans[x]+root->query(x+1,n-1));
	}
	
	if (1e15<best) rage();
	else{
		cout<<"YES"<<endl;
		cout<<best<<endl;
	}
}