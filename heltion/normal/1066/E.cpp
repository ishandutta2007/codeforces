#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL read() {LL x; scanf("%lld", &x); return x;}
void read(char *s) {scanf("%s", s);}
void no() {printf("-1"); exit(0);}

#define maxn 240000
const LL mod = 998244353;
char a[maxn], b[maxn];
int aa[maxn], bb[maxn];
int main() {
	int n = read(), m = read();
	read(a);
	read(b);
	for(int i = 0; i < n; i += 1) aa[i] = a[n - 1 - i] - '0';
	for(int i = 0; i < m; i += 1) bb[i] = b[m - 1 - i] - '0';
	for(int i = m - 1; i >= 0; i -= 1) bb[i] += bb[i + 1];
	LL ans = 0, p = 1;
	for(int i = 0; i < n; i += 1, p = p * 2 % mod) if(aa[i] == 1){
		ans = (ans + bb[i] * p) % mod;
		//printf("%lld\n", bb[i]);
	}
	printf("%lld", ans);
}