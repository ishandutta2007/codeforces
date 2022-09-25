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

const int B=400;

int n,q;
ii arr[200005];

int	small[B+5][B+5];
int big[200005];

int op[200005];

int pos[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	fac[0]=1;
	rep(x,1,1000005) fac[x]=fac[x-1]*x%MOD;
	ifac[1000004]=inv(fac[1000004]);
	rep(x,1000005,1) ifac[x-1]=ifac[x]*x%MOD;
	
	
	cin>>n>>q;
	rep(x,1,n+1) cin>>arr[x].fi>>arr[x].se;
	
	int a,b;
	rep(x,0,q){
		cin>>a>>b;
		if (a==1) op[x]=b;
		else op[x]=-b;
	}
	
	memset(pos,-1,sizeof(pos));
	
	rep(x,0,q){
		int temp=abs(op[x]);
		if (arr[temp].fi+arr[temp].se<=B) continue;
		
		if (op[x]>0) pos[temp]=x;
		else{
			int l=pos[temp],r=x;
			
			pos[temp]=-1;
			
			while (true){
				if (l+arr[temp].fi>=r) break;
				l+=arr[temp].fi;
				big[l]++;
				if (l+arr[temp].se>=r){
					big[r]--;
					break;
				}
				l+=arr[temp].se;
				big[l]--;
			}
		}
	}
	
	rep(x,1,n+1) if (pos[x]!=-1){
		int l=pos[x],r=q;
		int temp=x;
		
		while (true){
			if (l+arr[temp].fi>=r) break;
			l+=arr[temp].fi;
			big[l]++;
			if (l+arr[temp].se>=r){
				big[r]--;
				break;
			}
			l+=arr[temp].se;
			big[l]--;
		}
	}
	
	int curr=0;
	rep(x,0,q){
		int temp=abs(op[x]);
		if (arr[temp].fi+arr[temp].se<=B){
			if (op[x]>0) pos[temp]=x;
			int add=(op[x]>0?1:-1);
			
			int ped=arr[temp].fi+arr[temp].se;
			
			rep(y,arr[temp].fi,arr[temp].fi+arr[temp].se){
				//cout<<ped<<" "<<(pos[temp]+y)%ped<<" "<<add<<endl;
				small[ped][(pos[temp]+y)%ped]+=add;
			}
		}
		
		curr+=big[x];
		
		int ans=curr;
		rep(y,1,B+1) ans+=small[y][x%y];
		
		cout<<ans<<endl;
	}
}