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



int m, k;
int a[100];
int n;
vector<int> v[101];
bool used[101];
int minn[101];
int maxx[101];
int ans[101];


int main() {
		freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> m >> k;
	for (int i = 0; i < k; i++) {
		cin >> a[i];
		used[a[i]] = true;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int d;
		cin >> d;
		v[i].resize(d);
		int g = 0;
		int t = 0;
		for (int j = 0; j < d; j++) {
			int a;
			cin >> a;
			if (used[a]) {
				minn[i]++;
				maxx[i]++;
				g++;
			}
			if (a == 0) {
				t++;
			}
		}
		int g1 = d - t - g;
		minn[i] += max(0, t - (m - k - g1));
		maxx[i] += min(k - g, t);
	//	cout << maxx[i] << ' ' << minn[i] << endl;
	}
	for (int j = 0; j < n; j++) {
		bool b = true;
		for (int i = 0; i < n; i++) {
			if (maxx[j] < minn[i] && i != j) {
				b = false;
			}
		}
		int b1 = 0;
		for (int i = 0; i < n; i++) {
			if (minn[j] >= maxx[i] && i != j) {
				b1++;
			}
		}
		if (b1 == n - 1) {
			b1 = 1;
		} else {
			b1 = 0;
		}
		bool b2 = true;
		for (int i = 0; i < n; i++) {
			if (minn[j] < maxx[i] && i != j) {
				b2 = false;
			}
		}
		if (!b2 && b) {
			ans[j] = 2;
		} else {
			if (b2) {
				ans[j] = 0;
			} else {
				ans[j] = 1;
			}
		}
		cout << ans[j] << endl;
	}
	cout << endl;
 	return 0;
}