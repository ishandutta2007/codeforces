#include<cstdio>
int q;
long long int vshift[70];
long long int nshift[70];
int main() {
	scanf("%d", &q);
	while (q--) {
		int qt;
		long long int x;
		int layer = 0;
		scanf("%d%lld", &qt, &x);
		long long int y = x;
		while (y > 1) {
			y /= 2;
			layer++;
		}
		if (qt == 1) {
			long long int p;
			scanf("%lld", &p);
			p &= (1LL << layer) - 1;
			vshift[layer] += p;
			vshift[layer] &= (1LL << layer) - 1;
		}
		else if (qt == 2) {
			long long int p;
			scanf("%lld", &p);
			p &= (1LL << layer) - 1;
			nshift[layer] += p;
			nshift[layer] &= (1LL << layer) - 1;
		}
		else {
			x -= (1LL << layer);
			x += vshift[layer];
			x &= (1LL << layer) - 1;
			while (layer >= 0) {
				long long int res = x + (1LL << layer) - vshift[layer];
				res &= (1LL << layer) - 1;
				res += (1LL << layer);
				printf("%lld ", res);
				x += nshift[layer];
				x &= (1LL << layer) - 1;
				x /= 2;
				layer--;
			}
			printf("\n");
		}
	}
	return 0;
}