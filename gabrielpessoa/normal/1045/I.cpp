#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
 
map<int, int> freq;
const int N = 26; 
 
int id(char c) {
	return c - 'a';
}
 
int main() {
  cin.tie(0); ios::sync_with_stdio(0);
	int n;
	cin >> n;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		string s;
    cin >> s;
		int mask = 0;
		for (int j = 0; j < (int) s.size(); j++) {
			mask ^= 1ll << id(s[j]);
		}
		for (int j = 0; j < N; j++) {
      ans += freq[mask ^ (1 << j)];
		}
		ans += freq[mask]++;
	}
	cout << ans << '\n';
	return 0;
}