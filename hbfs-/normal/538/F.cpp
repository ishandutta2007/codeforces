#include <bits/stdc++.h>
#define N 200050
using namespace std;
int a[N],cf[N],ans[N],n;
inline int rd() {int r;scanf("%d",&r);return r;}
int main() {
	n = rd();
	for (int i=1;i<=n;i++) a[i] = rd();
	for (int i=2;i<=n;i++) {
		for (int k=1,lst;k<=i-2;k=lst+1) {
			lst = (i-2) / ((i-2) / k);
			if (a[i] < a[(i-2) / k + 1]) {
				cf[k]++;
				cf[lst+1]--;
			}
		}
		if (a[i] < a[1]) {
			cf[i-1]++;
			cf[n]--;
		}
	}
	for (int i=1;i<n;i++) ans[i] = ans[i-1] + cf[i];
	for (int i=1;i<n;i++) printf("%d%c",ans[i],i==n-1?'\n':' ');
	return 0;
}