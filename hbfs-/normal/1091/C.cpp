#include <bits/stdc++.h>
#define N 1000500
using namespace std;
typedef long long LL;
int n, tp;
LL o[N];
inline int rd() {int r;scanf("%d",&r);return r;}
int main() {
	n = rd();
	for (int i=1;i<=sqrt(n);i++) {
		if (n % i == 0) {
			LL t = n / i;
			o[++tp] = (0+(t-1)*i) * t / 2 + t;
			if (i * i != n) {
				int j = n / i;
				LL t = n / j;
				o[++tp] = (0+(t-1)*j) * t / 2LL + t;
			}
		}
	}
	sort(o+1, o+tp+1);
	for (int i=1;i<=tp;i++) {
		if (o[i]!=o[i+1]) printf("%I64d%c",o[i],i==tp ? '\n' :' ');
	}
	return 0;
}