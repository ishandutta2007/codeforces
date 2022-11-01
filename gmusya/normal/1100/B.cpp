#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector <int> a(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i];
		a[i]--;
	}
	map <int, int> ma;
	set <int> se;
	for (int i = 0; i < n; i++)
		se.insert(i);
	for (int i = 0; i < m; i++) {
		ma[a[i]]++;
		if (ma[a[i]] == 1)
			se.erase(a[i]);
		cout << (se.size() == 0);
		if (se.size() == 0)
			for (int i = 0; i < n; i++) {
				ma[i]--;
				if (ma[i] == 0)
					se.insert(i);
			}
	}
	return 0;
}