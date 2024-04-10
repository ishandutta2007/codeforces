#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <cassert>


using namespace std;


#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()


int n;
int a[6];
map<string, int> m;
vector<int> v[100001];
vector<int> v1[100001];
string s[6];
string ans[100001];
bool good[100001];


int main() {
	for (int i = 0; i < 6; i++) {
		cin >> a[i];
	}
	cin >> n;
	m["S"] = 0;
	s[0] = "S";
	m["M"] = 1;
	s[1] = "M";
	m["L"] = 2;
	s[2] = "L";
	m["XL"] = 3;
	s[3] = "XL";
	m["XXL"] = 4;
	s[4] = "XXL";
	m["XXXL"] = 5;
	s[5] = "XXXL";
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		bool b = 0;
		for (int j = 0; j < sz(a); j++) {
			if (a[j] == ',') {
				b = 1;
				string c, d;
				for (int k = 0; k < j; k++) {
					c += a[k];
				}
				for (int k = j + 1; k < sz(a); k++) {
					d += a[k];
				}
				//cout << c << ' ' << d << endl;
				v[m[c]].push_back(i);
				v1[m[d]].push_back(i);
			}
		}
		if (!b) {
			v1[m[a]].push_back(i);
		}
	}
	int cnt = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < (int)v1[i].size() && a[i]; j++) {
			int h = v1[i][j];
			if (!good[h]) {
				a[i]--;
				ans[h] = s[i];
				good[h] = 1;
				cnt++;
			}
		}
		for (int j = 0; j < (int)v[i].size() && a[i]; j++) {
			int h = v[i][j];
			if (!good[h]) {
				a[i]--;
				ans[h] = s[i];
				good[h] = 1;
				cnt++;
			}
		}
	}	
	//cout << cnt << endl;
	if (cnt == n) {
		cout << "YES" << endl;
		for (int i = 0; i < n; i++) {
			cout << ans[i] << endl;
		}
	} else {
		cout << "NO" << endl;
	}
	return 0;
}