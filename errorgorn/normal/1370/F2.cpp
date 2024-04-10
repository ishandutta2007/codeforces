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

int n;
vector<int> al[1005];
vector<int> qq;
int parent[1005];
int ss[1005];

ii test(){
	if (qq.empty()) return ii(-1,-1);
	
	cout<<"? "<<sz(qq)<<" ";
	for (auto &it:qq) cout<<it<<" ";
	cout<<endl;
	
	qq.clear(); //kek
	
	ii res;
	cin>>res.fi>>res.se;
	return res;
}

void dfsp(int i,int p){
	parent[i]=p;
	ss[i]=1;
	
	for (auto &it:al[i]){
		if (it==p) continue;
		dfsp(it,i);
		ss[i]+=ss[it];
	}
}

void dfs(int i,int p,int curr,int goal){
	if (curr==goal) qq.push_back(i);
	
	for (auto &it:al[i]){
		if (it==p) continue;
		dfs(it,i,curr+1,goal);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		rep(x,0,1005) al[x].clear();	
		
		cin>>n;
		
		int a,b;
		rep(x,1,n){
			cin>>a>>b;
			al[a].push_back(b);
			al[b].push_back(a);
		}
		
		rep(x,1,n+1) qq.push_back(x);
		
		ii root=test();
		
		dfsp(root.fi,-1);
		for (auto &it:al[root.fi]) if (ss[it]>=512) parent[root.fi]=it;
		
		int curr=root.fi;
		for (int dist=512;dist;dist>>=1){
			dfs(curr,parent[curr],0,dist);
			
			ii temp=test();
			if (temp.se==root.se) curr=temp.fi;
		}
		
		dfs(curr,-1,0,root.se);
		int tail=test().fi;
		
		cout<<"! "<<curr<<" "<<tail<<endl;
		
		string bruh;
		cin>>bruh;
	}
}