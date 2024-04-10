#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef complex<ld> pt;
typedef vector<pt> pol;
#define nl '\n'

///* advent of code
typedef istringstream iss;
#define pb push_back
#define ins insert
#define multiset mset
#define getl(A) getline(cin, A)
//*/

const ll INF = 0x3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-9;

ll brute(string s) {
	ll n = stoll(s);
	ll ans = 0;
	ll opt = -1;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j < i; j++) {
			ll cur = 0;
			ll temp = i+j+1;
			while (temp % 10 == 0) {
				temp /= 10;
				cur++;
			}
			if (cur > opt) {
				opt = cur;
				ans = 0;
			} 
			if (cur == opt && opt > 0) {
				ans++;
			}
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string s;
	cin >> s;
	ll len = s.size();
	
	if (s[0] < '5') {
		if (len == 1) {
			int n = stoi(s);
			cout << n*(n-1)/2 << endl;
		} else {
			ll first = s[0]-'0';
			ll second = s[1]-'0';
			string stail = s.substr(1, len);
			ll tail = stoll(stail);
			ll head = first * pow(10, len-1);
			ll ans = head * first / 2;
			if (second < 5) {
				ans += tail * first;
			} else {
				ll half = 5 * pow(10, len-2);
				ans += (half-1) * first;
				ans += (tail - (half-1))*(first+1);
			}
			bool nines = true;
			for (ll i = 0; i < stail.size(); i++) {
				if (stail[i] != '9')
					nines = false;
			}
			if (nines) {
				ans--;
			}
			cout << ans << endl;
		}
	} else {
		bool nines = true;
		for (ll i = 0; i < s.size(); i++) {
			if (s[i] != '9')
				nines = false;
		}
		ll ans = stoll(s) - 5*pow(10, len-1) + 1;
		if (nines) ans--;
		cout << ans << endl;
	}
	//cerr << brute(s) << " <-- brute" << endl;

	return 0;
}