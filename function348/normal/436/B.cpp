#include<cstdio>
#include<iostream>
#define rep(i,a,b) for (int i=a;i<=b;i++)
using namespace std;
char s[2010];
int n,m,k;
int v[2010];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n)
	{
		scanf("%s",s);
		rep(j,1,m)
		{
			char ch=s[j-1];
			int k=0;
			if (ch=='.') continue;
			if (ch=='L') k=j-i+1;
			if (ch=='R') k=i+j-1;
			if (ch=='U') if (i&1) k=j;else k=0;
			if (k>0&&k<=m) v[k]++;
		}
	}
	rep(i,1,m) printf("%d%c",v[i],i<m?' ':'\n');
	return 0;
}