#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int a[maxn],Max[maxn],s[maxn];
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",a+i);
		s[i]=s[i-1]^a[i];
		for(int j=30;j>=0;j--)
			if(a[i]>>j&1) {
				Max[i]=j;
				break;
			}
	}
	for(int i=3;i<=n;i++)
		if(Max[i]==Max[i-2]) {
			puts("1");
			return 0;
		}
	int ans=1e9;
	for(int i=1;i<n;i++)
		for(int j=1;j<=i;j++)
			for(int k=i+1;k<=n;k++)
				if((s[j-1]^s[i])>(s[k]^s[i]))
					ans=min(ans,k-j-1);
	if(ans>=1e8)puts("-1");
	else printf("%d\n",ans);
	return 0;
}