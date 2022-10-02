#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <tuple>
#include <unordered_set>


using namespace std;


int n;
vector<string> v;
map<string, int> m;
map<string, int> m1;
string s[100000];
int a[100000];


int main() {	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> a[i];
		m[s[i]]+= a[i];
		v.push_back(s[i]);
	}
	set<string> ss;
	int aa = 0;
	for (int i = 0; i < n; i++) {
		aa = max(aa, m[v[i]]);
	}
	for (int i = 0; i < n; i++) {
		if (m[v[i]] == aa) {
			ss.insert(v[i]);
		}
	}
	if ((int)ss.size() == 1) {
		cout << *(ss.begin()) << endl;
		return 0;
	}
	m.clear();
	for (int j = 0; j < n; j++) {
		m[s[j]]+= a[j];
		if (m[s[j]] >= aa && m1.find(s[j]) == m1.end()) {
			m1[s[j]] = j + 1;
		}  
	}
	int b = 10000;
	for (int j = 0; j < n; j++) {
		if (m[v[j]] == aa) {
			b = min(b, m1[v[j]]); 
		}
	}
	//cout << "opa" << endl;
	for (int j = 0; j < n; j++) {
		if (m[v[j]] == aa && m1[v[j]] == b) {
			cout << v[j] << endl;
			return 0;
		}
	}
    return 0;
}