#include <bits/stdc++.h>
using namespace std;

#define debug

#define ll long long
#define pii pair<int,int>
#define pdd pair<double,double>
#define ldouble long double
const ll MOD = 1e9+7;
const int INF = 0x7f7f7f7f;
const ll INFLL = 0x7f7f7f7f7f7f7f7f;

#define End return 0; }
#define of ios::sync_with_stdio(0); cin.tie(0);
#define story int main() {
#define The

The story of YAY_OR_NAY:

	string s;
	int n, k;
	cin >> n >> k;
	cin >> s;
	int count[26];
	memset(count, 0, sizeof(count));
	int m = 0;
	for (int i = 0; i < n; i++) {
		count[s[i]-'a']++;
		m = max(m, count[s[i]-'a']);
	}
	if (m > k) cout << "NO" << endl;
	else cout << "YES" << endl;

The End