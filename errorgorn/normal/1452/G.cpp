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

int n,m;
vector<int> al[200005];
int w[200005];
priority_queue<ii,vector<ii>,greater<ii> > pq;

int cent[200005];
bool used[200005];
int sz[200005];

void dfs_sz(int i,int p){
	sz[i]=1;
	for (auto &it:al[i]){
		if (it==p) continue;
		if (used[it]) continue;
		dfs_sz(it,i);
		sz[i]+=sz[it];
	}
}

vector<int> mx[200005];
vector<int> dist[200005];

void dfs(int i,int p,int d,int rp){
	while (sz(mx[rp])<=d) mx[rp].pub(0);
	mx[rp][d]=max(mx[rp][d],w[i]);
	dist[i].pub(d);
	
	for (auto &it:al[i]){
		if (it==p) continue;
		if (used[it]) continue;
		dfs(it,i,d+1,rp);
	}
}

void centroid(int i,int p){
	int curr=i;
	int currp=-1;
	
	dfs_sz(i,-1);
	int ss=sz[i];
	
	while (true){
		bool rec=false;
		for (auto &it:al[curr]){
			if (it==currp || used[it]) continue;
			
			if (sz[it]>=(ss+1)/2){
				currp=curr;
				curr=it;
				rec=true;
				break;
			}
		}
		if (!rec) break;
	}
	
	dfs(curr,-1,0,curr);
	rep(x,0,sz(mx[curr])-1) mx[curr][x+1]=max(mx[curr][x+1],mx[curr][x]);
	
	cent[curr]=p;
	used[curr]=true;
	
	for (auto &it:al[curr]) if (!used[it]) centroid(it,curr);
}

bool can(int i,int len){
	int idx=sz(dist[i])-1;
	int curr=i;
	int val=0;
	while (curr!=-1){
		int l=min(len-dist[i][idx],sz(mx[curr])-1);
		if (l>=0) val=max(val,mx[curr][l]);
		curr=cent[curr];
		idx--;
	}
	
	return val>len;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	
	int a,b;
	rep(x,1,n){
		cin>>a>>b;
		al[a].pub(b);
		al[b].pub(a);
	}
	
	memset(w,63,sizeof(w));
	
	cin>>m;
	rep(x,0,m){
		cin>>a;
		w[a]=0;
		pq.push(ii(w[a],a));
	}
	
	int weight,node;
	while (!pq.empty()){
		tie(weight,node)=pq.top(),pq.pop();
		
		if (w[node]!=weight) continue;
		
		for (auto &it:al[node]){
			if (w[it]>weight+1){
				w[it]=weight+1;
				pq.push(ii(w[it],it));
			}
		}
	}
	
	//rep(x,1,n+1) cout<<w[x]<<" "; cout<<endl;
	
	centroid(1,-1);
	
	//rep(x,1,n+1) cout<<cent[x]<<" "; cout<<endl;
	
	rep(x,1,n+1){
		int lo=-1,hi=2e5,mi;
		while (hi-lo>1){
			mi=hi+lo>>1;
			
			if (can(x,mi)) lo=mi;
			else hi=mi;
		}
		
		cout<<hi<<" ";
	}
}