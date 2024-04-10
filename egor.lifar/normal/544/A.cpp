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
 

using namespace std;


map<char, int> m;


int main(){
	int k;
	string a;
	cin >> k >> a;
	int n = (int)a.size();
	vector<int> v;
	for (int i = 0; i < n; i++) {
		if (m.find(a[i]) == m.end()) {
			m[a[i]] = true;
			v.push_back(i);
		}
	}
	if ((int)v.size() < k) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	while ((int)v.size() > k) {
		v.pop_back();
	}
	v.push_back(n);
	for (int i = 0; i < k; i++) {
		for (int j = v[i]; j < v[i + 1]; j++) {
			cout << a[j];
		}
		cout << endl;
	}
 	return 0;
}