#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	set <int> give, take, from, to, unused;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		if (a[i] != 0) {
			give.insert(i + 1);
			take.insert(a[i]);
		}
	for (auto now : give)
		if (take.find(now) == take.end())
			from.insert(now);
	for (auto now : take)
		if (give.find(now) == give.end())
			to.insert(now);
	for (int i = 1; i <= n; i++)
		if (give.find(i) == give.end() && take.find(i) == take.end())
			unused.insert(i);
	if (unused.size() == 1) {
		int x = *from.begin();
		int v = *unused.begin();
		a[v - 1] = x;
		unused.erase(v);
		from.erase(x);
		from.insert(v);
	}
	vector <int> b;
	vector <int> c;
	vector <int> d;
	for (auto now : from)
		b.push_back(now);
	for (auto now : to)
		c.push_back(now);
	for (auto now : unused)
		d.push_back(now);
	for (int i = 0; i < c.size(); i++)
		a[c[i] - 1] = b[i];
	for (int i = 0; i < d.size(); i++)
		a[d[i] - 1] = d[(i + 1) % d.size()];
	for (auto now : a)
		cout << now << " ";
	cout << endl;
	return 0;
}