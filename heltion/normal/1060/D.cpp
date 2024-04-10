#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL read() {LL x; scanf("%lld", &x); return x;}
void read(char *s) {scanf("%s", s);}
void no() {printf("no"); exit(0);}

#define maxn 120000
LL l[maxn], r[maxn];
int main() {
	int n = read();
	for(int i = 0; i < n; i += 1) l[i] = read(), r[i] = read();
	sort(l, l + n);
	sort(r, r + n);
	LL ans = n;
	for(int i = 0; i < n; i += 1) ans += max(l[i], r[i]);
	printf("%lld", ans);
}