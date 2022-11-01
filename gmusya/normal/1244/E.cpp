#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, k;
	cin >> n >> k;
	vector <ll> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());	
	deque <pair <ll, ll>> dq;
	ll val = a[0], cnt = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] != val) {
			dq.push_back({ val, cnt });
			val = a[i];
			cnt = 0;
		}
		cnt++;
	}
	dq.push_back({ val, cnt });
	while (dq.size() > 1 && k) {
		if (dq.back().second < dq.front().second) {
			pair <ll, ll> tmp = dq.back();
			if (k < tmp.second) break;
			dq.pop_back();
			ll val1 = tmp.first - dq.back().first;
			ll val2 = k / tmp.second;
			ll val = min(val1, val2);
			tmp.first -= val;
			k -= val * tmp.second;
			if (dq.back().first == tmp.first)
				dq.back().second += tmp.second;
			else 
				dq.push_back(tmp);
			continue;
		}
		pair <ll, ll> tmp = dq.front();
		if (k < tmp.second) break;
		dq.pop_front();
		ll val1 = dq.front().first - tmp.first;
		ll val2 = k / tmp.second;
		ll val = min(val1, val2);
		tmp.first += val;
		k -= val * tmp.second;
		if (dq.front().first == tmp.first)
			dq.front().second += tmp.second;
		else
			dq.push_front(tmp);
	}
	cout << dq.back().first - dq.front().first;
	return 0;
}