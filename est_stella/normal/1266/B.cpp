#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(NULL)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define pre(a) cout<<fixed; cout.precision(a)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;

bool f(ll k) {
	for(ll i=1; i<=6; i++) {
		if((k-i) % 14 == 0 && (k-i) != 0) return true;
	}

	return false;
}

int main() {
	int n;
	cin >> n;

	for(int i=1; i<=n; i++) {
		ll x;
		cin >> x;

		if(f(x)) cout << "YES\n";
		else cout << "NO\n";
	}
}