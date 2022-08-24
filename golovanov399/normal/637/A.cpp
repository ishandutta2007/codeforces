#include <iostream>
#include <map>

using namespace std;

int main() {
	int n;
	cin >> n;
	map<int, int> a;
	int b[n];
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		b[i] = k;
		a[k] += 1;		
	}
	map<int, int> c;
	int max = 0;
	for (map<int, int>::const_iterator it = a.begin(); it != a.end(); ++it) {
		if (it->second > max) 
			max = it->second;
	}
	for (map<int, int>::const_iterator it = a.begin(); it != a.end(); ++it) {
		if (it->second == max) 
			c[it->first] = it->second;
	}
	for (int i = 0; i < n; ++i) {
		c[b[i]]--;
		if (c[b[i]] == 0) {
			cout << b[i] << endl;
			return 0;
		}	
	}
	return 0;
}