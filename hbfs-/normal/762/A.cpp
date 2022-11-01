#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
typedef long long LL;
LL n,k;
int p[30000050],cnt;
int main() {
	cin >> n >> k;
	int tp = sqrt(n);
	for (int i=1;i<=tp;i++) {
		if (1LL*i*i == n) k++;
		if (n % i == 0) p[++cnt] = i;
		if (k == cnt) {
			printf("%d\n",p[cnt]); return 0;
		}
	}
	if (k > 2*cnt) puts("-1"); else cout << n/(1LL*p[2*cnt+1-k]) << endl;
	return 0;
}