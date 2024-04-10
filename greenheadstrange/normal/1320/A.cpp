#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
int n;
int b[maxn]; 
int main() {
	cin >> n;
	vector<pi> s;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		s.pb(mp(b[i] - i, b[i]));
	} 
	sort(s.begin(), s.end());
	ll ans = 0;
	for (int i = 0; i < s.size(); ) {
		int j = i;
		ll c = 0;
		while (j < s.size() && s[j].fi == s[i].fi)
			c += s[j].se, j++;
		ans = max(ans, c);
		i = j;
	}
	cout << ans << endl;
	return 0;
}