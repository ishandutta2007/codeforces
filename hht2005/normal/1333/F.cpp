#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int p[maxn],f[maxn],d[maxn],tot;
int main() {
	int n;
	scanf("%d",&n);
	d[1]=1;
	for(int i=2;i<=n;i++) {
		if(!f[i])p[++tot]=i,d[i]=1;
		for(int j=1;j<=tot&&p[j]*i<=n;j++) {
			f[i*p[j]]=1;
			d[i*p[j]]=i;
			if(i%p[j]==0)break;
		}
	}
	sort(d+1,d+1+n);
	for(int i=2;i<n;i++)
		printf("%d ",d[i]);
	printf("%d\n",d[n]);
	return 0;
}