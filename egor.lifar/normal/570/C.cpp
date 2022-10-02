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


int n, m;
int l[300001], r[300001];
int sum = 0;
int modl[3000001], modr[3000001];
int dl[3000001];
int dr[3000001];
int ss = 1;


void change(int i, int x) {
	dl[i] = x;
	while (i / 2 > 0) {
		i /= 2;
		dl[i] = min(dl[i * 2], dl[i * 2 + 1]);
	}
}


void change1(int i, int x) {
	dr[i] = x;
	while (i / 2 > 0) {
		i /= 2;
		dr[i] = min(dr[i * 2], dr[i * 2 + 1]);
	}
}


void push(int v) {
	if (modl[v] != -2) {
		dl[v] = modl[v];
		modl[v * 2] = modl[v];
		modl[v * 2 + 1] = modl[v];
		modl[v] = -2; 
	}
}


void push1(int v) {
	if (modr[v] != -2) {
		dr[v] = modr[v];
		modr[v * 2] = modr[v];
		modr[v * 2 + 1] = modr[v];
		modr[v] = -2; 
	}
}



void add(int v, int vl, int vr, int l, int r, int x) {
	if (vl > r || vr < l) {
		push(v);
		return;
	}
	if (l <= vl && vr <= r) {
		modl[v] = x;
		push(v);
		return;
	}
	push(v);
	add(v * 2, vl, (vl + vr) / 2, l, r, x);
	add(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r, x);
	dl[v] = min(dl[v * 2], dl[v * 2 + 1]);
}



void add1(int v, int vl, int vr, int l, int r, int x) {
	if (vl > r || vr < l) {
		push1(v);
		return;
	}
	if (l <= vl && vr <= r) {
		modr[v] = x;
		push1(v);
		return;
	}
	push1(v);
	add1(v * 2, vl, (vl + vr) / 2, l, r, x);
	add1(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r, x);
	dr[v] = min(dr[v * 2], dr[v * 2 + 1]);
}


int rmq(int v, int vl, int vr, int l, int r) {
	if (vl > r || vr < l) {
		push(v);
		return 1000 * 1000;
	}
	if (l <= vl && vr <= r) {
		push(v);
		return dl[v];
	}
	push(v);
	int ans = min(rmq(v * 2, vl, (vl + vr) / 2, l, r), rmq(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r));
	dl[v] = min(dl[v * 2], dl[v * 2 + 1]);
	return ans;
}



int rmq1(int v, int vl, int vr, int l, int r) {
	if (vl > r || vr < l) {
		push1(v);
		return 1000 * 1000;
	}
	if (l <= vl && vr <= r) {
		push1(v);
		return dr[v];
	}
	push1(v);
	int ans = min(rmq1(v * 2, vl, (vl + vr) / 2, l, r), rmq1(v * 2 + 1, (vl + vr) / 2 + 1, vr, l, r));
	dr[v] = min(dr[v * 2], dr[v * 2 + 1]);
	return ans;
}

int main() {
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] != '.') {
			l[i] = i;
			r[i] = i;
		} else {
			l[i] = (i == 0 ? -1: l[i - 1]);
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '.') {
			if (i == n - 1) {
				r[i] = n; 
			} else {
				r[i] = r[i + 1];
			}
		}
	}
	while (ss < n) {
		ss *= 2;
	}
	for (int i = 0; i < 1200000; i++) {
		modl[i] = -2;
		modr[i] = -2;
	}
	for (int i = 0; i < n; i++) {
		if (i < n - 1) {
			if (s[i] == s[i + 1] && s[i] == '.') {
				sum++;
			}
		}
		change(i + ss, l[i]);
		change1(i + ss, r[i]);
	}
	//cout << sum << endl;
	//cout << l[2] << endl;
	for (int i = 0; i < m; i++) {
		int a;
		char c;
		scanf(" %d %c", &a, &c);
		a--;
		l[a] = l[l[a] + 1];
		r[a] = r[r[a] - 1];
		if (c == '.') {
			if (s[a] != '.') {
				s[a] = '.';
				int r1 = a + 1;
				if (a + 1 < n) {
					if (s[a + 1] == '.') {
						r1 = rmq1(1, 1, ss, a + 2, a + 2);
					}
				}
				int l1 = a - 1;
				if (a > 0) {
					if (s[a - 1] == '.') {
						//cout << "opa" << endl;
						//cout << rmq(1, 1, ss, 1, 1) << endl;
						l1 = rmq(1, 1, ss, a, a);
					//	cout << l1 << endl;
					}
				}
				sum += (r1 - l1 - 2) - (max(0, r1 - (a + 1) - 1) + max(0, (a - 1) - l1 - 1));
				if (l1 + 2 <= r1) {
				//	cout << l1 << ' ' << r1 << endl;
					add(1, 1, ss, l1 + 2, r1, l1);
					//cout << l1 << endl;
					add1(1, 1, ss, l1 + 2, r1, r1);
				}
			}
		} else {
			if (s[a] == '.') {
				int l1 = rmq(1, 1, ss, a + 1, a + 1);
				int r1 = rmq1(1, 1, ss, a + 1, a + 1);
				//cout << l1 << ' ' << r1 << endl;
				sum -= (r1 - l1 - 2) - (max(0, r1 - (a + 1) - 1) + max(0, (a - 1) - l1 - 1));
				r1--;
				l1++;
				if (l1 + 1 <= a) {
					add1(1, 1, ss, l1 + 1, a, a);
				}	
				if (a + 2 <= r1 + 1) {
					add(1, 1, ss, a + 2, r1 + 1, a);
				}	
				add(1, 1, ss, a + 1, a + 1, a);
				add1(1, 1, ss, a + 1, a + 1, a);
			} 	
			s[a] = c;
		}
		//cout << rmq(1, 1, ss, 1, 1) << endl;
		printf("%d\n", sum);
	}
    return 0;
}