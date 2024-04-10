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


int n;
int h[200000];
int a[200000];
vector<vector<int> > v;
vector<vector<int> > v1;
int k[200000];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &h[i]);
	}
	int ans = 0;
	for (int j = 0; j < n; j++) {
		k[j] = min(j + 1, min(n - j, h[j]));
	}
	for (int j = 0; j < n; j++) {
		if (j > 0) {
			k[j] = min(k[j], k[j - 1] + 1);
		}
		if (j < n - 1) {
			k[j] = min(k[j], k[j + 1] + 1);
		}
	}
	for (int j = n - 1; j >= 0; j--) {
		if (j > 0) {
			k[j] = min(k[j], k[j - 1] + 1);
		}
		if (j < n - 1) {
			k[j] = min(k[j], k[j + 1] + 1);
		}
	}
	for (int j = n - 1; j >= 0; j--) {
		ans = max(ans, k[j]);
	}
	// for (int j = 0; j < n; j++) {
	// 	h[j] -= min(h[j], max(1, max((j > 0 ? a[j] - a[j - 1]: a[j]), (j < n - 1 ? a[j] - a[j + 1]: a[j]))));
	// }
	// int ans = 1;
	// int l = 0;
	// int k = 0;
	// v.resize(1);
	// v1.resize(1);
	// vector<int> c;
	// c.resize(0);
	// for (int j = 0; j < n; j++) {
	// 	if (h[j] != 0) {
	// 		l++;
	// 		v.back().push_back(h[j]);
	// 		v1.back().push_back(h[j]);
	// 	} else {
	// 		l = 0;
	// 		v.push_back(c);
	// 		v1.push_back(c);
	// 	}
	// 	k = max(k, l);
	// }
	// int k1 = 0;
	// for (int j = 0; j < (int)v.size(); j++) {
	// 	if ((int)v[j].size() != 0) {
	// 		//cout << (int)v[j].size() << endl;
	// 		int l = 0;
	// 		int r = (int)v[j].size() - 1;
	// 		int k2 = 0;
	// 		while (v[j][l] > 0 || v[j][r] > 0) {
	// 			if (l > r) {
	// 				break;
	// 			}
	// 			k2++;
	// 			v[j][l] = 0;
	// 			v[j][r] = 0;
	// 			while (v[j][l] == 0) {
	// 				l++;
	// 				if (l > r) {
	// 					break;
	// 				}
	// 				int a2 = v1[j][l];
	// 				//cout << a2 << endl;
	// 				v[j][l] = min(v[j][l], min(v1[j][l - 1], a2 - 1));
	// 				v[j][l] = min(v[j][l], min(v1[j][l + 1], a2 - 1));
	// 				//cout << v[j][l] << endl;
	// 				//cout << l << endl;
	// 			}
	// 			//cout << l <<  ' ' << r << endl;
	// 			if (l > r) {
	// 				break;
	// 			}
	// 			while (v[j][r] == 0) {
	// 				r--;
	// 				if (l > r) {
	// 					break;
	// 				}
	// 				int a2 = v1[j][r];
	// 				v[j][r] = min(v[j][r], min(v1[j][r + 1], a2 - 1));
	// 				v[j][r] = min(v[j][r], min(v1[j][r - 1], a2 - 1));
	// 			}
	// 			if (l > r) {
	// 				break;
	// 			}
	// 			v1[j][l] = v[j][l];
	// 			v1[j][r] = v[j][r];
	// 		}
	// 		//cout << k2 << endl;
	// 		k1 = max(k1, k2);
	// 	}
	// }
	// ans += k1;
	cout << ans << endl;
	return 0;
}