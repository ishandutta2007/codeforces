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

ll fix(ll i){
	i%=MOD;
	if (i<0) i+=MOD;
	return i;
}

int n;
vector<int> al[100005];
vector<int> divi;
int cnt[100005];

int sz[100005];

void dfs(int i,int p){
	sz[i]=1;
	
	for (auto &it:al[i]){
		if (it==p) continue;
		
		dfs(it,i);
		sz[i]+=sz[it];
	}
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
		
		rep(x,1,n+1) al[x].clear();
		divi.clear();
		rep(x,1,n+1) cnt[x]=0;
		
		int a,b;
		rep(x,1,n){
			cin>>a>>b;
			al[a].pub(b);
			al[b].pub(a);
		}
		
		dfs(1,-1);
		
		rep(x,1,n) if ((n-1)%x==0) divi.pub(x);
		
		cnt[1]=qexp(2,n-1,MOD);
		rep(x,1,sz(divi)){
			bool can=true;
			rep(y,2,n+1){
				if (sz[y]%divi[x]>1) can=false;
			}
			
			cnt[divi[x]]=can;
		}
		
		rep(x,sz(divi),0) rep(y,x+1,sz(divi)){
			if (divi[y]%divi[x]==0){
				cnt[divi[x]]=fix(cnt[divi[x]]-cnt[divi[y]]);
			}
		}
		
		rep(x,1,n+1) cout<<cnt[x]<<" "; cout<<endl;
	}
}