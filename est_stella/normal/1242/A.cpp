#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false);cin.tie(NULL)
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define eb emplace_back
#define pre(a) cout<<fixed; cout.precision(a)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const long long INF = 1e18;
const int inf = 1e9;

ll n;
ll ans;

int main() {
	fast;

	cin >> n;

	ans = n;

	for(ll i = 2; i*i <= n; i++) {
		while(n%i == 0) {
			n /= i;
			ans = __gcd(ans, i);
		}
	}

	if(n > 1) ans = __gcd(ans, n);

	cout << ans;
}