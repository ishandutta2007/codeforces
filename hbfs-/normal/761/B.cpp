#include <iostream>
#include <cstdio>

using namespace std;
#define N 1050
int a[N],b[N],c[N],d[N],n,l;

int main() {
	scanf("%d%d",&n,&l);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	for (int i=1;i<=n;i++) c[i] = a[i] - a[i-1];
	c[1] += l-a[n];
	for (int i=1;i<=n;i++) d[i] = b[i] - b[i-1];
	d[1] += l-b[n];
	for (int i=1;i<=n;i++) {
		int t = i , flag = 1;
		for (int j=1;j<=n;j++) {
			if (c[j] != d[t]) { flag = 0; break; }
			t++; if (t == n+1) t = 1;
		}
		if (flag) {	puts("YES"); return 0; }
	}
	puts("NO");
	return 0;
}