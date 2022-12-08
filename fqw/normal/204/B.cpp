#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main() {
	int n; map<int, int> a, b, c;
	scanf("%d", &n);
	for(int i=0, x, y; i<n; ++i) {
		scanf("%d%d", &x, &y);
		a[x]++, c[x]++;
		if(x!=y) b[y]++, c[y]++;
	}
	int ans=n, need=(n+1)/2;
	for(map<int, int>::iterator it=c.begin(); it!=c.end(); ++it) {
		int cur=it->first;
		int ca=a[cur];
		int cb=b[cur];
		int tmp=n;
		if(ca>=need) tmp=0;
		else if(ca+cb>=need) tmp=need-ca;
		ans=min(ans, tmp);
	}
	if(ans<n)
		printf("%d\n", ans);
	else
		printf("-1\n");
	return 0;
}