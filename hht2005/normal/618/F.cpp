#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long a[N],b[N],c[N],t[N];
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%lld",a+i);
		a[i]+=a[i-1];
	}
	for(int i=1;i<=n;i++) {
		scanf("%lld",b+i);
		b[i]+=b[i-1];
	}
	memset(t,-1,sizeof(t));
	t[0]=0;
	for(int i=1;i<=n;i++) {
		c[i]=c[i-1];
		while(c[i]<n&&a[i]>=b[c[i]+1])
			c[i]++;
		if(~t[a[i]-b[c[i]]]) {
			int j=t[a[i]-b[c[i]]];
			printf("%d\n",i-j);
			for(int k=j+1;k<=i;k++)
				printf("%d ",k);
			puts("");
			printf("%d\n",c[i]-c[j]);
			for(int k=c[j]+1;k<=c[i];k++)
				printf("%d ",k);
			puts("");
			return 0;
		}
		t[a[i]-b[c[i]]]=i;
	}
	return 0;
}