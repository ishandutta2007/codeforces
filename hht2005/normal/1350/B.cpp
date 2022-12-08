#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn],f[maxn];
int main() {
	int T,n;
	scanf("%d",&T);
	while(T--) {
		int ans=1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",a+i),f[i]=1;
		for(int i=1;i<=n;i++) {
			ans=max(ans,f[i]);
			for(int j=i+i;j<=n;j+=i)
				if(a[j]>a[i])f[j]=max(f[j],f[i]+1);
		}
		printf("%d\n",ans);
	}
	return 0;
}