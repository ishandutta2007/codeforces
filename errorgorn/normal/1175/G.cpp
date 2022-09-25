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
#define ii pair<int,int>
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

struct line{
	int m=0,c=1e9;
	
	int eval(int x){
		return m*x+c;
	}
};

double POI(line a,line b){
	return (double)(a.c-b.c)/(double)(b.m-a.m);
}

struct node;

#define nl pair<node*,line>
vector<nl> stk;

struct node{
	int s,e,m;
	line val;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	void update(line i){
		bool lo=i.eval(s)<val.eval(s);
		bool mi=i.eval(m)<val.eval(m);
		bool hi=i.eval(e)<val.eval(e);
		
		if (mi){
			stk.pub({this,val});
			swap(i,val);
		}
		
		if (s==e || lo==hi) return;
		
		if (lo!=mi) l->update(i);
		else r->update(i);
	}
	
	int query(int i){
		if (val.c==1e9) return 1e9;
		if (s==e) return val.eval(i);
		
		if (i<=m) return min(val.eval(i),l->query(i));
		else return min(val.eval(i),r->query(i));
	}
} *root=new node(0,20005);

void roll(int i){
	while (sz(stk)>i){
		node *curr=stk.back().fi;
		line val=stk.back().se;
		stk.pob();
		curr->val=val;
	}
}

int n,k;
int arr[20005];
int memo[2][20005];

deque<line> dq[200005];

void merge(int i,int j){
	if (sz(dq[i])<sz(dq[j])){
		rep(x,sz(dq[i]),0){
			while (sz(dq[j])>=2 && POI(dq[i][x],dq[j][0])>POI(dq[j][0],dq[j][1])){
				dq[j].pof();
			}
			dq[j].puf(dq[i][x]);
		}
	}
	else{
		rep(x,0,sz(dq[j])){
			while (sz(dq[i])>=2 && POI(dq[i][sz(dq[i])-2],dq[i][sz(dq[i])-1])>POI(dq[i][sz(dq[i])-1],dq[j][x])){
				dq[i].pob();
			}
			dq[i].pub(dq[j][x]);
		}
		swap(dq[i],dq[j]);
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>k;
	arr[0]=1e9;
	rep(x,1,n+1) cin>>arr[x];
	
	memo[0][0]=1e9;
	int mx=0;
	rep(x,1,n+1){
		mx=max(mx,arr[x]);
		memo[0][x]=x*mx;
	}
	
	int a=0,b=1;
	rep(_,1,k){
		rep(y,0,20005) memo[b][y]=1e9;
		
		roll(0);
		
		vector<ii> stk2={{0,0}};
		rep(x,1,n+1){
			dq[x]={line({-(x-1),memo[a][x-1]})};
			
			while (arr[stk2.back().fi]<arr[x]){
				merge(stk2.back().fi,x);
				stk2.pob();
			}
			roll(stk2.back().se);
			
			while (sz(dq[x])>=2 && dq[x][0].eval(arr[x])>dq[x][1].eval(arr[x])) dq[x].pof();
			
			root->update(line({arr[x],dq[x][0].eval(arr[x])}));
			
			stk2.pub({x,sz(stk)});
			memo[b][x]=root->query(x);
		}
		
		swap(a,b);
		//rep(x,1,n+1) cout<<memo[a][x]<<" "; cout<<endl;
	}
	
	cout<<memo[a][n]<<endl;
}