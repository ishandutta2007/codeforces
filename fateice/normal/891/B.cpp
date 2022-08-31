#include<bits/stdc++.h>
#define L long long
using namespace std;
int n,a[30],b[30],c[30],p;
inline bool cmp(int i,int j)
{
	return a[i]<a[j];
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	  c[i]=i;
	sort(c+1,c+n+1,cmp);
	for(i=1;i<n;i++)
	  b[c[i]]=a[c[i+1]];
	b[c[n]]=a[c[1]];
	for(i=1;i<=n;i++)
	  printf("%d ",b[i]);
	printf("\n");
	return 0;
}