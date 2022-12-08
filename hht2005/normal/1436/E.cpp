#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn],c[maxn],pre[maxn],las[maxn],mex[maxn],n;
void Min(int x,int v) {
	for(int i=x;i<=n;i+=i&-i)
		c[i]=min(c[i],v);
}
int qry(int x) {
	int Min=1e9;
	for(int i=x;i;i-=i&-i)Min=min(Min,c[i]);
	return Min;
}
int main() {
	memset(c,0x3f,sizeof(c));
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",a+i);
		if(a[i]!=1)mex[1]=1;
		pre[i]=las[a[i]];
		las[a[i]]=i;
	}
	for(int i=1;i<=n;i++)Min(i,las[i]);
	for(int i=2;i<=n+1;i++)
		if(qry(i-1)>las[i])mex[i]=1;
	for(int i=n;i>=1;i--) {
		Min(a[i],pre[i]);
		if(a[i]!=1&&qry(a[i]-1)>pre[i])mex[a[i]]=1;
	}
	int ans=1;
	while(mex[ans])ans++;
	printf("%d\n",ans);
	return 0;
}