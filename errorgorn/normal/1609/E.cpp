//
//

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

struct dat{
	int cost[32]; //a,b,c,ab,bc
	
	dat(){
		memset(cost,63,sizeof(cost));
	}
};

int arr[32][32];

vector<ii> v;
dat merge(dat i,dat j){
	dat res;
	
	for (auto [x,y]:v){
		res.cost[arr[x][y]]=min(res.cost[arr[x][y]],i.cost[x]+j.cost[y]);
	}
	
	return res;
}

int n,q;
string st;

struct node{
	int s,e,m;
	dat val;
	node *l,*r;
	
	node(int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
			val=merge(l->val,r->val);
		}
		else{
			val.cost[1]=1;
			val.cost[2]=1;
			val.cost[4]=1;
			
			if (st[s]=='a') val.cost[1]=0;
			else if (st[s]=='b') val.cost[2]=0;
			else val.cost[4]=0;
		}
	}
	
	void update(int i,char c){
		if (s==e){
			val.cost[1]=1;
			val.cost[2]=1;
			val.cost[4]=1;
			
			if (c=='a') val.cost[1]=0;
			else if (c=='b') val.cost[2]=0;
			else val.cost[4]=0;
		}
		else{
			if (i<=m) l->update(i,c);
			else r->update(i,c);
			val=merge(l->val,r->val);
		}
	}
} *root;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	rep(x,0,32) rep(y,0,32){
		if ((x&8) && (x&3)!=3) continue;
		if ((x&16) && (x&6)!=6) continue;
		if ((y&8) && (y&3)!=3) continue;
		if ((y&16) && (y&6)!=6) continue;
		
		arr[x][y]=x|y;
		if ((x&1) && (y&2)) arr[x][y]|=(1<<3);
		if ((x&2) && (y&4)) arr[x][y]|=(1<<4);
		
		if ((x&8) && (y&4)) arr[x][y]=-1;
		if ((x&1) && (y&16)) arr[x][y]=-1;
		
		if (arr[x][y]!=-1) v.pub(ii(x,y));
	}
	
	//cout<<sz(v)<<endl;
	
	cin>>n>>q;
	cin>>st;
	
	root=new node(0,n-1);
	
	int a;
	char c;
	
	while (q--){
		cin>>a>>c;
		
		a--;
		root->update(a,c);
		
		auto temp=root->val;
		
		int ans=1e9;
		rep(x,0,32) ans=min(ans,temp.cost[x]);
		cout<<ans<<endl;
	}
	
}