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


string s;
int t = 0;
map<char, int> m;


int main(){
	cin >> s;
	int n = (int)s.size();
	for (int i = 0; i < n; i++) {
		m[s[i]]++;
	}
	for (char c = 'a'; c <= 'z'; c++) {
		if (m[c] % 2 == 1) {
			t++;
		}
	}
	if (t < 2 || (t % 2 == 1)) {
		cout << "First" << endl;
		return 0;
	}
	cout << "Second" << endl;
	return 0;
}