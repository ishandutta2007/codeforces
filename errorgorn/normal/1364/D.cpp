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

int n,m,k;
vector<int> al[100005];
int deg[100005];

priority_queue<ii,vector<ii>,greater<ii> > pq;
bool indie[100005];
bool bad[100005];

int vis[100005];

int root=-1;
vector<int> ans;

bool dfs(int i,int p){
	vis[i]=2;
	
	for (auto &it:al[i]){
		if (it==p) continue;
		
		if (!vis[it]){
			if (dfs(it,i)){
				if (root!=-1) ans.push_back(i);
				if (i==root) root=-1;
				return true;
			}
		}
		else if (vis[it]==2){
			root=it;
			ans.push_back(i);
			return true;
		}
	}
	
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>k;
	
	rep(x,0,m){
		int a,b;
		cin>>a>>b;
		
		al[a].push_back(b);
		al[b].push_back(a);
		
		deg[a]++,deg[b]++;
	}
	
	rep(x,1,n+1) pq.push(ii(deg[x],x));
	
	int num=n;
	
	while (!pq.empty()){
		int d=pq.top().fi,node=pq.top().se;
		pq.pop();
		
		if (deg[node]!=d) continue;
		
		//cerr<<node<<" "<<d<<endl;
		
		if (d>=2 && num<=k){ //can form cycle
			cout<<2<<endl;
			dfs(node,-1);
			
			cout<<sz(ans)<<endl;
			for (auto &it:ans) cout<<it<<" ";
			
			return 0;
		}
		
		vis[node]=1;
		num--;
		
		if (!bad[node]) indie[node]=true;
		for (auto &it:al[node]) if (!vis[it]){
			deg[it]--;
			if (indie[node]) bad[it]=true;
			pq.push(ii(deg[it],it));
		}
	}
	
	int cnt=(k+1)/2;
	cout<<1<<endl;
	rep(x,1,n+1){
		if (cnt && indie[x]){
			cout<<x<<" ";
			cnt--;
		}
	}
}