#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=100010;
int n,m;
char s[N];
int x[N],y[N],z[N];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++)
	{
		x[i]=x[i-1];y[i]=y[i-1];z[i]=z[i-1];
		if (s[i]=='x') x[i]++;
		if (s[i]=='y') y[i]++;
		if (s[i]=='z') z[i]++;
	}
	scanf("%d",&m);
	while (m--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		l--;
		int a=x[r]-x[l],b=y[r]-y[l],c=z[r]-z[l];
		if (max(max(a,b),c)-min(min(a,b),c)<=1) printf("YES\n");else 
		if (l+2==r&&s[l+1]==s[r]) printf("YES\n");else printf("NO\n");
	}
	return 0;
}