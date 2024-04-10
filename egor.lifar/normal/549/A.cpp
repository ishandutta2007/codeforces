#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
 

using namespace std;


int n, m;
string s[51];


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	int ans = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m - 1; j++) {
			vector<char> k;
			k.push_back(s[i][j]);
			k.push_back(s[i + 1][j]);
			k.push_back(s[i][j + 1]);
			k.push_back(s[i + 1][j + 1]);
			sort(k.begin(), k.end());
			if (k[0] == 'a' && k[1] == 'c' && k[2] == 'e' && k[3] == 'f') {
				ans++;
			}
		}
	}
	cout << ans << endl;
 	return 0;
}