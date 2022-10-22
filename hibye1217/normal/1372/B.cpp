#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define fr first
#define sc second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
	Fast;
	int t;
	cin >> t;
	while (t--){
		ll n;
		cin >> n;
		bool f = false;
		for (ll i = 2; i*i <= n; i++){
			if (n % i == 0){
				cout << n/i << ' ' << (i-1)*n/i << endl;
				f = true;
				break;
			}
		}
		if (!f) cout << 1 << ' ' << n-1 << endl;
	}
}