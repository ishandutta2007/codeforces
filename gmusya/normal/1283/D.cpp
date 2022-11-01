#include <iostream>
#include <vector>
#include <set>
#include <map>

#define ll long long
using namespace std;

int main() {
	ll n, m;
	cin >> n >> m;
	vector <ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	set <ll> used;
	set <pair <ll, ll>> s;
	ll cnt = 0;
	ll ans = 0;
	for (ll i = 0; i < n; i++)
		used.insert(a[i]);
	for (ll i = 0; i < n; i++) {
		if (used.find(a[i] + 1) == used.end())
			s.insert({ 1, a[i] + 1 });
		if (used.find(a[i] - 1) == used.end())
			s.insert({ 1, a[i] - 1 });
		used.insert(a[i]);
		used.insert(a[i] - 1);
		used.insert(a[i] + 1);
	}
	vector <ll> guys;
	while (cnt < m) {
		pair <ll, ll> temp = *s.begin();
		s.erase(temp);
		used.insert(temp.second);
		guys.push_back(temp.second);
		ans += temp.first;
		if (used.find(temp.second + 1) == used.end())
			s.insert({ temp.first + 1, temp.second + 1 });
		if (used.find(temp.second - 1) == used.end())
			s.insert({ temp.first + 1, temp.second - 1 });
		used.insert(temp.second + 1);
		used.insert(temp.second - 1);
		cnt++;
	}
	cout << ans << endl;
	for (auto now : guys)
		cout << now << " ";
	return 0;
}