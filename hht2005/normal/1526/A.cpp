#include<bits/stdc++.h>
using namespace std;
const int maxn=60;
int a[maxn],b[maxn];
int main() {
	int T,n;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);n*=2;
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		sort(a+1,a+n+1);
		for(int i=1;i<=n/2;i++)b[i*2-1]=a[i];
		for(int i=n/2+1;i<=n;i++)b[(i-n/2)*2]=a[i];
		for(int i=1;i<=n;i++)printf("%d ",b[i]);
		puts("");
	}
	return 0;
}