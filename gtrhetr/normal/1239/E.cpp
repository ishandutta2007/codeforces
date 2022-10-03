#include<bits/stdc++.h>
using namespace std;
#define bs bitset<1250010>
#define inf 2123333333

bs f[52][26];

int ans,id1,id2;
int num[60],h[60],res[60],n,tt;
bool bo[60];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();
	for (int i=1;i<=n*2;i++) num[i]=rd();
	sort(num+1,num+n*2+1);
	ans=inf;id1=id2=0;
	f[n*2+1][0][0]=1;
	int sum=0;
	for (int i=1;i<=n*2;i++) sum+=num[i];
	for (int i=n*2;i>1;i--)
	{
		for (int j=0;j<=n*50000;j++) if (f[i+1][n-1][j])
		{
			int h2=j+num[i],h1=sum-h2;
			if (ans>max(num[1]+h2,num[i]+h1))
			{
				ans=max(num[1]+h2,num[i]+h1);
				id1=i;id2=j;
			}
		}
		for (int j=1;j<=n;j++) f[i][j]=(f[i+1][j]|(f[i+1][j-1]<<num[i]));
	}
	h[tt=1]=id1;
	int now=n-1;
	for (int i=id1+1;i<=n*2;i++)
	{
		if (!now) break;
		if (id2<num[i]) continue;
		if (f[i+1][now-1][id2-num[i]]) h[++tt]=i,id2-=num[i],now--;
	}
	int tot=0;
	for (int i=1;i<=tt;i++) bo[h[i]]=true,res[++tot]=num[h[i]];
	sort(res+1,res+tot+1);
	for (int i=1;i<=tot;i++) printf("%d ",res[i]);puts("");
	tot=0;
	for (int i=1;i<=n*2;i++) if (!bo[i]) res[++tot]=num[i];
	sort(res+1,res+tot+1);
	for (int i=tot;i;i--) printf("%d ",res[i]);puts("");
	return 0;
}