#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <cmath>
#include <set>
#include <map>


using namespace std;


int n, x[100];
int a;
int ans = 0;
bool b[100];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	sort(x, x + n);
	bool t = true;
	a = x[0];
	ans = 1;
	int k = 1;
	b[0] = true;
	while(t) {
		t = false;
		bool t1 = false;
		for (int i = 0; i < n; i++) {
			if (!b[i] && x[i] >= k) {
				a = x[i];
				b[i] = true;
				k++;
				t1 = true;
				t = true;
				break;
			}
		}
		if (!t1) {
			for (int i = 0; i < n; i++) {
				if (!b[i]) {
					t = true;
					a = x[i];
					k = 1;
					b[i] = true;
					ans++;
					break;
				}
			}
		}
	}
	cout << ans << endl;
    return 0; 
}///