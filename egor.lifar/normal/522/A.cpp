#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <unordered_map>
#include <tuple>


using namespace std; 


int n;
map<string, int> m;


int main() {
	cin >> n;
	m["polycarp"] = 1;
	int k = 0;
	for (int i = 0; i < n; i++) {
		string a, b, c;
		cin >> a >> b >> c;
		for (int i = 0; i < (int)a.size(); i++) {
			if (a[i] >= 'A' && a[i] <= 'Z') {
				a[i] = a[i] - 'A' + 'a'; 
			}
		}
		for (int i = 0; i < (int)c.size(); i++) {
			if (c[i] >= 'A' && c[i] <= 'Z') {
				c[i] = c[i] - 'A' + 'a'; 
			}
		}
		m[a] = m[c] + 1;
		k = max(k, m[a]);
	}
	cout << k << endl;
	return 0;
}