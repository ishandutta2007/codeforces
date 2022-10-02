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


int n;
long long l[200000];
map<long long, int> m;
multiset<long long> v;


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l[i];
		m[l[i]]++;
	}
	sort(l, l + n);
	for (int i = 0; i < n; i++) {
		v.insert(l[i]);
	}
	long long ans = 0;
	while ((int)v.size() >= 4) {
		int l1 = *(v.rbegin());
		if (m[l1] >= 2) {
			m[l1] -= 2;
			v.erase(v.find(l1));
			v.erase(v.find(l1));
			while (!v.empty() && m[(*v.rbegin())] < 2) {
				int l2 = (*v.rbegin());
				v.erase(v.find(l2));
				m[l2]--;
				l2--;
				m[l2]++;
				v.insert(l2);
				if (m[l2] < 2) {
					v.erase(l2);
				}
			}
			if ((int)v.size() < 2) {
				break;
			}
			ans += (*v.rbegin()) * l1;
			int l2 = (*v.rbegin());
			v.erase(v.find(l2));
			v.erase(v.find(l2));
			m[l2] -= 2;
		} else {
			v.erase(l1);
			m[l1]--;
			l1--;
			m[l1]++;
			v.insert(l1);
			if (m[l1] >= 2) {
				continue;
			} else {
				v.erase(l1);
				continue;
			}
		}
	}
	cout << ans << endl;
	return 0;
}