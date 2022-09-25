//
//

#include <bits/stdc++.h>
using namespace std;
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

#define dd double
#define di pair<dd,int>

const int SZ=1000005;

int n;
int arr[SZ];
priority_queue<di,vector<di>,greater<di> > pq;

struct UFDS{
	int p[SZ];
	dd val[SZ];
	int l[SZ];
	int r[SZ];
	
	UFDS(){
		rep(x,0,SZ){
			p[x]=l[x]=r[x]=x;
			val[x]=arr[x];
		}
	}
	
	int par(int i){
		if (i==p[i]) return i;
		else return p[i]=par(p[i]);
	}
	
	void unions(int i,int j){
		i=par(i),j=par(j);
		
		p[i]=j;
		val[j]=(val[i]*(r[i]-l[i]+1)+val[j]*(r[j]-l[j]+1));
		l[j]=min(l[i],l[j]);
		r[j]=max(r[i],r[j]);
		
		val[j]/=(r[j]-l[j]+1);
	}
} ;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	fac[0]=1;
	rep(x,1,1000005) fac[x]=fac[x-1]*x%MOD;
	ifac[1000004]=inv(fac[1000004]);
	rep(x,1000005,1) ifac[x-1]=ifac[x]*x%MOD;
	
	cin>>n;
	rep(x,0,n) cin>>arr[x];
	
	UFDS ufds=UFDS();
	
	rep(x,0,n) pq.push(ii(ufds.val[ufds.par(x)],ufds.par(x)));
	
	int pos;
	while (!pq.empty()){
		pos=pq.top().se,pq.pop();
		if (ufds.par(pos)!=pos) continue;
		if (ufds.l[pos]==0) continue;
		
		int temp=ufds.par(ufds.l[pos]-1);
		if (ufds.val[temp]>=ufds.val[pos]){
			ufds.unions(temp,pos);
			pq.push(ii(ufds.val[ufds.par(pos)],ufds.par(pos)));
		}
		
		//rep(x,0,n) cout<<ufds.val[ufds.par(x)]<<" "; cout<<endl;
	}
	
	rep(x,0,n){
		cout<<fixed<<setprecision(12)<<ufds.val[ufds.par(x)]<<endl;
	}
}