#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL read() {LL x; scanf("%lld", &x); return x;}
void read(char *s) {scanf("%s", s);}
void no() {printf("no"); exit(0);}

#define maxn 120
LL cal(LL n){
	LL res = 0;
	while(n){
		res += n % 10;
		n /= 10;
	}
	return res;
}
int main() {
	LL s = 1, n;
	scanf("%lld", &n);
	LL ans = 0;
	while(s - 1 <= n){
		ans = max(ans, cal(s - 1) + cal(n - s + 1));
		s *= 10;
	}
	printf("%lld", ans);
}