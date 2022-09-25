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

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int MOD;

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

ll fac[2005];
ll ifac[2005];

ll nCk(int i,int j){
	if (i<j) return 0;
	return fac[i]*ifac[j]%MOD*ifac[i-j]%MOD;
}

int n;
vector<int> al[2005];
int memo[2005][2005];

void dfs(int i,int p){
	vector<int> child;
	for (auto it:al[i]){
		if (it==p) continue;
		child.pub(it);
	}
	
	for (auto it:child) dfs(it,i);
	
	vector<int> res=vector<int>(sz(child),0);
	int minus=0;
	rep(x,1,2005){
		vector<int> f={1};
		for (auto it:child) f.pub(memo[it][x]);
		f.pub(1);
		vector<int> b=f;
		reverse(all(b));
		rep(x,1,sz(f)) f[x]=f[x]*f[x-1]%MOD;
		rep(x,1,sz(b)) b[x]=b[x]*b[x-1]%MOD;
		reverse(all(b));
		
		rep(y,0,sz(child)) res[y]=(res[y]+f[y]*b[y+2])%MOD;
		minus=(minus+(sz(child)-1)*f.back())%MOD;
		
		memo[i][x]=(MOD-minus)%MOD;
		rep(y,0,sz(child)) memo[i][x]=(memo[i][x]+res[y]*memo[child[y]][x])%MOD;
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>MOD;
	
	fac[0]=1;
	rep(x,1,2005) fac[x]=fac[x-1]*x%MOD;
	ifac[2004]=inv(fac[2004]);
	rep(x,2005,1) ifac[x-1]=ifac[x]*x%MOD;
	
	int a,b;
	rep(x,1,n){
		cin>>a>>b;
		al[a].pub(b);
		al[b].pub(a);
	}
	
	rep(x,1,2005) memo[1][x]=1;
	for (auto it:al[1]){
		dfs(it,1);
		rep(x,1,2005) memo[1][x]=memo[1][x]*memo[it][x]%MOD;
	}
	
	//rep(x,1,n+1) cout<<memo[1][x]<<" "; cout<<endl;
	rep(x,1,n){
		rep(y,1,x) memo[1][x]=fix(memo[1][x]-memo[1][y]*nCk(x,y));
		cout<<memo[1][x]<<" ";
	} cout<<endl;
}