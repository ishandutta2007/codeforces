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

ll a[200005];
ll cum[200005], cum2[200005];

int main(){
	int n, k, x;
	scanf("%d%d%d", &n, &k, &x);
	rep(i,0,n)
		scanf("%I64d", a+i);
	cum[0]=0;
	rep(i,0,n)
		cum[i+1]=cum[i]|a[i];
	cum2[n]=0;
	rrep(i,n,0)
		cum2[i]=cum2[i+1]|a[i];
	ll ans=0;
	rep(i,0,n){
		ll v=a[i];
		rep(j,0,k)
			v *= x;
		ll newVal=cum[i]|cum2[i+1]|v;
		ans=max(ans, newVal);
	}
	printf("%I64d\n", ans);
}