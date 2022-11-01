#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <ll> a(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	vector <ll> pre(n + 1);
	for (int i = 1; i <= n; i++)
		pre[i] = pre[i - 1] + a[i];
	map <ll, vector <int>> m;
	for (int i = 0; i <= n; i++)
		m[pre[i]].push_back(i);
	vector <int> ravn(n + 1);
	for (auto now : m) {
		for (int i = 1; i < now.second.size(); i++) 
			ravn[now.second[i]] = now.second[i - 1] + 1;
	}
	for (int i = 1; i <= n; i++)
		ravn[i] = max(ravn[i], ravn[i - 1]);
	ll ans = 0;
	for (int i = 1; i <= n; i++)
		ans += (i - ravn[i]);
	cout << ans;
	return 0;
}