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

const ll INF=1e18;

struct line{
	ll m,c;
	
	line (ll _m,ll _c){
		m=_m,c=_c;
	}
	
	ll get(ll x){
		return m*x+c;
	}
};

struct node{
	int s,e,m; //note that this stores for [s,e)
	line val=line(0,INF);
	node *l,*r;
	
	node(int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s+1!=e){
			l=new node(s,m);
			r=new node(m,e);
		}
	}
	
	void update(line i){
		bool lo=i.get(s)<val.get(s);
		bool mi=i.get(m)<val.get(m);
		bool hi=i.get(e)<val.get(e);
		
		if (mi) swap(i,val);
		
		if (e-s==1 || i.c==INF || lo==hi) return;
		if (lo!=mi) l->update(i);
		else r->update(i);
	}
	
	ll query(ll i){
        if (val.c==INF) return INF;
		else if (s+1==e) return val.get(i);
		else if (i<m) return min(l->query(i),val.get(i));
		else return min(r->query(i),val.get(i));
	}
	
	void clear(){
		val=line(0,INF);
		if (s+1!=e){
			l->clear(),r->clear();
		}
	}
}*root=new node(0,2005);

int n,m;
string grid[2005];
int w[2005][2005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	fac[0]=1;
	rep(x,1,1000005) fac[x]=fac[x-1]*x%MOD;
	ifac[1000004]=inv(fac[1000004]);
	rep(x,1000005,1) ifac[x-1]=ifac[x]*x%MOD;
	
	cin>>n>>m;
	n++,m++;
	rep(x,0,n) cin>>grid[x];
	
	//skill issue
	
	memset(w,63,sizeof(w));
	rep(x,0,n){
		rep(y,0,m){
			if (grid[x][y]=='1') w[x][y]=0;
		}
		rep(y,1,m){
			w[x][y]=min(w[x][y-1]+1,w[x][y]);
		}
		rep(y,m-1,0){
			w[x][y]=min(w[x][y+1]+1,w[x][y]);
		}
	}
	
	ll ans=0;
	rep(y,0,m){
		root->clear();
		rep(x,0,n) if (w[x][y]<1e9) root->update(line({-2*x,w[x][y]*w[x][y]+x*x}));
		rep(x,0,n){
			//cout<<x<<" "<<y<<" "<<root->query(x)+x*x<<endl;
			ans+=root->query(x)+x*x;
		}
	}
	
	cout<<ans<<endl;
}