#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=100010;
char s[N];
int v[30][30][30],v2[30][30][30];
int vis[N][5];
int cnt,n,tot;
int same(int i,int j,int k)
{
	for (int p=0;p<k;p++) 
	if (s[i+p]!=s[j+p]) return 0;
	return 1;
}
void dfs(int n,int k)
{
	if (vis[n][k]) return;
	vis[n][k]=1;
	if ((!same(n-1,n+1,k)||k!=2)&&n-2>=5)
	{
		if (!v2[s[n-1]][s[n]][26]) cnt++;
		v2[s[n-1]][s[n]][26]=1;
		dfs(n-2,2);
	}
	if ((!same(n-2,n+1,k)||k!=3)&&n-3>=5)
	{
		if (!v2[s[n-2]][s[n-1]][s[n]]) cnt++;
		v2[s[n-2]][s[n-1]][s[n]]=1;
		dfs(n-3,3);
	}
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++) s[i]-='a';
	dfs(n,0);
	printf("%d\n",cnt);
	for (int i=0;i<26;i++)
	for (int j=0;j<26;j++)
	{
		if (v2[i][j][26]) printf("%c%c\n",i+'a',j+'a');
		for (int k=0;k<26;k++)
		if (v2[i][j][k]) printf("%c%c%c\n",i+'a',j+'a',k+'a');
	}
	return 0;
}