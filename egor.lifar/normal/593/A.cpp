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
#include <queue>
#include <unordered_map>
#include <vector>


using namespace std;


int n;
string s[1001];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	int ans = 0;
	for (char c = 'a'; c <= 'z'; c++) {
		for (char c1 = 'a'; c1 <= 'z'; c1++) {
			int ans1 = 0;
			for (int i = 0; i < n; i++) {
				int l = (int)s[i].size();
				bool b = true;
				for (int j = 0; j < l; j++) {
					if (s[i][j] != c && s[i][j] != c1) {
						b = false;
						break;
					}
				}
				if (b) {
					ans1 += l;
				}
			}
			ans = max(ans, ans1);
		} 
	}
	cout << ans << endl;
	return 0;
}