#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <vector>

using namespace std;


int n;
int f[200];
int g[200];
int c[200];
int ll[200];



long long nod(long long a, long long b) {
	if (a == 0LL) {
		return b;
	}
	return nod(b % a, a);
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &f[i]);
	}
	int k = 0;
	long long t = 1;
	for (int i = 0; i < n; i++) {
		int a = f[i];
		set<int> s;
		s.insert(i + 1);
		while (s.find(a) == s.end()) {
			s.insert(a);
			//cout << a << endl;
			a = f[a - 1];
		}
		//cout << "opa" << endl;
		g[i] = (int)s.size() - 1;
		c[i] = a;
		int h = i + 1;
		for (int j = 1; j <= g[i]; j++) {
			h = f[h - 1];
			if (c[i] == h) {
				ll[i] = j;
				break;
			}
		}
		k = max(k, ll[i]);
//		cout << g[i] - ll[i] + 1 << endl;
		t = t * 1LL * (g[i] - ll[i] + 1) / nod(t, 1LL * (g[i] - ll[i] + 1));
		//cout << c[i] << endl;
	}
	//cout << get(4) << endl;
	//cout << k << endl;
	long long t1 = t;
	while (t1 < 1LL * k) {
		t1 += t;
	}
	cout << t1 << endl;
    return 0;
}