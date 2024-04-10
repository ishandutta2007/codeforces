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


using namespace std;


int n;
unordered_map<string, int> m;


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (m.find(s) == m.end()) {
			m[s]++;
			cout << "OK" << endl;
		} else {
			int g = m[s];
			cout << s << g << endl;
			string s1 = s;
			vector<int> v;
			m[s]++;
			while (g > 0) {
				v.push_back(g % 10);
				g /= 10;
			}
			reverse(v.begin(), v.end());
			for (int j = 0; j < (int)v.size(); j++) {
				s1 += '0' + v[j];
			}
			m[s1]++;
		}
	}
    return 0;
}