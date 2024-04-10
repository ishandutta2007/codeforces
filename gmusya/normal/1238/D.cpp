#include <iostream>
#include <vector>
#include <string>

typedef long long ll;

using namespace std;

int main() {
	ll n;
	cin >> n;
	string s;
	cin >> s;
	vector <ll> a;
	ll cur = 0;
	for (ll i = 0; i < n; i++) {
		if (i > 0 && s[i] != s[i - 1]) {
			a.push_back(cur);
			cur = 0;
		}
		cur++;
	}
	a.push_back(cur);
	ll bad = 0;
	for (ll i = 0; i < a.size() - 1; i++)
		bad += a[i] + a[i + 1];
	cout << n * (n - 1) / 2 - (bad - a.size() + 1);
	return 0;
}