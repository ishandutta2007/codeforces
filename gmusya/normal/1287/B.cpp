#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

#define ll long long
using namespace std;

int main() {
	ll n, k;
	cin >> n >> k;
	vector <string> s(n);
	map <string, ll> m;
	for (ll i = 0; i < n; i++) {
		cin >> s[i];
		m[s[i]]++;
	}
	vector <pair <string, ll>> arr;
	for (auto now : m)
		arr.push_back(now);
	ll ans = 0;
	for (ll i = 0; i < arr.size() - 1; i++)
		for (ll j = i + 1; j < arr.size(); j++) {
			if (j == i)
				continue;
			string hm;
			for (ll z = 0; z < k; z++) {
				if (s[i][z] == s[j][z])
					hm += s[i][z];
				else
					hm += ((char)('S' + 'E' + 'T' - (s[i][z] + s[j][z])));
			}
			if (hm > s[j] || hm > s[i])
				continue;
			ans += m[hm] * m[arr[i].first] * m[arr[j].first];
		}
	for (ll i = 0; i < arr.size(); i++)
		ans += max((ll) 0, (arr[i].second - 2) * (arr[i].second - 1) * (arr[i].second) / 6);
	cout << ans;
	return 0;
}