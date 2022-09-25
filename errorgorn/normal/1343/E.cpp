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

int n,m,A,B,C;
ll p[200005];
vector<int> al[200005];

int w[3][200005];
queue<int> q;

void do_bfs(int l,int root){
	w[l][root]=0;
	q.push(root);
	
	int node;
	while (!q.empty()){
		node=q.front(),q.pop();
		
		for (auto &it:al[node]) if (w[l][it]==-1){
			w[l][it]=w[l][node]+1;
			q.push(it);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>m>>A>>B>>C;
		
		rep(x,1,n+1){
			al[x].clear();
			w[0][x]=w[1][x]=w[2][x]=-1;	
		}
		
		rep(x,1,m+1){
			cin>>p[x];
		}
		
		int a,b;
		rep(x,0,m){
			cin>>a>>b;
			al[a].push_back(b);
			al[b].push_back(a);
		}
		
		sort(p+1,p+m+1);
		
		rep(x,1,m+1) p[x]+=p[x-1];
		//rep(x,0,m+1) cout<<p[x]<<" ";cout<<endl;
		
		do_bfs(0,A);
		do_bfs(1,B);
		do_bfs(2,C);
		
		//rep(x,1,n+1) cout<<w[0][x]<<" "; cout<<endl;
		//rep(x,1,n+1) cout<<w[1][x]<<" "; cout<<endl;
		//rep(x,1,n+1) cout<<w[2][x]<<" "; cout<<endl;
		
		ll ans=1e18;
		
		rep(x,1,n+1){
			int t=w[0][x]+w[2][x];
			int tt=w[1][x];
			
			//cout<<t<<" "<<tt<<endl;
			
			if (t+tt<=m){
				ans=min(ans,p[tt]*2+p[t+tt]-p[tt]);
			}
		}
		
		cout<<ans<<endl;
	}
}