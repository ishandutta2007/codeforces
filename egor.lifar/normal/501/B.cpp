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
#include <math.h>


using namespace std;


int q;
map<string, pair<string, int> > m;
bool b[100000];
string a[100000];


int main() {
	cin >> q;
	for (int i = 0; i < q; i++) {
		string b;
		cin >> a[i] >> b;
		m[a[i]] = make_pair(b, i);
	}
	vector<pair<string, string> > ans;
	for (int i = 0; i < q; i++) {
		if (!b[i]) {
			string g = a[i];
			while (true) {
				if (m.find(g) == m.end()) {
					break;
				}
				b[m[g].second] = true;
				g = m[g].first;
			}
			ans.push_back(make_pair(a[i], g));
		}
	}
	cout << (int)ans.size() << endl;
	for (int i = 0; i < (int)ans.size(); i++) {
		cout << ans[i].first << ' ' << ans[i].second << endl;
	}
    return 0;
}