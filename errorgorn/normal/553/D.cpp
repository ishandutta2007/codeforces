/*













*/

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")


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

#define di pair<double,int>

int n,m,k;
bool block[100005];

vector<int> al[100005];
bool vis[100005];
int dg[100005];
int active[100005];

priority_queue<di,vector<di>,greater<di> > pq;
set<int> proc;

double calc(int i){
	return (double)active[i]/dg[i];
}

void dfs(int i){
	vis[i]=true;
	
	for (auto &it:al[i]){
		dg[i]++;
		if (!block[it]) active[i]++;
		if (!block[it] && !vis[it]) dfs(it);
	}
	
	pq.push(di(calc(i),i));
	proc.insert(i);
}

double best=-1;
vector<int> ans;

void get_ans(int i){
	ans.push_back(i);
	
	vis[i]=true;
	
	for (auto &it:al[i]){
		if (proc.count(it) && !vis[it]) get_ans(it);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>k;
	
	rep(x,0,k){
		int t;
		cin>>t;
		block[t]=true;
	}
	
	rep(x,0,m){
		int a,b;
		cin>>a>>b;
		al[a].push_back(b);
		al[b].push_back(a);
	}
	
	rep(x,1,n+1) if (!block[x] && !vis[x]){		
		while (!pq.empty()) pq.pop();
		proc.clear();
		dfs(x);
		
		double weight;
		int node;
		while (!pq.empty()){
			weight=pq.top().fi;
			node=pq.top().se;
			pq.pop();
			
			if (weight!=calc(node)) continue;
			
			best=max(best,weight);
			
			for (auto &it:al[node]){
				if (proc.count(it)){
					active[it]--;
					
					pq.push(di(calc(it),it));
				}
			}
			
			proc.erase(node);
		}
	}
	
	//cout<<best<<endl;
	
	memset(dg,0,sizeof(dg));
	memset(active,0,sizeof(active));
	memset(vis,false,sizeof(vis));
	
	rep(x,1,n+1) if (!block[x] && !vis[x]){		
		while (!pq.empty()) pq.pop();
		proc.clear();
		dfs(x);
		
		double weight;
		int node;
		while (!pq.empty()){
			weight=pq.top().fi;
			node=pq.top().se;
			pq.pop();
			
			if (weight!=calc(node)) continue;
			
			if (weight==best){
				memset(vis,false,sizeof(vis));
				get_ans(node);
				
				cout<<sz(ans)<<endl;
				for (auto &it:ans) cout<<it<<" ";
				
				return 0;
			}
			
			for (auto &it:al[node]){
				if (proc.count(it)){
					active[it]--;
					
					pq.push(di(calc(it),it));
				}
			}
			
			proc.erase(node);
		}
	}
}