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

const int MOD=998244353;

ll qexp(ll b,ll p,int m){
    ll res=1;
    while (p){
        if (p&1) res=(res*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return res;
}

ll inv(int i){
	return qexp(i,MOD-2,MOD);
}

ll fix(ll i){
	i%=MOD;
	if (i<0) i+=MOD;
	return i;
}


int n,m;
vector<int> al[100005];
bool vis[100005];
vector<int> topo;
int g[100005];

void dfs(int i){
	vis[i]=true;
	
	for (auto &it:al[i]){
		if (!vis[it]) dfs(it);
	}
	topo.push_back(i);
}

int cnt[520];
ll mat[520][520];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m;
	
	int a,b;
	rep(x,0,m){
		cin>>a>>b;
		al[a].push_back(b);
	}
	
	rep(x,1,n+1) if (!vis[x]) dfs(x);
	
	for (auto &it:topo){
		set<int> s;
		for (auto &it2:al[it]) s.insert(g[it2]);
		
		int curr=0;
		while (s.count(curr)) curr++;
		g[it]=curr;
		cnt[g[it]]++;
	}
	
	//rep(x,1,n+1) cout<<g[x]<<" "; cout<<endl;
	
	rep(x,0,512){
		rep(y,0,512){
			mat[x][y]=cnt[x^y]*inv(n+1)%MOD;
		}
		mat[x][x]=fix(mat[x][x]-1);
	}
	mat[0][512]=fix(-inv(n+1));
	
	rep(x,0,512){
		if (mat[x][x]==0){
			rep(y,x+1,512) if (mat[y][x]){
				swap(mat[x],mat[y]);
				break;
			}
		}
		rep(y,x+1,512){
			int temp=mat[y][x]*inv(mat[x][x])%MOD;
			rep(z,0,513) mat[y][z]=fix(mat[y][z]-mat[x][z]*temp);
		}
	}
	
	rep(x,512,0){
		if (mat[x][x]==0) continue;
		rep(y,0,x){
			int temp=mat[y][x]*inv(mat[x][x])%MOD;
			rep(z,0,513) mat[y][z]=fix(mat[y][z]-mat[x][z]*temp);
		}
	}
	
	cout<<fix(1-mat[0][512]*inv(mat[0][0])%MOD)<<endl;
}