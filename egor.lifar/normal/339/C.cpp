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


using namespace std;


int m;
string s;
int used[22][22][1001];
pair<int, int> ot[22][22][1001];
queue<pair<int, pair<int, int> > > q;


int main() {
	cin >> s >> m;
	q.push(make_pair(10, make_pair(0, 0)));
	ot[10][0][0] = make_pair(0, -1);
	used[10][0][0] = 1;
	while (!q.empty()) {
		pair<int, pair<int, int> > a = q.front();
		q.pop();
		for (int i = 1; i <= 10; i++) {
			if (s[i - 1] == '1' && i != a.second.first && a.second.second != m) {
				if (a.first == 10) {
					if (!used[a.first + i][i][a.second.second + 1]) {
						used[a.first + i][i][a.second.second + 1] = true;
						q.push(make_pair(a.first + i, make_pair(i, a.second.second + 1)));
						ot[a.first + i][i][a.second.second + 1] = make_pair(i, a.second.first);
					}
					if (!used[a.first - i][i][a.second.second + 1]) {
						used[a.first - i][i][a.second.second + 1] = true;
						q.push(make_pair(a.first - i, make_pair(i, a.second.second + 1)));
						ot[a.first - i][i][a.second.second + 1] = make_pair(-i, a.second.first);
					}
				} else {
					if (a.first < 10) {
						if (a.first + i > 10 && a.first + i <= 20) {
							if (!used[a.first + i][i][a.second.second + 1]) {
								used[a.first + i][i][a.second.second + 1] = true;
								q.push(make_pair(a.first + i, make_pair(i, a.second.second + 1)));
								ot[a.first + i][i][a.second.second + 1] = make_pair(i, a.second.first);
							}
						}
					} else {
						if (a.first - i < 10 && a.first - i >= 1) {
							if (!used[a.first - i][i][a.second.second + 1]) {
								used[a.first - i][i][a.second.second + 1] = true;
								q.push(make_pair(a.first - i, make_pair(i, a.second.second + 1)));
								ot[a.first - i][i][a.second.second + 1] = make_pair(-i, a.second.first);
							}
						}
					}
				}
			}
		}
	}
	for (int i = 0; i <= 20; i++) {
		for (int j = 0; j <= 20; j++) {
			if (used[i][j][m]) {
				cout << "YES" << endl;
				int i1 = i;
				int j1 = j;
				int m1 = m;
				vector<int> v;
				while (m1 > 0) {
					v.push_back(abs(ot[i1][j1][m1].first));
					int a = ot[i1][j1][m1].first;
					j1 = ot[i1][j1][m1].second;
					i1 = i1 - a;
					m1--;
				}
				reverse(v.begin(), v.end());
				for (int i = 0; i < (int)v.size(); i++) {
					cout << v[i] << ' ';
				}
				cout << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
    return 0;
}