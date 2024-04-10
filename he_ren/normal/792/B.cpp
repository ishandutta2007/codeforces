#include<cstdio>
const int MAXN = 100 + 5;

int a[MAXN];
int nxt[MAXN],lst[MAXN];

int main(void)
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1; i<=k; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<n; ++i) nxt[i]=i+1;
	nxt[n]=1;
	for(int i=2; i<=n; ++i) lst[i]=i-1;
	lst[1]=n;
	
	int now=1;
	for(int j=1; j<=k; ++j)
	{
		a[j]%=n-j+1;
		for(int i=0; i<a[j]; ++i) now=nxt[now];
		printf("%d ",now);
		nxt[lst[now]]=nxt[now];
		lst[nxt[now]]=lst[now];
		now=nxt[now];
	}
	return 0;
}