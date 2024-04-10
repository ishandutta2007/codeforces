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
#include <unordered_map>


using namespace std;


int n, m;
int p[100000];
bool used[100000];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
	}
	cin >> m;
	m = n - m;
	vector<vector<int> > v;
	int l = 0;
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			vector<int> v1;
			v.push_back(v1);
			int a = i;
			do {
				used[a] = true;
				v[l].push_back(a);
				a = p[a];
			} while (a != i);
			l++;
		}
	}
	//cout <<
	if (m == l) {
		cout << 0 << endl;
		return 0;
	}
	//cout << l << endl;
	if (m < l) {
		cout << l - m << endl;
		for (int i = 1; i <= l - m; i++) {
			cout << 1 << ' ' << v[i][0] + 1 << ' ';
		}
		cout << endl;
	} else {
		cout << m - l << endl;
		for (int i = 0; i < n && l < m; i++) {
			vector<int> posi;
			posi.resize(n);
			for (int j = 0; j < n; j++) {
				posi[j] = -1;
			}
			int cnt = 0;
			for (int j = p[i]; j != i; j = p[j]) {
				cnt++;
				posi[j] = cnt;
			}
			cnt = 0;
			for (int j = i + 1; j < n && l < m; j++) {
				if (posi[j] >= cnt) {
					cout << i + 1 << ' ' << j + 1 << ' ';
					l++;
					cnt = posi[j] + 1;
					swap(p[i], p[j]);
				}
			}
		}
		cout << endl;
	}
    return 0;
}