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
#include <assert.h>
#include <stack>


using namespace std;


int n;
int l[100000], r[100000], p[100000];
stack<int> t;
string s;


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
		t.push(i);
		p[i] = (int)s.size();
		s += '(';
		while (!t.empty() && p[t.top()] + l[t.top()] <= (int)s.size()) {
			if ( p[t.top()] + r[t.top()] < (int)s.size()) {
				cout << "IMPOSSIBLE" << endl;
				return 0;
			}
			s += ')';
			t.pop();
		}
	}
	if (!t.empty()) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		cout << s << endl;
	}
  	return 0; 
}