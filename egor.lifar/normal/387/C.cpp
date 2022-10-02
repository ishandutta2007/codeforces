#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <vector>
#include <map>
 

using namespace std;


string s;
int ans = 0;
vector<string> v;


int main() {
	cin >> s;
	int n = (int)s.size();
	int l = 0;
	while (l < n) {
		string s1;
		s1+= s[l];
		while (l < n - 1 && s[l + 1] == '0') {
			l++;
			s1 += '0';
		}
		v.push_back(s1);
		l++;
	}
	int ans = (int)v.size();
	int i = 0;
	string t;
	int k = 0;
	while (i < (int)v.size()) {
		if (t.size() > 0) {
			if (t.size() < v[i].size() || (t.size() == v[i].size() && t < v[i])) {
				ans-= k;
				t += v[i];
				k = 1;
			} else {
				t += v[i];
				k++;
			}
		} else {
			t += v[i];
			k++;
		}
		i++;
	}
	cout << ans << endl;
	return 0;
}