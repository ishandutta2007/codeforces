#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int bx, by, sx, sy, n, tx, ty;
	scanf("%lld %lld %lld", &n, &bx, &by);
	sx = bx;
	sy = by;
	for(int i = 1; i < n; i++) { 
		scanf("%lld %lld", &tx, &ty);
		sx = min(sx, tx);
		sy = min(sy, ty);
		bx = max(bx, tx);
		by = max(by, ty);
	}
	printf("%lld", max((bx - sx) * (bx - sx), (by - sy) * (by - sy)));
	return 0;
}