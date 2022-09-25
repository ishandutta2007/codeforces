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
#define iii tuple<int,int,int>
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

ll inv(ll i){
	return qexp(i,MOD-2,MOD);
}

vector<int> fac[200005];

int n;
vector<iii> al[200005];
int cnt[200005]; //number of factors

int ans;
int curr;

void dfs(int i,int p,int w){
	
	for (auto [it,a,b]:al[i]){
		if (it==p) continue;
		
		//check if we need to update things
		for (auto it2:fac[a]){
			cnt[it2]--;
			if (cnt[it2]==-1){
				cnt[it2]++;
				ans=(ans*it2)%MOD;
				curr=(curr*it2)%MOD;
			}
		}
		for (auto it2:fac[a]) cnt[it2]++;
	}
	
	// cout<<"debug: "<<i<<" "<<p<<" "<<ans<<" "<<curr<<endl;
	// cout<<ans<<" "<<curr<<endl;
	
	for (auto [it,a,b]:al[i]){
		if (it==p) continue;
		
		//now change the cnt array to the child
		
		for (auto it2:fac[a]) cnt[it2]--;
		for (auto it2:fac[b]) cnt[it2]++;
		
		int temp=curr;
		curr=curr*w%MOD*inv(a)%MOD;
		ans=(ans+curr*b)%MOD;
		dfs(it,i,b);
		curr=curr*inv(w)%MOD*a%MOD;
		
		for (auto it2:fac[a]) cnt[it2]++;
		for (auto it2:fac[b]) cnt[it2]--;
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	rep(x,2,200005) if (fac[x].empty()){
		for (int y=x;y<200005;y+=x){
			int yy=y;
			while (yy%x==0){
				fac[y].pub(x);
				yy/=x;
			}
		}
	}
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,1,n+1) al[x].clear();
		
		int a,b,c,d;
		ans=0;
		rep(x,1,n){
			cin>>a>>b>>c>>d;
			
			int g=__gcd(c,d);
			c/=g,d/=g;
			
			al[a].pub({b,c,d});
			al[b].pub({a,d,c});
		}
		
		int s;
		rep(x,1,n+1) if (sz(al[x])==1) s=x;
		
		rep(x,1,n+1) cnt[x]=0;
		
		for (auto it:fac[get<2>(al[s][0])]) cnt[it]++;
		ans=get<1>(al[s][0])+get<2>(al[s][0]);
		curr=1;
		dfs(get<0>(al[s][0]),s,get<2>(al[s][0]));
		cout<<ans<<endl;
	}
}