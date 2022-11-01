#include <bits/stdc++.h>
#define N 1000500
typedef long long LL;
using namespace std;
inline int rd() {int r;scanf("%d",&r);return r;}
int n,k,a[N];

int main() {
	n = rd();
	LL tmp;
	scanf("%I64d",&tmp);
	if (tmp > n) k = n; else k = tmp;
	for (int i=1;i<=n;i++) a[i] = rd();
	int cur = 0;
	for (int _=1;_<n;_++) {
		if (a[_]>a[_+1]) {
			cur++;
			swap(a[_], a[_+1]);
			if (cur >= k) {
				printf("%d\n", a[_+1]);
				return 0;
			}
		} else {
			cur = 1;
		}
	}
	if (a[n] > a[1]) {
		cur++;
		swap(a[n], a[1]);
		if (cur >= k) {
			printf("%d\n", a[1]);
			return 0;
		}
	}
	
	printf("%d\n",a[1]);
	return 0;
}