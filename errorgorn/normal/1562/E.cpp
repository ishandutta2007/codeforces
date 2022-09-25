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

//ok fine why the fuck would you MLE treap

int n;
string s;
int memo[5005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	fac[0]=1;
	rep(x,1,1000005) fac[x]=fac[x-1]*x%MOD;
	ifac[1000004]=inv(fac[1000004]);
	rep(x,1000005,1) ifac[x-1]=ifac[x]*x%MOD;
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		cin>>s;
		
		rep(x,0,n) memo[x]=0;
		
		vector<int> idx;
		rep(x,0,n) idx.pub(x);
		
		sort(all(idx),[](int i,int j){
			int cnt=1;
			while (true){
				if (max(i,j)+cnt==n+1){
					return i>j;
				}
				if (s[i+cnt-1]!=s[j+cnt-1])
					return s[i+cnt-1]<s[j+cnt-1];
				
				cnt++;
			}
		});
		
		//for (auto &it:idx) cout<<it<<" "; cout<<endl;
		
		rep(x,0,n){
			int pos=0;
			int curr=0;
			
			rep(y,0,n-x){
				while (s[idx[pos]+y]<s[x+y]){
					curr=max(curr,memo[idx[pos]]);
					pos++;
				}
				curr++;
			}
			
			memo[x]=curr;
		}
		
		int ans=0;
		rep(x,0,n) ans=max(ans,memo[x]);
		
		cout<<ans<<endl;
	}
}