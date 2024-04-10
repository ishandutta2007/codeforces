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
int a[1000001];
int d[1000001];
int t[1000001];
vector<int> v[1000001];
vector<int> st[1000001];


void pereb(int i, int a, int b) {
	if (i == (int)v[a].size()) {
		if (t[b] >= 0 && b != a) {
			d[t[b] - 1] = max(d[t[b] - 1], d[t[a] - 1] + 1);
		}
		return;
	}
	int k = 1;
	for (int j = 0; j <= st[a][i]; j++) {
		if (j != 0) {
			k *= v[a][i];
		}
		pereb(i + 1, a, b * k);
	}
}


int main() {
	cin >> n;
	int maxa = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		maxa = max(maxa, a[i]);
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		t[a[i]] = i + 1;
	}
	for (int i = 2; i <= maxa; i++) {
		if ((int)v[i].size() == 0) {
			for (int j = i * 2; j <= maxa; j+= i) {
				v[j].push_back(i);
			}
		}
	}
	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		int g = a[i];
		st[g].resize((int)v[g].size());
		for (int j = 0; j < (int)v[g].size(); j++) {
		//	cout << g << ' ' << v[g][j] << endl;
			int g1 = g;
			while (g1 % v[g][j] == 0) {
				st[g][j]++;
				g1 /= v[g][j];
			}
		}
	//	cout << "opa" << endl;
		d[i] = max(d[i], 1);
		pereb(0, g, 1);
		ans = max(ans, d[i]);
	}
	cout << ans << endl;
    return 0;
}