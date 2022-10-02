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


int n, m;
bool b[101], b1[101];
vector<pair<int, int> > v;


int main() {
	cin >> n >> m;
	int s = 0;
	while (s < n * m) {
		v.push_back(make_pair(s % n, s % m));
		s++;
	}
	int f;
	cin >> f;
	for (int i = 0; i < f; i++) {
		int g;
		cin >> g;
		b[g] = true;
	}
	cin >> f;
	for (int i = 0; i < f; i++) {
		int g;
		cin >> g;
		b1[g] = true;
	}
	while (true) {
		bool bb = true;
		for (int j = 0; j < (int)v.size(); j++) {
			if (b[v[j].first] && !b1[v[j].second]) {
				bb = false;
				b1[v[j].second] = true;
			}
			if (!b[v[j].first] && b1[v[j].second]) {
				bb = false;
				b[v[j].first] = true;
			}
		} 
		if (bb) {
			break;
		}
	}
	bool bb = true;
	for (int i = 0; i < n; i++) {
		if (!b[i]) {
			bb = false;
		}
	}
	for (int i = 0; i < m; i++) {
		if (!b1[i]) {
			bb = false;
		}
	}
	if (bb) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
    return 0;
}