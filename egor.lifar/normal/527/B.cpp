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


using namespace std;



int n;
string a, b;
map<char, int> m, m2;
map<pair<char, char>, int> m1; 


int main() {
	cin >> n;
	cin >> a >> b;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			ans++;
		}
		m1[make_pair(a[i], b[i])]++;
	}
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i] && m1[make_pair(b[i], a[i])]) {
			for (int j = 0; j < n; j++) {
				if (a[j] == b[i] && b[j] == a[i]) {
					cout << ans - 2 << endl;
					cout << j + 1 << ' ' << i + 1 << endl;
					return 0;
				}
			}
		}
		m[a[i]]+= a[i] != b[i];
		m2[b[i]]+= a[i] != b[i];
	}
	//cout << m['z'] << endl;
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			m[a[i]]-= a[i] != b[i];
			m2[b[i]]-= a[i] != b[i];
		//	cout << m[b[i]] << m2[a[i]] << endl;
		//	cout << i << endl;
			if (m[b[i]] > 0) {
				for (int j = 0; j < n; j++) {
					if (a[j] == b[i] && b[j] != a[j]) {
										cout << ans - 1 << endl;
						cout << j + 1 << ' ' << i + 1 << endl;
						return 0;
					}
				}
				return 0;
			}
			if (m2[a[i]] > 0) {
				for (int j = 0; j < n; j++) {
					if (b[j] == a[i] && b[j] != a[j])  {
										cout << ans - 1 << endl;
						cout << j + 1 << ' ' << i + 1 << endl;
						return 0;
					}
				}
				return 0;
			}
			m[a[i]]+= a[i] != b[i];
			m2[b[i]]+= a[i] != b[i];
		}
	}
	// .cout << "opa" << endl;
	cout << ans << endl;
	cout << -1 << ' ' << -1 << endl;
	return 0;
}