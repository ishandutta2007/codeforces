#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)


map<long long, long long> inc;
int n;

void solve() {
	scanf("%d", &n);
	REP(i,n) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			long long u,v; long long w;
			scanf("%lld %lld %lld", &u, &v, &w);
			while (u != v) {
				if (u > v) swap(u,v);
				inc[v] += w;
				v >>= 1;
			}
		}
		else {
			long long u,v; long long w = 0;
			scanf("%lld %lld", &u, &v);
			while (u != v) {
				if (u > v) swap(u,v);
				w += inc[v];
				v >>= 1;
			}
			printf("%lld\n", w);
		}
	}
}

int main() {
    solve();
}