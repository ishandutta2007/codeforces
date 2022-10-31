#include<cstdio>
#include<iostream>
using namespace std;
int cas,n,m;
char s[4][200];
int ok(int i,int j) 
{ 
	if (i==0||i==4) return 0;
	if (j>n) return 1;
	if (s[i][j]=='.'||s[i][j]=='s') return 1;
	return 0;
}
int main()
{
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d%d",&n,&m);
		scanf("%s",s[1]+1);
		scanf("%s",s[2]+1);
		scanf("%s",s[3]+1);
		for (int j=1;j<=n;j++)
		for (int i=1;i<=3;i++)
		if (s[i][j]=='s')
		{
			if (ok(i,j+1)&&ok(i,j+2)&&ok(i,j+3)) s[i][min(j+3,n)]='s';
			if (ok(i,j+1)&&ok(i-1,j+1)&&ok(i-1,j+2)&&ok(i-1,j+3)) s[i-1][min(j+3,n)]='s';
			if (ok(i,j+1)&&ok(i+1,j+1)&&ok(i+1,j+2)&&ok(i+1,j+3)) s[i+1][min(j+3,n)]='s';
		}
		if (s[1][n]=='s'||s[2][n]=='s'||s[3][n]=='s') printf("YES\n");else printf("NO\n");
	}
	return 0;
}