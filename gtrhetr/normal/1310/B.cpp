#include<bits/stdc++.h>
using namespace std;

int num[200010],f[200010][4],n,k,m,tt;
bool bo[200010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void dfs(int x)
{
	if (x>=(1<<m)) return;
	dfs(x<<1);dfs(x<<1|1);
	for (int i=0;i<4;i++) for (int j=0;j<4;j++) f[x][i|j]=max(f[x][i|j],f[x<<1][i]+f[x<<1|1][j]+(i|j));
}

int main()
{
	n=rd();k=rd();
	for (int i=1;i<=k;i++) num[i]=rd();
	if (!k) { puts("0");return 0; }
	for (int i=1;i<=k;i++) bo[num[i]-1]=true;
	int ans=1;
	for (int i=0;i<(1<<n);i+=2) if (bo[i]||bo[i+1]) ans++;
	m=n-2;tt=1<<m;
	memset(f,-0x3f,sizeof(f));
	for (int i=0;i<(1<<n);i+=4)
	{
		int cnt=bo[i]+bo[i+1]+bo[i+2]+bo[i+3];
		f[tt][0]=0;
		if (cnt==1) f[tt][1]=1,f[tt][2]=2;
		if (cnt>=2) f[tt][3]=3;
		tt++;
	}
	dfs(1);
	int res=0;
	for (int i=0;i<4;i++) res=max(res,f[1][i]);
	printf("%d\n",ans+res);
	return 0;
}