// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define int long long
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

int n;
vector<int> al[300005];

int d[300005];
int tkd[300005][20];

void dfs(int i,int p){
	for (auto &it:al[i]){
		if (it==p) continue;
		
		int curr=tkd[it][0]=i;
		rep(x,0,19){
			if (curr==-1) break;
			curr=tkd[it][x+1]=tkd[curr][x];
		}
		d[it]=d[i]+1;
		dfs(it,i);
	}
}

int mov(int i,int j){
	rep(x,0,20) if (j&(1<<x)) i=tkd[i][x];
	return i;
}

int lca(int i,int j){
	if (d[i]<d[j]) swap(i,j);
	i=mov(i,d[i]-d[j]);
	if (i==j) return i;
	
	rep(x,20,0) if (tkd[i][x]!=tkd[j][x]) i=tkd[i][x],j=tkd[j][x];
	return tkd[i][0];
}

int dist(int i,int j){
	int g=lca(i,j);
	return d[i]+d[j]-2*d[g];
}

vector<int> v;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		
		rep(x,1,n+1) al[x].clear();
		
		int a,b;
		rep(x,1,n){
			cin>>a>>b;
			al[a].pub(b);
			al[b].pub(a);
		}
		
		rep(x,1,n+1) rep(y,0,20) tkd[x][y]=-1;
		dfs(1,-1);
		
		v.clear();
		vector<int> idx;
		rep(x,1,n+1) idx.pub(x);
		
		sort(all(idx),[](int i,int j){
			return d[i]<d[j];
		});
		
		a=b=-1;
		rep(x,n+1,1){
			while (!idx.empty() && d[idx.back()]==x){
				if (a==-1) a=b=idx.back();
				else{
					int wa=dist(a,b),wb=dist(a,idx.back()),wc=dist(b,idx.back());
					
					if (wa>=wb && wa>=wc) ;
					else if (wb>=wc) b=idx.back();
					else a=idx.back();
				}
				idx.pob();
			}
			
			int ans=1e9;
			if (a!=-1){
				int rad=(dist(a,b)+1)/2;
				ans=x-rad;
			}
			
			v.pub(ans);
		}
		
		reverse(all(v));
		
		int i=0;
		rep(x,1,n+1){
			while (v[i]<=x) i++;
			cout<<i<<" ";
		}
		
		cout<<endl;
	}
}