#include <bits/stdc++.h>
using namespace std;
typedef long ll;
typedef pair<ll, ll> pp;
#define MAX 1010101
#define MOD 993244853
#define INF 2147483647
#define pb push_back
#define all(v) v.begin(), v.end()
#define abs(x) ((x)>0?(x):-(x))
#define sortv(v) sort(all(v))
#define sortvc(v, cmp) sort(all(v), cmp)
#define ln '\n'
void init() { 
	ios::sync_with_stdio(false);
	cin.tie(0);
}
void solve() {
	string str;
	cin >> str;
	ll i;
	ll c = 0;
	for (i = 0; str[i]; i++) {
		if (c) {
			if (str[i] == 'z') str[i] = 'y';
			else str[i] = 'z';
			c = 0;
		}
		else {
			if (str[i] == 'a') str[i] = 'b';
			else str[i] = 'a';
			c = 1;
		}
	}
	cout << str << ln;
}
int main() {
	init();
	ll T;
	cin >> T;
	while (T-- > 0) solve();
	return 0;
}