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

ll powerMod(ll a, ll x){
	if(!x)return 1;
	if(x%2)
		return (a*powerMod((a*a)%MOD, x/2))%MOD;
	return powerMod((a*a)%MOD, x/2);
}

ll inv(ll a){
	return powerMod(a, MOD-2);
}

ll nCr[2000005];

int main(){
	int N;
	scanf("%d", &N);
	ll ans=powerMod(2, N+1)-1;
	nCr[N]=1;
	rep(n,N+1,2*N+1){
		nCr[n]=(((nCr[n-1]*n)%MOD)*inv(n-N))%MOD;
	}
	ll add=nCr[2*N];
	rrep(n,2*N+1,N+1){
		ans += add;
		add=add*inv(2)+nCr[n-1];
		add%=MOD;
	}
	ans%=MOD;
	cout << ans << endl;
}