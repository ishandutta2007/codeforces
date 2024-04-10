#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <vector>
#include <map>
 

using namespace std;


int n, m;
int s[10000001];
int x[1000001];
bool b[10000001];
vector<int> p;
int d[10000001], t[10000001];


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) { 
		scanf("%d", &x[i]);
		s[x[i]]++;
	}
	for (int i = 2; i <= 10000000; i++) {
		if (!b[i]) {
			p.push_back(i);
			long long s = 1LL * i * i;
			while (s <= 10000000) {
				b[s] = true;
				s += (long long)i;
			}
		}
	}
	for (int i = 0; i < (int)p.size(); i++) {
		int x1 = p[i];
		while (x1 <= 10000000) {
			t[i] += s[x1];
			x1 += p[i];
		}
		d[i] = (i > 0 ? d[i - 1]: 0) + t[i];
	}
	//cout << p[3] << endl;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int l, r;
		scanf("%d %d", &l, &r);
		r = min(r, 10000000);
		if (l > r) {
			printf("0\n");
			continue;
		}
		int i1 = distance(p.begin(), upper_bound(p.begin(), p.end(), l - 1));
		int i2 = distance(p.begin(), upper_bound(p.begin(), p.end(), r)) - 1;
		//cout << d[i2] << endl; 
		if (i2 >= i1 && i2 < (int)p.size()) {
			printf("%d\n", d[i2] - (i1 > 0 ? d[i1 - 1]: 0));
		} else {
			printf("0\n");
		}
	}
	return 0;
}