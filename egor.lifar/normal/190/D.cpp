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



int n, k;
int a[400000];
map<int, int> m;
long long s = 0;


int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int l = 0;
	int t = 0;
	for (int i = 0; i < n; i++) {
		m[a[i]]++;
		if (m[a[i]] == k) {
			t++;
		}
		while (l < i) {
			//cout << i + 1 << ' ' << a[l] << ' ' << m[a[l]] << endl;
			if (t > 0 && !(m[a[l]] == k && t == 1)) {
				m[a[l]]--;
				if (m[a[l]] == k - 1) {
					t--;
				}
				//cout << i + 1 << endl;
				l++;
			} else {
				break;
			}
		}
		//cout << t << ' ' << l << endl;
		//cout << l + 1 << ' ' << i + 1 << endl;
		if (t > 0) {
			s += l + 1;
		}
	}
	cout << s << endl;
    return 0;
}