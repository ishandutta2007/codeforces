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


int n, q;
int a[200000];
int k[200001];
int c[200001];
int ans[200001];


int main() {
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);	
	}
	sort(a, a + n);
	for (int i = 0; i < q; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		l--;r--;
		k[l]++;
		k[r + 1]--;
	}
	int anss = 0;
	vector<pair<int, int> > v;
	for (int i = 0; i < n; i++) {
		anss += k[i];
		c[i] = anss;
		v.push_back(make_pair(c[i], i));
	}
	sort(v.begin(), v.end());
	for (int i = n - 1; i >= 0; i--){
		ans[v[i].second] = a[i];
	}
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += 1LL * ans[i] * c[i];
	}
	cout << sum << endl;
	return 0;
}