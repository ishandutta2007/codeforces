#include <bits/stdc++.h>

__int128 a,b,c,d;

__int128 calc(__int128 x) { return x * (x + 1) / 2; }

__int128 check(__int128 a,__int128 b,__int128 c,__int128 d,__int128 t) {
	__int128 x = std::min(t ,c / d + 1);
	return (__int128) a * t - (__int128) (t-x) * b * c - (__int128) calc(x - 1) * d * b;
}
	

void solve() {
	long long A,B,C,D;
	scanf("%lld%lld%lld%lld",&A,&B,&C,&D);
	a=A;b=B;c=C;d=D;
//	for (int i = 1; i <= 20; ++ i) printf("%lld ",check(a,b,c,d,i));
//	puts("");
	__int128 l = 0, r = 1e9; __int128 ans = 0;
	while (r-l > 5) {
		__int128 mid = (l+r)>>1;
		if (check(a,b,c,d,mid) <= check(a,b,c,d,mid + 1)) { l = mid ; }
		else r = mid;
	} for (__int128 i = l; i <= r; ++ i) {
		__int128 p = check(a,b,c,d,i);
		if (p > ans) ans = p;
	}
	if (check(a,b,c,d,r+1) > ans) { puts("-1"); return; }
	long long p = ans;
	printf("%lld\n",p);
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}