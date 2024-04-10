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


int n, m;
int a, b;


int main(){
	cin >> n >> m;
	int n1 = n;
	int m1 = m;
	int t = 0;
	if (t) {
		m--; 
	} else {
		n--;
	}
	int k = 0;
	int ans = 0;
	int ans1 = 0;
	while (n + m > 0) {
		k++;
		k %= 2;
		if (k == 1) {
			if (t) {
				if (n > 0) {
					t = 0;
					n--;
					ans1++;
				} else {
					ans++;
					m--;
					t = 1;
				}
			} else {
				if (m > 0) {
					t = 1;
					m--;
					ans1++;
				} else {
					ans++;
					n--;
					t = 0;
				}
			}
		} else {
			if (t) {
				if (m > 0) {
					t = 1;
					m--;
					ans++;
				} else {
					ans1++;
					n--;
					t = 0;
				}
			} else {
				if (n > 0) {
					t = 0;
					n--;
					ans++;
				} else {
					ans1++;
					m--;
					t = 1;
				}
			}
		}
	}
	n = n1;
	m = m1;
 t = 1;
	if (t) {
		m--; 
	} else {
		n--;
	}
 k = 0;
 int ans2 = 0;
 int ans3 = 0;
	while (n + m > 0) {
		k++;
		k %= 2;
		if (k == 1) {
			if (t) {
				if (n > 0) {
					t = 0;
					n--;
					ans3++;
				} else {
					ans2++;
					m--;
					t = 1;
				}
			} else {
				if (m > 0) {
					t = 1;
					m--;
					ans3++;
				} else {
					ans2++;
					n--;
					t = 0;
				}
			}
		} else {
			if (t) {
				if (m > 0) {
					t = 1;
					m--;
					ans2++;
				} else {
					ans3++;
					n--;
					t = 0;
				}
			} else {
				if (n > 0) {
					t = 0;
					n--;
					ans2++;
				} else {
					ans3++;
					m--;
					t = 1;
				}
			}
		}
	}
	if (ans2 > ans || (ans2 == ans && ans3 < ans1)) {
		cout << ans2 << ' ' << ans3 << endl;
	} else {
		cout << ans << ' ' << ans1 << endl;
	}
	return 0;
}