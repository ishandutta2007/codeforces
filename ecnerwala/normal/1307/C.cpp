#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1.1e5;
int N;
string S;
ll cnt[26];
ll val[26][26];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> S; N = int(S.size());
	ll ans = 0;
	for (char c : S) {
		for (int i = 0; i < 26; i++) {
			ans = max(ans, val[c - 'a'][i] += cnt[i]);
		}
		ans = max(ans, ++cnt[c - 'a']);
	}
	cout << ans << '\n';

	return 0;
}