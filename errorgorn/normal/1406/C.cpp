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
#define debug(x) cout << #x << " is " << x << endl

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
vector<int> al[100005];
int ss[100005];

int u,v;
void dfs(int i,int p){
	ss[i]=1;
	for (auto &it:al[i]){
		if (it==p) continue;
		
		dfs(it,i);
		ss[i]+=ss[it];
	}
	if (ss[i]==n/2) u=p,v=i;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		
		rep(x,0,n+1) al[x].clear();
		
		int a,b;
		rep(x,1,n){
			cin>>a>>b;
			al[a].push_back(b);
			al[b].push_back(a);
		}
		
		if (n%2==1){
			cout<<a<<" "<<b<<endl;
			cout<<a<<" "<<b<<endl;
			continue;
		}
		
		u=v=-1;
		dfs(1,-1);
		
		if (u==-1){
			cout<<a<<" "<<b<<endl;
			cout<<a<<" "<<b<<endl;
		}
		else{
			for (auto &it:al[u]){
				if (it!=v){
					cout<<u<<" "<<it<<endl;
					cout<<v<<" "<<it<<endl;
					break;
				}
			}
		}
		
	}
}