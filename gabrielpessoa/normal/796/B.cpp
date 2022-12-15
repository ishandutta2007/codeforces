#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, k, dum, u, v, p = 1;
	scanf("%d %d %d", &n, &m, &k);
	bool hole[n+1];
	for (int i = 1; i <= n; i++) {
		hole[i] = false;
	}
	while(m--) {
		scanf("%d", &dum);
		hole[dum] = true;
	}
	for(int i = 0; i < k && hole[p] == false; i++) {
		scanf("%d %d", &u, &v);
		if(u == p) {
			p = v;
		} else if (v == p) {
			p = u;
		}
	}
	printf("%d", p);
	return 0;
}