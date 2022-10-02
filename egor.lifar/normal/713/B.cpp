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
#include <bitset>
#include <unordered_map>


using namespace std;


int n;
//int X, Y, X1, Y1;
//int X2, Y2, X3, Y3;
int cnt = 0;


int query(int x1, int y1, int x2, int y2) {
	printf("? %d %d %d %d\n", x1, y1, x2, y2);
	fflush(stdout);
	int ans = 0;
	// cnt++;
	// if (X >= x1 && X1 <= x2 && Y >= y1 && Y1 <= y2) {
	// 	ans++;
	// }
	// if (X2 >= x1 && X3 <= x2 && Y2 >= y1 && Y3 <= y2) {
	// 	ans++;
	// }
	scanf("%d", &ans);
	return ans; 
}


int ansx[2][2], ansy[2][2];


void findreck(int a, int b, int c, int d) {
	int l, r;
	l = a;
	r = c;
	while (l != r) {
		int m = (l + r) / 2;
		if (query(a, b, m, d) >= 1) {
			r = m;
		} else {
			l = m + 1;
		}
	}
	ansx[1][1] = l;
	l = a;
	r = c;
	while (l != r) {
		int m = (l + r + 1) / 2;
		if (query(m, b, c, d) >= 1) {
			l = m;
		} else {
			r = m - 1;
		}
	}
	ansx[1][0] = l;
	l = b;
	r = d;
	while (l != r) {
		int m = (l + r) / 2;
		if (query(a, b, c, m) >= 1) {
			r = m;
		} else {
			l = m + 1;
		}
	}
	ansy[1][1] = l;
	l = b;
	r = d;
	while (l != r) {
		int m = (l + r + 1) / 2;
		if (query(a, m, c, d) >= 1) {
			l = m;
		} else {
			r = m - 1;
		}
	}
	ansy[1][0] = l;
}



int main() {
	cin >> n;
	//cin >> X >> Y >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3;
	int l = 1;
	int r = n;
	while (l != r) {
		int m = (l + r) / 2;
		if (query(1, 1, m, n) >= 1) {
			r = m;
		} else {
			l = m + 1;
		}
	}
	if (query(1, 1, l, n) == 1) {
		ansx[0][1] = l;
		int L = l;
		l = 1;
		r = L;
		while (l != r) {
			int m = (l + r + 1) / 2;
			if (query(m, 1, L, n) >= 1) {
				l = m;
			} else {
				r = m - 1;
			}
		}
		ansx[0][0] = l;
		l = 1;
		r = n;
		while (l != r) {
			int m = (l + r) / 2;
			if (query(1, 1, L, m) >= 1) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		ansy[0][1] = l;
		l = 1;
		r = n;
		while (l != r) {
			int m = (l + r + 1) / 2;
			if (query(1, m, L, n) >= 1) {
				l = m;
			} else {
				r = m - 1;
			}
		}
		ansy[0][0] = l;
		if (query(ansx[0][1] + 1, 1, n, n)) {
			findreck(ansx[0][1] + 1, 1, n, n);
		} else {
			if (ansy[0][1] != n && query(1, ansy[0][1] + 1, n, n)) {
				findreck(1, ansy[0][1] + 1, n, n);
			} else {
				findreck(1, 1, n, ansy[0][0] - 1);
				//cout << "opa" << endl;
			}
		}
	} else {
		ansx[0][1] = l;
		ansx[1][1] = l;
		int L = l;
		l = 1;
		r = n;
		while (l != r) {
			int m = (l + r) / 2;
			if (query(1, 1, L, m) >= 1) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		ansy[0][1] = l;
		l = 1;
		r = n;
		while (l != r) {
			int m = (l + r + 1) / 2;
			if (query(1, m, L, n) >= 1) {
				l = m;
			} else {
				r = m - 1;
			}
		}
		ansy[1][0] = l;
		l = 1;
		r = n;
		while (l != r) {
			int m = (l + r) / 2;
			if (query(1, 1, L, m) >= 2) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		ansy[1][1] = l;
		l = 1;
		r = n;
		while (l != r) {
			int m = (l + r + 1) / 2;
			if (query(1, m, L, n) >= 2) {
				l = m;
			} else {
				r = m - 1;
			}
		}
		//cout << l << endl;
		//fflush(stdout);
		ansy[0][0] = l;
		l = 1;
		r = L;
		while (l != r) {
			int m = (l + r + 1) / 2;
			if (query(m, ansy[0][0], L, ansy[0][1]) >= 1) {
				l = m;
			} else {
				r = m - 1;
			}
		}	
		ansx[0][0] = l;
		l = 1;
		r = L;
		while (l != r) {
			int m = (l + r + 1) / 2;
			if (query(m, ansy[1][0], L, ansy[1][1]) >= 1) {
				l = m;
			} else {
				r = m - 1;
			}
		}	
		ansx[1][0] = l;
	}
	cout << "!";
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cout << ' ' << ansx[i][j] << ' ' << ansy[i][j];
		}
	}
	cout << endl;
	//cout << cnt << endl;
    return 0;
}