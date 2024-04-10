#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


string s;
int n;
int a[10], b[10];
int a1[10], b1[10];


int main() {
	cin >> s;
	n = s.size();
	for (int i = 0; i < n; i++) {
		a[s[i] - '0']++;
		b[s[i] - '0']++;
	}
	long long ans = -1;
	int count = -1, pos = -1;
	for (int i = 0; i <= a[0]; i++) {
		for (int j = 0; j < 10; j++) {
			a1[j] = a[j];
			b1[j] = b[j];
		}
		a1[0] -= i;
		b1[0] -= i;
		for (int j = 1; j < 10; j++) {
			long long s1 = i;
			if (a1[j] > 0 && b1[10 - j] > 0) {
				a1[j]--;
				b1[10 - j]--;
				for (int k = 0; k < 10; k++) {
					s1 += min(a1[k], b1[9 - k]);
				}
				if (ans <= s1) {
					ans = s1;
					count = i;
					pos = j;
				}
				a1[j]++;
				b1[10 - j]++;
			}
		}
	}
	vector<int> v;
	vector<int> v1;
	if (count > 0) {
		for (int i = 0; i < count; i++) {
			v.push_back(0);
			v1.push_back(0);
		}
		a[0] -= count;
		b[0] -= count;
	}
	if (pos >= 0) {
		v.push_back(pos);
		v1.push_back(10 - pos);
		a[pos]--;
		b[10 - pos]--;
	}
	for (int i = 0; i < 10; i++) {
		while (min(a[i], b[9 - i]) > 0) {
			a[i]--;
			b[9 - i]--;
			v.push_back(i);
			v1.push_back(9 - i);
		}
	} 
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < a[i]; j++) {
			v.push_back(i);
		}
		for (int j = 0; j < b[i]; j++) {
			v1.push_back(i);
		}
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i];
	}
	cout << endl;
	for (int i = v1.size() - 1; i >= 0; i--) {
		cout << v1[i];
	}
	cout << endl;
	return 0;
}