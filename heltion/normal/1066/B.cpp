#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL read() {LL x; scanf("%lld", &x); return x;}
void read(char *s) {scanf("%s", s);}
void no() {printf("-1"); exit(0);}

#define maxn 1200
int a[maxn], f[maxn];
int main() {
	int n = read(), r = read(), ans = 0;
	for(int i = 0; i < n; i += 1) a[i] = read();
	for(int i = 0; i < n; i += 1) if(f[i] == 0){
		int k = -1;
		for(int j = 0; j < n; j += 1)
			if(a[j] && abs(j - i) + 1 <= r) k = j;
		if(k == -1) no();
		ans += 1;
		for(int j = i; j < n && j <= k + r - 1; j += 1) f[j] = 1;
	}
	printf("%d", ans);
}