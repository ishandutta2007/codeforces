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


int n, m;
int f[100000];
vector<int> v[100000];
bool b[100000];


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> f[i];
		b[i] = true;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--;b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		bool t = true;
		int p = -1;
		int l = 0;
		int p1 = 0;
		for (int j = 0; j < n; j++) {
			if (b[j]) {
				t = false;
				int gg = 0;
				for (int g = 0; g < (int)v[j].size(); g++) {
					gg += b[v[j][g]] * f[v[j][g]];
				}
				// << gg1 << endl;
				if (p < f[j]) {
					l = j;
					p = f[j];
					p1 = gg;
				}
			}
		}
		ans += p1;
	//	cout << p << ' ' << l + 1 << endl;
		b[l] = false;
		if (t) {
			break;
		}
	}
	cout << ans << endl;
    return 0;
}