#include <cstdio>
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
int n, k;
map<char, long long> m;
long long ans = 0, ans1 = 0;


int main() {
	cin >> s;
	n = s.size();
	cin >> k;
	long long t = 0;
	long long t1 = 0;
	for (char i = 'a'; i <= 'z'; i++) {
		cin >> m[i];
		t = max(t, m[i]);
	}
	for (int i = 0; i < n; i++) {
		ans += m[s[i]] * (i + 1);
		t1 += m[i];
	}
	ans1 = ans + t1 * k;
	for (int i = 0; i < k; i++) {
		ans1 += (i + 1) * t;
	}
	for (int i = n; i < n + k; i++) {
		ans += t * (i + 1);
	}
	cout << max(ans, ans1) << endl;
	return 0;
}