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

int n,m,sqrtn;
vector<int> al[100005];
int d[100005];
priority_queue<ii,vector<ii>,greater<ii> > pq;

bool used[100005];
bool blocked[100005]; //blocked in mis

vector<int> mis;

int occ[100005];
vector<int> cyc;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	sqrtn=ceil(sqrt(n));
	
	int a,b;
	rep(x,0,m){
		cin>>a>>b;
		al[a].push_back(b);
		al[b].push_back(a);
		
		d[a]++,d[b]++;
	}
	
	rep(x,1,n+1) pq.push(ii(d[x],x));
	
	int node,deg;
	while (!pq.empty()){
		deg=pq.top().fi,node=pq.top().se,pq.pop();
		
		if (d[node]!=deg) continue;
		
		if (deg>=sqrtn-1) break;
		used[node]=true;
		
		if (!blocked[node]) mis.push_back(node);
		
		for (auto &it:al[node]){
			if (!blocked[node]) blocked[it]=true;
			
			if (!used[it]){
				d[it]--;
				pq.push(ii(d[it],it));
			}
		}
	}
	
	if (sz(mis)>=sqrtn){
		cout<<1<<endl;
		rep(x,0,sqrtn) cout<<mis[x]<<" ";
		
		return 0;
	}
	
	int curr=-1;
	rep(x,1,n+1) if (!used[x]){
		curr=x;
		break;
	}
	
	memset(occ,-1,sizeof(occ));
	
	while (true){		
		occ[curr]=sz(cyc);
		cyc.push_back(curr);
		used[curr]=true;
		
		for (auto &it:al[curr]){
			if (!used[it]){
				curr=it;
				break;
			}
			else if (occ[it]!=-1 && sz(cyc)-occ[it]>=sqrtn){
				cout<<2<<endl;
				cout<<sz(cyc)-occ[it]<<endl;
				rep(x,occ[it],sz(cyc)) cout<<cyc[x]<<" ";
				return 0;
			}
		}
	}
}