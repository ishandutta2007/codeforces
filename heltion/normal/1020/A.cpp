#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL aabs(LL a){
	return a > 0 ? a : -a;
}
int main(){
	LL n, h, a, b, k;
	scanf("%lld %lld %lld %lld %lld", &n, &h, &a, &b, &k);
	for(int i = 0; i < k; i += 1){
		LL ta, fa, tb, fb;
		scanf("%lld %lld %lld %lld", &ta, &fa, &tb, &fb);
		if(ta == tb) printf("%lld\n", abs(fa - fb));
		else{
			LL ans = 0;
			if(fa > b) ans += fa - b, fa = b;
			if(fa < a) ans += a - fa, fa = a;
			if(fb > b) ans += fb - b, fb = b;
			if(fb < a) ans += a - fb, fb = a;
			printf("%lld\n", ans + abs(fa - fb) + abs(ta - tb));
		}
	}
}