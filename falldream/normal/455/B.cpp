#include<cstdio>
#define MN 100000
char s[MN+5];
int c[MN+5][26],tn,f[MN+5][2];
inline int to(int x,int y){return c[x][y]?c[x][y]:c[x][y]=++tn;}
void dp(int x)
{
	int i,u=0;
	for(i=0;i<26;++i)if(c[x][i])
	{
		dp(c[x][i]);u=1;
		f[x][0]|=!f[c[x][i]][0];
		f[x][1]|=!f[c[x][i]][1];
	}
	if(!u)f[x][1]=1;
}
int main()
{
	int n,k,i,j;
	scanf("%d%d",&n,&k);
	while(n--)
	{
		scanf("%s",s);
		for(i=j=0;s[i];++i)j=to(j,s[i]-'a');
	}
	dp(0);
	if(f[0][0]&&f[0][1])puts("First");
	else if(f[0][0])puts(k&1?"First":"Second");
	else puts("Second");
}