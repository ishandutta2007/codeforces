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


int n;
int a[120001], b[120001], c[120001];
int t[120001];
set<int> s;
bool used[120001];
vector<int> f[30001];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		t[i] = 4;
	}
	for (int i = 0; i < 4 * n; i++) {
		cin >> a[i] >> b[i] >> c[i];
		a[i]--;
		b[i]--;
		c[i]--;
		f[b[i]].push_back(i);
		f[c[i]].push_back(i);
		s.insert(i);
	}
	cout << "YES" << endl;
	while (!s.empty()) {
		int g = (*s.begin());
		cout << g + 1 << ' ';
		used[g] = true;
		t[a[g]]--;
		t[b[g]]++;
		t[c[g]]++;
	//	cout << t[1] << endl;
		s.erase(g);
		for (int j = 0; j < (int)f[a[g]].size(); j++) {
			int hh = f[a[g]][j];
			if (!used[hh]) {
				t[a[hh]]--;
				t[b[hh]]++;
				t[c[hh]]++;
				if (t[b[hh]] > 9 || t[c[hh]] > 9) {
					if (s.find(hh) != s.end()) {
						s.erase(hh);
					}
				} else {
					s.insert(hh);
				}
				t[a[hh]]++;
				t[b[hh]]--;
				t[c[hh]]--;
			}
		}
		for (int j = 0; j < (int)f[b[g]].size(); j++) {
			int hh = f[b[g]][j];
			if (!used[hh]) {
				t[a[hh]]--;
				t[b[hh]]++;
				t[c[hh]]++;
				if (t[b[hh]] > 9 || t[c[hh]] > 9) {
					if (s.find(hh) != s.end()) {
						s.erase(hh);
					}
				} else {
					s.insert(hh);
				}
				t[a[hh]]++;
				t[b[hh]]--;
				t[c[hh]]--;
			}
		}
		for (int j = 0; j < (int)f[c[g]].size(); j++) {
			int hh = f[c[g]][j];
			if (!used[hh]) {
				t[a[hh]]--;
				t[b[hh]]++;
				t[c[hh]]++;
				if (t[b[hh]] > 9 || t[c[hh]] > 9) {
					if (s.find(hh) != s.end()) {
						s.erase(hh);
					}
				} else {
					s.insert(hh);
				}
				t[a[hh]]++;
				t[b[hh]]--;
				t[c[hh]]--;
			}
		}
	}
	cout << endl;
    return 0;
}