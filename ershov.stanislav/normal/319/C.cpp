#include <cstdio>
#include <iostream>

using namespace std;

#ifdef ONLINE_JUDGE
const int maxn=100000;
#else
const int maxn=100;
#endif

int n, a[maxn+11], b[maxn+11], d[maxn+11];
long long c[maxn+11];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", &a[i]);
	for (int i=0; i<n; i++) scanf("%d", &b[i]);
	c[0]=b[0];
	for (int j=1, i=1, t=1; i<n; i++) {
		c[i]=c[d[j-1]]+((long long)b[d[j-1]])*(a[i]-1)+b[i];
		while (j<i&&c[d[j]]+((long long)b[d[j]])*(a[i]-1)+b[i]<c[i]) c[i]=c[d[j]]+((long long)b[d[j]])*(a[i]-1)+b[i], j++;
		while (t>=2&&((double)c[d[t-1]]-(double)c[d[t-2]])/(b[d[t-2]]-b[d[t-1]]) > ((double)c[i]-(double)c[d[t-2]])/(b[d[t-2]]-b[i])) t--;
		d[t++]=i;
	}
	cout << c[n-1];
    return 0;
}