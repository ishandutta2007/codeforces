#include <iostream>
#include <vector>

#define ll long long
#define endl '\n'
using namespace std;

int main() {
	ll n, sum = 0;
	cin >> n;
	vector <bool> used(n);
	vector <ll> x(n), y(n), c(n), k(n), stations;
	vector <pair <ll, ll>> mi(n), edges;
	for (ll i = 0; i < n; i++) 
		cin >> x[i] >> y[i];
	for (ll i = 0; i < n; i++)
		cin >> c[i];
	for (ll i = 0; i < n; i++)
		cin >> k[i];
	for (ll i = 0; i < n; i++)
		mi[i] = { c[i], -1 };
	for (ll i = 0; i < n; i++) {
		ll v = -1;
		for (ll j = 0; j < n; j++)
			if (!used[j] && (v == -1 || mi[j] < mi[v]))
				v = j;
		used[v] = true;
		sum += mi[v].first;
		if (mi[v].second == -1)
			stations.push_back(v);
		else 
			edges.push_back({ v, mi[v].second });
		for (ll j = 0; j < n; j++)
			if (mi[j].first > (abs(x[v] - x[j]) + abs(y[v] - y[j])) * (k[v] + k[j])) {
				mi[j].first = (abs(x[v] - x[j]) + abs(y[v] - y[j])) * (k[v] + k[j]);
				mi[j].second = v;
			}
	}
	cout << sum << endl;
	cout << stations.size() << endl;
	for (ll i = 0; i < stations.size(); i++)
		cout << stations[i] + 1 << " ";
	cout << endl;
	cout << edges.size() << endl;
	for (ll i = 0; i < edges.size(); i++)
		cout << edges[i].first + 1 << " " << edges[i].second + 1 << endl;
	return 0;
}