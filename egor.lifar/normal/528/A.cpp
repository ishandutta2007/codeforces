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


int w, h, n;
set<pair<int, int> > s, s1;
multiset<long long> k1, k2;


int main() {
	cin >> w >> h >> n;
	s.insert(make_pair(h, 1));
	s1.insert(make_pair(w, 1));
	k1.insert(h);
	k2.insert(w);
	for (int i = 0; i < n; i++) {
		char c;
		int k;
		cin >> c >> k;
		if (c == 'H') {
			pair<int, int> p = *(s.lower_bound(make_pair(k, k)));
			s.erase(p);
			swap(p.first, p.second);
			s.insert(make_pair(k, p.first));
			s.insert(make_pair(p.second, k + 1));
			k1.erase(k1.find(p.second - p.first + 1));
			k1.insert(k - p.first + 1);
			k1.insert(p.second - k);
		} else {
			pair<int, int> p = *(s1.lower_bound(make_pair(k, k)));
			s1.erase(p);
			swap(p.first, p.second);
			s1.insert(make_pair(k, p.first));
			s1.insert(make_pair(p.second, k + 1));
			k2.erase(k2.find(p.second - p.first + 1));
			k2.insert(k - p.first + 1);
			k2.insert(p.second - k);
		}
		cout << (*(k1.rbegin())) * (*(k2.rbegin())) << endl;
	}
	return 0;
}