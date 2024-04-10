#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


string s;
int n;


int main() {
	cin >> s;
	n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			for (int j = 0; j < n; j++) {
				if (j != i) {
					cout << s[j];
				}
			}
			cout << endl;
			return 0;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		cout << 1;
	}
	cout << endl;
	return 0;
}