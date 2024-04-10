#include<iostream>
#include<iomanip>
#include<math.h>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#define REP(i, N) for(ll i = 0; i < N; ++i)
#define FOR(i, a, b) for(ll i = a; i < b; ++i)
#define ALL(a) (a).begin(),(a).end()
#define pb push_back
#define INF (long long)1000000000
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
	ll x, y, l, r;
	cin>>x>>y>>l>>r;
	vector<ll> res;
	ll a = 1;
	ll b = 1;
	while(a + b <= r) {
		while(a + b <= r) {
			if(a + b >= l) res.pb(a + b);
			if(log10(b) + log10(y) <= 18.0000001) b *= y;
			else break;
		}
		if(log10(a) + log10(x) <= 18.0000001) a *= x;
		else break;
		b = 1;
	}
	sort(ALL(res));
	ll ans = 0;
	if(res.size() == 0) cout<<r - l + 1<<endl;
	else {
	ans = res[0] - l;
	FOR(i, 1, res.size()) {
		ans = max(ans, res[i] - res[i - 1] - 1);
	}
	ans = max(ans, r - res[res.size() - 1]);
	cout<<ans<<endl;
	}
}