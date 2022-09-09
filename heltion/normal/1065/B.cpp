#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL read() {LL x; scanf("%lld", &x); return x;}
void read(char *s) {scanf("%s", s);}
void no() {printf("no"); exit(0);}

#define maxn 

int main(){
	LL n = read(), m = read();
	LL ans = n;
	for(LL k = n; k >= 0; k -= 1)
		if(k * (k - 1) / 2 >= m) ans = n - k;
	printf("%lld %lld", max(n - 2 * m, 0LL), ans);
}