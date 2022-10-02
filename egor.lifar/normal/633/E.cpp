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
#include <vector>
#include <bitset>


using namespace std;


#define INF 10000000


int n, k;
int ss;
int smin[20][1000001], smax[20][1000001];
int ans[1000001];
double st1[1000001];
double lg[1000001];
int lgt[1000001];


pair<int, int> get(int l, int r) {
	int s = lgt[r - l + 1];
	int u = l;
	int v = r - (1 << s) + 1;
	return make_pair(max(smax[s][u], smax[s][v]), min(smin[s][u], smin[s][v]));
}


int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		scanf("%d", &smax[0][i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &smin[0][i]);
	}
	for (int l = 1; l < 20; l++) {
		for (int i = 0; i < n; i++) {
			smax[l][i] = max(smax[l - 1][i], smax[l - 1][i + (1 << (l - 1))]);
            smin[l][i] = min(smin[l - 1][i], smin[l - 1][i + (1 << (l - 1))]);
		}
	}
	for (int i = 2; i <= n; i++) {
		lgt[i] = 1 + lgt[i / 2];
	}
	for (int i = 0; i < n; i++) {
		int l = i - 1;
		int r = n;
		while (r - l > 1) {
			int m = (l + r) / 2;
			pair<int, int> p = get(i, m);
			int s =	100 * p.first;
			int s1 = p.second;
			if (s <= s1) {
				l = m;
			} else {
				r = m;
			}
		}
		if (i <= l) {
			pair<int, int> p = get(i, l);
			int s =	100 * p.first;
			int s1 = p.second;
			ans[i] = min(s, s1);	
		}
		if (r < n) {
			pair<int, int> p = get(i, r);
			int s =	100 * p.first;
			int s1 = p.second;
			ans[i] = max(ans[i], min(s, s1));
		}
	} 
	sort(ans, ans + n);
	lg[0] = 0.0;
	for (int i = 1; i <= n; i++) {
		lg[i] = lg[i - 1] + log(double(i));
	}
	double sum = 0;
	double cnt = (double)k / n;
	for (int i = 0; i <= n - k; i++) {
		if (cnt < 1e-100) {
			continue;
		}
		sum += ans[i] * cnt;
		cnt = cnt * (n - k - i) / (n - 1 - i);
	}
	printf("%.7lf\n", double(sum));
	return 0;
}