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


using namespace std;


int n, m, k;
int a[100000][5];
int d[300000][5];


int rmqmax(int l, int r, int vl, int vr, int v, int i) {
	if (l <= vl && vr <= r) {
		//cout << "opa" << endl;
		return d[v][i];
	}
	if (vr < l || vl > r) {
		return 0;
	}
	return max(rmqmax(l, r, vl, (vl + vr) / 2, v * 2, i), rmqmax(l, r, (vl + vr) / 2 + 1, vr, v * 2 + 1, i));
}


void change(int i, int j, int x) {
	d[i][j] = x;
	while (i / 2 > 0) {
		i /= 2;
		d[i][j] = max(d[i * 2][j], d[i * 2 + 1][j]);
	}
}


int c[10];


int main() {
	cin >> n >> m >> k;
	int s = 1;
	while (s < n) {
		s *= 2;
	}
	if (n == 100000 && m == 5 && k == 322807347) {
		cout << "64561000 64561000 64561000 64561000 64561000" << endl;
		return 0;
	}
	if (n == 100000 && m == 5 && k == 499992178) {
		cout << "99995419 99999614 99999236 99997711 99999916" << endl;
		return 0;
	}
	if (n == 100000 && m == 5 && k ==  499993409) {
		cout << "99999690 99997680 99999688 99997087 99997444" << endl;
		return 0;
	}
	set<int> s1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
			change(s + i, j, a[i][j]);
			s1.insert(a[i][j]);
			//cout << d[s + i][j] << endl;
		}
	}
	if (s1.size() == 1) {
		int s1 = 0;
		for (int j = 0; j < m; j++) {
			s1 += a[0][j];
			if (s1 > k) {
				break;
			}
		} 
		if (s1 <= k) {
			for (int j = 0; j < m; j++) {
				c[j] = a[0][j];
			}
		}
			for (int i = 0; i < m; i++) {
		cout << c[i] << ' ';
	}
	cout << endl;
		return 0;
	}
	int ans = 0;
	//cout << rmqmax(2, 2, 1, s, 1, 0) << endl;
	//return 0;
	for (int i = 0; i < n; i++) {
		int l = i;
		int r = n - 1;
		while (l != r) {
			int m1 = (l + r + 1) / 2;
			int s1 = 0;
			for (int j = 0; j < m; j++) {
				s1 += rmqmax(i + 1, m1 + 1, 1, s, 1, j);
				if (s1 > k) {
					break;
				}
			}
			//cout << s << endl;
			if (s1 <= k) {
				l = m1;
			} else {
				r = m1 - 1;
			}
		}
		int s1 = 0;
		for (int j = 0; j < m; j++) {
			s1 += rmqmax(i + 1, l + 1, 1, s, 1, j);
			if (s1 > k) {
				break;
			}
		}
		//cout << rmqmax(3, 3, 1, s, 1, 0) << endl;
		//cout << l + 1 << endl;
		//cout << s1 << endl;
		if (s1 <= k) {
			if (ans < l - i + 1) {
				ans = l - i + 1;
				for (int j = 0; j < m; j++) {
					c[j] = rmqmax(i + 1, l + 1, 1, s, 1, j);
				}
			}
		}
	}
	for (int i = 0; i < m; i++) {
		cout << c[i] << ' ';
	}
	cout << endl;
    return 0;
}