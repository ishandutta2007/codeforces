/*

*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
typedef long long ll;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 301010
#define MOD 100000009
#define INF 1000000000000

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

//var
//

void solve() {
	string s;
	cin >> s;
	ll i;
	ll N;
	vector<ll> v(26);
	N = s.size();
	for (i = 0; i < N; i++) v[s[i] - 97]++;
	ll a, b, c;
	ll cnt = 0;
	for (i = 0; i < 26; i++) if (v[i]) cnt++;
	//case 1
	if (cnt == 1) {
		cout << s << ln;
		return;
	}
	//case 2, 3
	string ans;
	ll chk = -1;
	a = b = c = -1;
	for (i = 25; i >= 0; i--) if (v[i]) c = b, b = a, a = i;
	for (i = 0; i < 26; i++) {
		if (v[i] == 1) {
			chk = i;
			break;
		}
	}
	if (chk != -1) {
		//case 2
		ans.push_back(chk + 97);
		v[chk]--;
		for (i = 0; i < 26; i++) {
			while (v[i]) ans.push_back(i + 97), v[i]--;
		}
	}
	else if (cnt == 2) {
		if ((N - v[a]) >= v[a] - 2) {
			//aa1a2a3a4a5678
			ans.push_back(a + 97);
			ans.push_back(a + 97);
			v[a] -= 2;
			ll ptr = b;
			for (i = b; i < 26; i++) {
				while (v[i]) {
					ans.push_back(i + 97), v[i]--;
					if (v[a]) ans.push_back(a + 97), v[a]--;
				}
			}
		}
		else {
			ans.push_back(a + 97);
			v[a]--;
			while (v[b]) ans.push_back(b + 97), v[b]--;
			while (v[a]) ans.push_back(a + 97), v[a]--;
		}
	}
	else {
		if ((N - v[a]) >= v[a] - 2) {
			//aa1a2a3a4a5678
			ans.push_back(a + 97);
			ans.push_back(a + 97);
			v[a] -= 2;
			ll ptr = b;
			for (i = b; i < 26; i++) {
				while (v[i]) {
					ans.push_back(i + 97), v[i]--;
					if (v[a]) ans.push_back(a + 97), v[a]--;
				}
			}
		}
		else {
			//abaaaaaaaacb12345
			ans.push_back(a + 97);
			ans.push_back(b + 97);
			v[a]--;
			v[b]--;
			while (v[a]) ans.push_back(a + 97), v[a]--;
			ans.push_back(c + 97);
			v[c]--;
			for (i = 0; i < 26; i++) {
				while (v[i]) ans.push_back(i + 97), v[i]--;
			}			
		}
	}
	cout << ans << ln;
}

void init() {

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	tmode;
	while (T--) {
		init();
		solve();
	}
}