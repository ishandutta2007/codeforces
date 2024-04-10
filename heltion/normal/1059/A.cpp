#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL read() {LL x; scanf("%lld", &x); return x;}
void read(char *s) {scanf("%s", s);}
void no() {printf("no"); exit(0);}
#define maxn 120000
LL t[maxn], l[maxn];
int main() {
	LL n = read(), L = read(), a = read();
	for(int i = 0; i < n; i += 1)
		t[i] = read(), l[i] = read(); 
	LL ans = 0;
	ans += t[0] / a;
	for(int i = 0; i + 1 < n; i += 1)
		ans += (t[i + 1] - t[i] - l[i]) / a;
	ans += (L - t[n - 1] - l[n - 1]) / a;
	printf("%lld", ans);
}