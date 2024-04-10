// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
using namespace std;

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

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
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

ll inv(ll i){
	return qexp(i,MOD-2,MOD);
}

ll fix(ll i){
	i%=MOD;
	if (i<0) i+=MOD;
	return i;
}

ll fac[1000005];
ll ifac[1000005];

ll nCk(int i,int j){
	if (i<j) return 0;
	return fac[i]*ifac[j]%MOD*ifac[i-j]%MOD;
}

int n,k;
vector<int> al[200005];
int ss[200005];

map<ii,ii> memo; //(size,ans)
int pp[200005];
ii res[200005];
int bad[200005];

ii dfs(int i,int p){
	if (memo.count(ii(i,p))) return memo[ii(i,p)];
	
	if (pp[i]==-1){
		res[i].fi=1;
		
		pp[i]=p;
		for (auto it:al[i]){
			if (it==p) continue;
			auto temp=dfs(it,i);
			res[i].fi=(res[i].fi+temp.fi)%MOD;
			res[i].se=(res[i].se+temp.se)%MOD;
			bad[i]=(bad[i]+nCk(temp.fi,k))%MOD;
		}
		
		int ans=(res[i].se+(nCk(res[i].fi,k)-bad[i]+MOD)*res[i].fi)%MOD;
		return memo[ii(i,p)]={res[i].fi,ans};
	}
	else{
		auto val=res[i];
		auto t1=p==-1?ii(0,0):dfs(p,i),t2=dfs(pp[i],i);
		val.fi=(val.fi-t1.fi+t2.fi+MOD)%MOD;
		val.se=(val.se-t1.se+t2.se+MOD)%MOD;
		int bad2=(bad[i]-nCk(t1.fi,k)+nCk(t2.fi,k)+MOD)%MOD;
		
		int ans=(val.se+(nCk(val.fi,k)-bad2+MOD)*val.fi)%MOD;
		return memo[ii(i,p)]={val.fi,ans};
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	fac[0]=1;
	rep(x,1,1000005) fac[x]=fac[x-1]*x%MOD;
	ifac[1000004]=inv(fac[1000004]);
	rep(x,1000005,1) ifac[x-1]=ifac[x]*x%MOD;
	
	cin>>n>>k;
	
	int a,b;
	rep(x,1,n){
		cin>>a>>b;
		al[a].pub(b);
		al[b].pub(a);
	}
	
	memset(pp,-1,sizeof(pp));
	dfs(a,b);
	dfs(b,a);
	
	int ans=0;
	rep(x,1,n+1){
		auto temp=dfs(x,-1);
		ans=(ans+temp.se)%MOD;
	}
	
	cout<<ans<<endl;
}