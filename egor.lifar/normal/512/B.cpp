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
#include <assert.h>


using namespace std;


#define INF 1000000000


int n;
int l[300];
int c[300];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	int ans = INF;
	for (int i = 0; i < n; i++) {
		vector<int> v;
		int l1 = l[i];
		int a = 2;
		while (a <= (int)sqrt(l1)) {
			if (l1 % a == 0) {
				v.push_back(a);
				while (l1 % a == 0) {
					l1 /= a;
				}
			}
			a++;
		}
		if (l1 != 1) {
			v.push_back(l1);
		}
		// for (int g = 0; g < (int)v.size(); g++) {
		// //		cout << v[g] << ' ';
		// 	}
		// //	cout << endl;
		int m[300];
		for (int j = 0; j < n; j++) {
			vector<int> v1;
			for (int g = 0; g < (int)v.size(); g++) {
				if (l[j] % v[g] == 0) {
					v1.push_back(1);
				} else {
					v1.push_back(0);
				}
			}
			m[j] = 0;
			for (int g = 0; g < (int)v1.size(); g++) {
				m[j] *= 2;
				m[j] += v1[g];
			}
		}
		int d[1024];
		for (int j = 0; j <= 512; j++) {
			d[j] = INF;
		}
		d[m[i]] = c[i];
		//cout << m[i] << endl;
		for (int j = m[i]; j >= 0; j--) {
			for (int k = 0; k < n; k++) {
				int a = j & m[k];
				d[a] = min(d[a], d[j] + c[k]);
			}
			//cout << d[j] << endl;
		}
		ans = min(ans, d[0]);
	//	cout << endl;
	//	cout << endl;
	}
	if (ans == INF) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}
  	return 0; 
}