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
map<ii,int> edges;
vector<ii> al[200005];

set<int> incyc;
vector<int> cyc;

bool complete=false;

bool dfs(int i,int p){
	incyc.insert(i);

	for (auto &it:al[i]){
		if (it.fi==p) continue;
		
		if (incyc.count(it.fi)){
			incyc.clear();
			incyc.insert(it.fi);
			cyc.push_back(it.fi);
			incyc.insert(i);
			cyc.push_back(i);
			return true;
		}
		else if (dfs(it.fi,i)){
			if (cyc.front()==i) complete=true;
			if (!complete){
				incyc.insert(i);
				cyc.push_back(i);
			}
			return true;
		}
	}
	
	incyc.erase(i);
	return false;
}

ll stp=0;

ll dfs2(int i,int p){
	ii val={0,0};
	
	for (auto &it:al[i]){
		if (it.fi==p || incyc.count(it.fi)) continue;
		
		val.se=max(val.se,dfs2(it.fi,i)+it.se);
		if (val.fi<val.se) swap(val.fi,val.se);
	}
	
	stp=max(stp,val.fi+val.se);
	return val.fi;
}

ll w[400005];
ll len[400005];

bool can(ll i){
	deque<int> dq;
	int l=0;
	
	rep(x,0,2*sz(cyc)){
		while (!dq.empty() && w[dq.front()]-len[dq.front()]+len[x]+w[x]>i){
			l=dq.front()+1;
			dq.pop_front();
		}
		
		while (!dq.empty() && w[dq.back()]-len[dq.back()]<w[x]-len[x]){
			dq.pop_back();
		}
		
		dq.push_back(x);
		
		if (x-l+1>=sz(cyc)) return true;
	}
	
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	
	int a,b,c;
	rep(x,0,n){
		cin>>a>>b>>c;
		
		al[a].push_back(ii(b,c));
		al[b].push_back(ii(a,c));
		
		edges[ii(a,b)]=c;
		edges[ii(b,a)]=c;
	}
	
	dfs(1,-1);
	
	rep(x,0,sz(cyc)){
		//cout<<cyc[x]<<endl;
		
		w[x+sz(cyc)]=w[x]=dfs2(cyc[x],-1);
		len[x+sz(cyc)+1]=len[x+1]=edges[ii(cyc[x],cyc[(x+1)%sz(cyc)])];
	}
	
	//rep(x,0,sz(cyc)*2) cout<<w[x]<<" "<<len[x]<<endl;
	rep(x,0,sz(cyc)*2) len[x+1]+=len[x];
	
	ll lo=0,hi=1e15,mi;
	
	while (hi-lo>1){
		mi=hi+lo>>1;
		
		if (can(mi)) hi=mi;
		else lo=mi;
	}
	
	//cout<<stp<<" "<<hi<<endl;
	cout<<max(stp,hi)<<endl;
}