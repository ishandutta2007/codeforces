#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int a[maxn],f[maxn][2];
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		f[1][0]=1e9;
		f[1][1]=a[1];
		f[2][0]=a[1];
		f[2][1]=a[1]+a[2];
		for(int i=3;i<=n;i++) {
			f[i][0]=min(f[i-1][1],f[i-2][1]);
			f[i][1]=min(f[i-1][0]+a[i],f[i-2][0]+a[i]+a[i-1]);
		}
		printf("%d\n",min(f[n][0],f[n][1]));
	}
	return 0;
}