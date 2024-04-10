//
//

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

int n;
vector<int> al[300005];
int w[300005];
int pp[300005];

void dfs(int i,int p){
	for (auto &it:al[i]){
		if (it==p) continue;
		
		pp[it]=i;
		dfs(it,i);
		w[i]^=(w[it]+1);
	}
}

bool used[300005];

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
	
	dfs(1,-1);
	
	int ans=0;
	rep(x,1,n+1){
		if (x==1){
			used[1]=true;
			for (auto &it:al[1]){
				ans^=(w[it]+1);
			}
		}
		else if (!used[x]){
			int curr=x;
			while (true){
				ans^=1;
				
				for (auto &it:al[curr]){
					if (it==pp[curr] || used[it]) continue;
					ans^=(w[it]+1);
				}
				
				used[curr]=true;
				if (used[pp[curr]]){
					ans^=(w[curr]+1);
					break;
				}
				curr=pp[curr];
			}
		}
		
		if (ans) cout<<1;
		else cout<<2;
	}
}