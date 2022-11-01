#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

void ne() {
	cout << "No\n";
	exit(0);
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, t;
	cin >> n >> t;
	string s;
	cin >> s;
	t -= (1 << (s[n - 1] - 'a')) - (1 << (s[n - 2] - 'a'));
	ll kolko[30] = {0};
	for(int i = 0; i < n - 2; i++) kolko[s[i] - 'a']++;
	ll maxi = 0, mini = 0;
	REP(i, 30) {
		maxi += (ll) kolko[i] * (1 << i);
		mini -= (ll) kolko[i] * (1 << i);
	}
	if(mini > t || maxi < t) ne();
	for(int i = 29; i >= 0; i--) {
		ll raz = maxi - t;
		ll kol = raz / (1 << (i + 1));
		maxi -= (ll) min(kol, kolko[i]) * (1 << (i + 1));
	}
	if(maxi == t) cout << "Yes\n";
	else ne();
	return 0;
}