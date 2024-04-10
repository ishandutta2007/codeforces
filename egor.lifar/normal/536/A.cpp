#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>


using namespace std;


int a, b, n;


int main() {
	cin >> a >> b >> n;
	for (int i = 0; i < n; i++) {
		int l, t, m;
		scanf("%d %d %d", &l, &t, &m);
		if (1LL * t < 1LL * a + 1LL * (l - 1) * 1LL * b) {
			printf("-1\n");
			continue;
		}
		int l1 = l;
		int r = 3000000;
		while (l1 != r) {
			int m1 = (l1 + r + 1) / 2;
			if (1LL * a + 1LL * (m1 - 1) * b <= 1LL * t) {
				if (1LL * (1LL * a + 1LL * (l - 1) * b) * (m1 - l + 1) + 1LL * b * (m1 - l) * (m1 - l + 1) / 2LL <= 1LL * t * m) {
					l1 = m1; 
					continue;
				}
			}
			r = m1 - 1;
		}
		printf("%d\n", l1);
	}
    return 0;
}