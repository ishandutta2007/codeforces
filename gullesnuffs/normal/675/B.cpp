#include <bits/stdc++.h>
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

int main(){
	int n, a, b, c, d;
	scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
	ll ans=0;
	rep(mid,1,n+1){
		int lo=1, hi=n;
		lo=max(lo, 1+a+c-(a+b));
		hi=min(hi, n+a+c-(a+b));
		lo=max(lo, 1+d+c-(a+b));
		hi=min(hi, n+d+c-(a+b));
		lo=max(lo, 1+d+b-(a+b));
		hi=min(hi, n+d+b-(a+b));
		if(hi >= lo)
			ans += hi-lo+1;
	}
	printf("%I64d\n", ans);
}