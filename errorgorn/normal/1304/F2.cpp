/*













*/

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
	int s,e,m;
	int val,lazy;
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
			val+=lazy;
			if (s!=e){
				l->lazy+=lazy;
				r->lazy+=lazy;
			}
			lazy=0;
		}
	}
	
	void update(int i,int j,int k){
		if (j<i) return; //ok cool
	
		if (s==i && e==j) lazy+=k;
		else{
			if (j<=m) l->update(i,j,k);
			else if (m<i) r->update(i,j,k);
			else l->update(i,m,k),r->update(m+1,j,k);
			
			l->propo(),r->propo();
			val=max(l->val,r->val);
		}
	}
	
	int query(int i,int j){
		propo();
		
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return max(l->query(i,m),r->query(m+1,j));
	}
	
	void clear(){
		val=lazy=0;
		if (s!=e){
			l->clear();
			r->clear();
		}
	}
}*root=new node(0,20005);

int n,m,k;
int grid[55][20005];
int pre[55][20005];

int w[2][20005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>k;
	rep(x,0,n){
		rep(y,1,m+1){
			cin>>grid[x][y];
			pre[x][y]=grid[x][y]+pre[x][y-1];
		}
	}
	
	rep(x,0,m-k+1){
		w[0][x]=pre[0][x+k]-pre[0][x]+pre[1][x+k]-pre[1][x];
	}
	
	int a=0,b=1;
	
	rep(x,1,n){
		memset(w[b],0,sizeof(w[b]));
		//rep(y,0,m-k+1) cout<<w[a][y]<<" ";
		//cout<<endl;
		
		root->clear();
		rep(y,0,m-k+1) root->update(y,y,w[a][y]);
		rep(y,m-k+1,0){
			root->update(y+1,m-k,grid[x][y+1]);
			if (y+k+1<m-k+1) root->update(y+k+1,m-k,-grid[x][y+k+1]);
			w[b][y]=max(w[b][y],root->query(y,m-k));
		}
		
		root->clear();
		rep(y,0,m-k+1) root->update(y,y,w[a][y]);
		rep(y,0,m-k+1){
			root->update(0,y-1,grid[x][y+k]);
			if (k<=y) root->update(0,y-1-k,-grid[x][y]);
			w[b][y]=max(w[b][y],root->query(0,y));
		}
		
		rep(y,0,m-k+1) w[b][y]+=pre[x+1][y+k]-pre[x+1][y];
				
		swap(a,b);
	}
	
	//rep(x,0,m-k+1) cout<<w[a][x]<<" ";
	//cout<<endl;
	
	int ans=0;
	rep(x,0,m-k+1) ans=max(ans,w[a][x]);
	cout<<ans<<endl;
}