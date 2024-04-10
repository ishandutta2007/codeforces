#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	set <int> s1;
	for (int i = 0; i < n; i++) {
		if (s1.find(a[i] - 1) == s1.end()) {
			s1.insert(a[i] - 1);
			continue;
		}
		if (s1.find(a[i]) == s1.end()) {
			s1.insert(a[i]);
			continue;
		}
		s1.insert(a[i] + 1);
	}
	set <int> s2;
	for (int i = 0; i < n; i++) {
		if (s2.find(a[i] - 1) != s2.end() || s2.find(a[i]) != s2.end())
			continue;
		s2.insert(a[i] + 1);
	}
	cout << s2.size() << " " << s1.size();
	return 0;
}