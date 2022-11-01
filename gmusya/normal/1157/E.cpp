#include <iostream>
#include <set>
#include <vector> 
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n), b(n);
	multiset <int> s;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		s.insert(b[i]);
	}
	for (int i = 0; i < n; i++) {
		int x;
		if (s.lower_bound((n - a[i])  % n) == s.end())
			x = *s.begin();
		else
			x = *s.lower_bound((n - a[i]) % n); 
		cout << (x + a[i]) % n << " ";
		s.erase(s.find(x));
	}
	cout << endl;
	return 0;
}