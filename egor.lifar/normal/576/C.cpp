#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <math.h>
#include <string.h>
#include <cstring>


using namespace std;


int n;
int x[1000000], y[1000000];
vector<pair<pair<int, int>, int> > v;
vector<pair<int, int> > s[1001];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]);
		v.push_back(make_pair(make_pair(x[i], y[i]), i + 1));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		s[(v[i].first.first - 1) / 1000].push_back(make_pair(v[i].first.second, v[i].second));
	}
	int l = 0;
	for (int i = 0; i < 1000; i++) {
		if ((int)s[i].size() > 0) {
			l++;
			sort(s[i].begin(), s[i].end());
			if (l % 2 == 1) {
				for (int j = 0; j < (int)s[i].size(); j++) {
					printf("%d ", s[i][j].second);
				}
			} else {
				for (int j = (int)s[i].size() - 1; j >= 0; j--) {
					printf("%d ", s[i][j].second);
				}
			}
		}
	}
	cout << endl;
	return 0;
}