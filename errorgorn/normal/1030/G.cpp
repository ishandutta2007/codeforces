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

const int MOD=1000000007;

ll qexp(ll b,ll p,int m){
    ll res=1;
    while (p){
        if (p&1) res=(res*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return res;
}


int n;
int arr[200005];

int cnt[2000005];
vector<ii> fac[2000005];
ii num[2000005];

void add(int i,int j){
	if (num[i].fi<j) num[i]={j,0};
	if (num[i].fi==j) num[i].se++;
}

vector<int> v;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	rep(x,2,2000005) if (fac[x].empty()){
		for (int y=x;y<2000005;y+=x){
			int curr=y;
			int num=0;
			while (curr%x==0){
				curr/=x;
				num++;
			}
			fac[y].pub({x,num});
		}
	}
	
	// rep(x,0,20){
		// cout<<x<<": ";
		// for (auto it:fac[x]) cout<<it.fi<<"_"<<it.se<<" "; cout<<endl;
	// }
	
	cin>>n;
	rep(x,1,n+1) cin>>arr[x];
	
	rep(x,1,n+1) cnt[arr[x]]++;
	
	rep(x,0,2000005) if (cnt[x]>=2){
		v.pub(x);
		add(x,1);
		
		rep(y,1,cnt[x]){
			v.pub(x-1);
			for (auto it:fac[x-1]) add(it.fi,it.se);
		}
	}
	
	rep(x,2000005,0) if (cnt[x]==1){
		if (num[x].fi==0){
			v.pub(x);
			add(x,1);
		}
		else{
			v.pub(x-1);
			for (auto it:fac[x-1]) add(it.fi,it.se);
		}
	}
	
	bool add=false;
	for (auto x:v){
		bool rem=true;
		for (auto it:fac[x]) if (num[it.fi]==ii(it.se,1)) rem=false;
		if (rem) add=true;
	}
	
	int ans=1;
	rep(x,1,2000005) ans=ans*qexp(x,num[x].fi,MOD)%MOD;
	if (add) ans=(ans+1)%MOD;
	
	cout<<ans<<endl;
}