#include<bits/stdc++.h>
using namespace std;

int num[5000010],n,m,all;
bool bo[1<<22],vis[1<<22];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void dfs(int x)
{
	vis[x]=true;
	if (bo[x]&&!vis[all^x]) dfs(all^x);
	for (int i=0;i<m;i++) if (((1<<i)&x)&&!vis[x^(1<<i)]) dfs(x^(1<<i)); 
}

int main()
{
	m=rd();n=rd();
	for (int i=1;i<=n;i++) num[i]=rd(),bo[num[i]]=true;
	all=(1<<m)-1;
	int ans=0;
	for (int i=1;i<=n;i++) if (!vis[num[i]]) ans++,dfs(num[i]);
	printf("%d\n",ans);
	return 0;
}