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
string s;
vector<int> v;
vector<pair<long long, int> > v1;
map<int, long long> m;


int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		for (int j = 2; j <= s[i] - '0'; j++) {
			long long ans = j;
			long long ans3 = ans;
			long long a = 2;
			while (a * a <= ans3) {
				int t = 0;
				while (ans3 % a == 0) {
					ans3 /= a;
					t++;
				}
				if (t != 0) {
					v1.push_back(make_pair(a, t));
					m[a]+=t;
				}
				a++;
			} 
			if (ans3 != 1) {
				v1.push_back(make_pair(ans3, 1));
				m[ans3]++;
			}
		}
	}
	sort(v1.begin(), v1.end());
	for (int i = v1.size() - 1; i >= 0; i--) {
		for (int j = 0; j < (int)v1[i].second; j++) {
			bool b = true;
			long long ans = v1[i].first;
			vector<pair<int, int> > v2;
			long long a = 2;
			while (a * a <= ans) {
				int t = 0;
				while (ans % a == 0) {
					ans /= a;
					t++;
				}
				if (t != 0) {
					v2.push_back(make_pair(a, t));
				}
				a++;
			} 
			if (ans != 1) {
				v2.push_back(make_pair(ans, 1));
			}
			for (int g = 0; g < (int)v2.size(); g++) {
				if (m[v2[g].first] < v2[g].second) {
					b = false;
				}
			}
			if (b) {
				v.push_back(v1[i].first);
				for (long long g = v1[i].first; g >= 1; g--) {
					long long anss = g;
					vector<pair<int, int> > v3;
					long long a = 2;
					while (a * a <= anss) {
						int t = 0;
						while (anss % a == 0) {
							anss /= a;
							t++;
						}
						if (t != 0) {
							v3.push_back(make_pair(a, t));
						}
						a++;
					} 
					if (anss != 1) {
						v3.push_back(make_pair(anss, 1));
					}
					for (int g1 = 0; g1 < (int)v3.size(); g1++) {
						m[v3[g1].first] -= v3[g1].second;
					}
				}
			}
		}
	}
	for (int i = 0; i < (int)v.size(); i++) {
		cout << v[i];
	}
	cout << endl;
    return 0;
}