#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
#include <string.h>
#include <iomanip>
#include <utility>
#define INF 0x3fffffff
using namespace std;
int n, m, k, t, p, q, x, y;
string s;
int w[30];
long long sum[100005];
map<long long, int> mymap[30];
int main() {
	for (int i = 0; i < 26; i++) {
		cin >> w[i];
	}
	long long res = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		sum[i] = sum[i - 1] + w[s[i] - 'a'];
	}

	for (int i = 0; i < s.size(); i++) {
		int index = s[i] - 'a';
		if (i == 0) {
			mymap[index][sum[i]]++;
			continue;
		}
		if (mymap[index].count(sum[i - 1])) {
			res += mymap[index][sum[i - 1]];
		}
		mymap[index][sum[i]]++;
	}
	cout << res << endl;
	return 0;
}