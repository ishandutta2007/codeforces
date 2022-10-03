#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll f[60][110][2];
ll bin[60],num[60],s,tt;

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	s=rd();bin[0]=1;
	for (int i=1;i<=51;i++) bin[i]=bin[i-1]*2;
	ll ans=0;
	for (int h=1;bin[h]-1<=s;h++)
	{
		ll hh=s%(bin[h]-1);
		for (int j=h-1;j;j--) if (bin[j]-1<=hh) hh-=bin[j]-1;
		ans+=(!hh);
	}
	for (int h0=1;h0<=50;h0++) for (int h1=1;h1<=50;h1++) if (bin[h0+1]+bin[h1+1]-3<=s-bin[h1]+1)
	{
		ll hh=(s-bin[h1]+1)%(bin[h0+1]+bin[h1+1]-3);
		for (int n=0;n<=h0+h1-2;n++)
		{
			tt=0;ll now=hh+n;
			if (now&1) continue;
			memset(num,0,sizeof(num));
			for (now>>=1;now;now>>=1) num[++tt]=now&1;
			memset(f,0,sizeof(f));
			f[0][0][0]=1;
			for (int i=1;i<=tt;i++) for (int j=0;j<=n;j++) for (int k=0;k<2;k++) if (f[i-1][j][k])
			{
				for (int l1=0;l1<2;l1++) for (int l2=0;l2<2;l2++)
				{
					if ((i>=h0&&l1)||(i>=h1&&l2)) continue;
					int hh=l1+l2+k,now=j+l1+l2;
					if ((hh&1)==num[i]) f[i][now][hh>>1]+=f[i-1][j][k];
				}
			}
			ans+=f[tt][n][0];
		}
	}
	printf("%lld\n",ans);
	return 0;
}