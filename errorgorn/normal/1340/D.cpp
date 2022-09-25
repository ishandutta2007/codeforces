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

int n;
vector<int> al[100005];
int d[100005]; //deg ig

vector<ii> ans;
int TIME=0;

void dfs(int i,int p){
	int goal=TIME-1;
	
	ans.push_back(ii(i,TIME++));
	
	if (TIME+d[i]-1!=goal && goal-d[i]>=0){
		TIME=goal-d[i];
		ans.push_back(ii(i,TIME++));
	}
	
	for (auto &it:al[i]){
		if (it==p) continue;
		
		d[i]--;
		
		dfs(it,i);
		
		ans.push_back(ii(i,TIME++));
		
		if (TIME+d[i]-1!=goal && goal-d[i]>=0){
			TIME=goal-d[i];
			ans.push_back(ii(i,TIME++));
		}
	}
	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	
	int a,b;
	rep(x,1,n){
		cin>>a>>b;
		
		al[a].push_back(b);
		al[b].push_back(a);
		
		d[a]++,d[b]++;
	}
	
	rep(x,1,n+1) d[x]--;
	
	for (auto &it:al[1]){
		ans.push_back(ii(1,TIME++));
		
		dfs(it,1);
	}
	ans.push_back(ii(1,TIME));
	
	cout<<sz(ans)<<endl;
	for (auto &it:ans) cout<<it.fi<<" "<<it.se<<endl;
}