#include <bits/stdc++.h>
#define N 1000500
using namespace std;
typedef long long LL;
LL a[2*N], sum;
int n;
bool check(LL x) {
	LL t = sqrt(x);
	return t * t == x;
}
inline int rd() {int r;scanf("%d",&r);return r;}
int main() {
	n = rd() / 2;
	for (int i=1;i<=n;i++) a[2*i] = rd();
	LL sum = 0, d = 1;
	for (int i=1;i<=n;i++) {
		while (d*d < sum) d++;
		while (!check(d*d+a[2*i])) {
			++d;
			if (d > 1000000) {
				puts("No");
				return 0;
			}
		}
		a[2*i-1] = d * d - sum;
		sum = d * d + a[2*i];
	}
	puts("Yes");
	for (int i=1;i<=2*n;i++) printf("%I64d%c",a[i],i==2*n?'\n':' ');
	return 0;
}