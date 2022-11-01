#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	map <int, int> m;
	set <pair <int, int>> s;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		m[a[i]]++;
		if (m[a[i]] == 1)
			s.insert({ 1, a[i] });
		else {
			s.erase({ m[a[i]] - 1, a[i] });
			s.insert({ m[a[i]], a[i] });
		}
		if (s.size() == 1) {
			ans = i + 1;
			continue;
		}
		if (s.size() > 1) 
			if ((s.begin()->first == (--s.end())->first - 1 && s.begin()->first == (--(--s.end()))->first) || (s.begin()->first == 1 && (--s.end())->first == (++s.begin())->first))
				ans = i + 1;
	}
	cout << ans;
	return 0;
}