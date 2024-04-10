#include<bits/stdc++.h>
using namespace std;
const int maxn=2010;
int a[maxn],b[maxn],c[maxn],d[maxn],X[1000010];
int main() {
	int n,m,ans=1e9;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d%d",a+i,b+i);
	for(int i=1;i<=m;i++)scanf("%d%d",c+i,d+i);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i]<=c[j])X[c[j]-a[i]]=max(X[c[j]-a[i]],d[j]-b[i]+1);
	for(int i=1e6;i>=1;i--)X[i-1]=max(X[i-1],X[i]);
	for(int i=0;i<=1e6;i++)ans=min(i+X[i],ans);
	printf("%d\n",ans);
	return 0;
}