#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

int n, k;
vector <int> a;
set <int> s;
map <int, int> m;

int main() {
	cin >> n >> k;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < k; i++) {
		if (s.find(a[i]) == s.end() && m.find(a[i]) == m.end()) {
			s.insert(a[i]);
			continue;
		}
		if (m.find(a[i]) == m.end()) {
			m.insert({ a[i], 2 });
			s.erase(a[i]);
			continue;
		}
		m[a[i]]++;
	}
	for (int i = k; i < n; i++) {
		if (s.size() == 0)
			cout << "Nothing" << endl;
		else 
			cout << *(--s.end()) << endl;
		if (s.find(a[i]) == s.end() && m.find(a[i]) == m.end()) {
			s.insert(a[i]);
		}
		else {
			if (m.find(a[i]) == m.end()) {
				m.insert({ a[i], 2 });
				s.erase(a[i]);
			}
			else {
				m[a[i]]++;
			}
		} 
		if (m.find(a[i - k]) != m.end()) {
			m[a[i - k]]--;
			if (m[a[i - k]] == 1) {
				s.insert(a[i - k]);
				m.erase(a[i - k]);
			}
		}
		else
			if (s.find(a[i - k]) != s.end()) 
				s.erase(a[i - k]);
	}	
	if (s.size() == 0)
		cout << "Nothing" << endl;
	else
		cout << *(--s.end()) << endl;
	return 0;
}