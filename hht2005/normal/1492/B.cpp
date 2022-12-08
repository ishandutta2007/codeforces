#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn],Max[maxn];
int main() {
	int T,n;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		for(int i=1;i<=n;i++)
			if(a[i]>a[Max[i-1]])Max[i]=i;
			else Max[i]=Max[i-1];
		while(n) {
			for(int i=Max[n];i<=n;i++)
				printf("%d ",a[i]);
			n=Max[n]-1;
		}
		puts("");
	}
	return 0;
}