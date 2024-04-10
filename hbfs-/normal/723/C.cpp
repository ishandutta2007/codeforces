#include <iostream>
#include <cstdio>

#define N 5050

using namespace std;

int n,m,a[N],F[N],o[N];

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if (a[i] <= m) F[ a[i] ]++;	 
	} 
	int ans = (n / m) , tot = 0;
	 
	for (int i=1;i<=m;i++) if (F[i] < ans) tot += ans - F[i];
	
	printf("%d %d\n",ans,tot);
	
	for (int i=1;i<=n;i++) if (a[i] <= m && F[ a[i] ] <= ans || !tot) {
		printf("%d ",a[i]);
	} else {
		for (int j=1;j<=m;j++) if (tot && F[j] < ans) {
			printf("%d ",j); tot--; F[j]++; if (a[i] <= m) F[ a[i] ]--;
			break;
		}
	}
	
	
	
	return 0;
}