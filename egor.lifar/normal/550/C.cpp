#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>


using namespace std;


int main() {
	string s;
	cin >> s;
	int n = (int)s.size();
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int g = j + 1; g < n; g++) {
				int h = s[i] - '0';
				int h1 = s[j] - '0';
				int h2 = s[g] - '0';
				int gg = h * 100 + h1 * 10 + h2;
				if (gg % 8 == 0) {
					cout << "YES" << endl;
					cout << gg << endl;
					return 0;
				}
				
				
			}
			int h = s[i] - '0';
				int h1 = s[j] - '0';
			int gg1 = h * 10 + h1;
				if (gg1 % 8 == 0) {
					cout << "YES" << endl;
					cout << gg1 << endl;
					return 0;
				}
		}
		int h = s[i] - '0';
		int gg2 = h;
				if (gg2 % 8 == 0) {
					cout << "YES" << endl;
					cout << gg2 << endl;
					return 0;
				}
	}
	cout << "NO" << endl;
    return 0;   
}