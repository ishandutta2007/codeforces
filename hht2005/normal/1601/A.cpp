#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int main() {
	int T,n;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		int g=0;
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		for(int i=0;i<=30;i++) {
			int sum=0;
			for(int j=1;j<=n;j++)
				if(a[j]>>i&1)sum++;
			g=__gcd(g,sum);
		}
		for(int i=1;i<=n;i++)
			if(g%i==0)printf("%d ",i);
		puts("");
	}
	return 0;
}