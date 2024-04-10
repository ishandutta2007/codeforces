#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

ll powerMod(ll a, ll x, ll mod){
	if(x == 0)
		return 1;
	if(x%2){
		return (a*powerMod((a*a)%mod, x/2, mod))%mod;
	}
	return powerMod((a*a)%mod, x/2, mod);
}

bool vis[1000005];

int main(){
	ll p, k;
	scanf("%I64d%I64d", &p, &k);
	if(!k){
		printf("%I64d\n", powerMod(p, p-1, MOD));
		return 0;
	}
	if(k == 1){
		printf("%I64d\n", powerMod(p, p, MOD));
		return 0;
	}
	ll ans=1;
	for(int i=1; i < p; ++i){
		if(vis[i])
			continue;
		ans=(ans*p)%MOD;
		ll cur=i;
		cur=(cur*k)%p;
		while(cur != i){
			vis[cur]=true;
			cur=(cur*k)%p;
		}
	}
	printf("%I64d\n", ans);
}