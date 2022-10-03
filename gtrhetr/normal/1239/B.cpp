#include<bits/stdc++.h>
using namespace std;
#define ll long long
 
int mn1[300010],mn2[300010];
int pre[300010],suf[300010],sum1[300010],sum2[300010];
int sum[300010],h[300010],num[300010],n,tt,l,r,ans;
char s[300010];
 
inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}
 
int main()
{
	n=rd();
	scanf("%s",s+1);
	int S=0;
	for (int i=1;i<=n;i++) S+=(s[i]=='(')?1:-1,num[i]=(s[i]=='(')?1:-1;
	if (S!=0) { puts("0");puts("1 1");return 0; }
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+(s[i]=='('?1:-1);
	int mn=sum[0];
	for (int i=1;i<n;i++) mn=min(mn,sum[i]);
	int cnt=0;
	for (int i=0;i<n;i++) if (sum[i]==mn) cnt++;
	for (int i=0;i<=n;i++) if (sum[i]==mn) h[++tt]=i;
	ans=cnt;l=r=1;
	pre[0]=0;suf[n]=sum[n];
	for (int i=1;i<=n;i++) pre[i]=min(pre[i-1],sum[i]);
	for (int i=n-1;i>=0;i--) suf[i]=min(suf[i+1],sum[i]);
	int id1=-1,id2=-1;
	for (int i=0;i<h[1];i++) if (pre[i]>=mn+2&&num[i+1]==-1) id1=i;
	for (int i=n;i>h[tt];i--) if (suf[i]>=mn+2&&num[i]==1) id2=i;
	if (id1>=0&&id2>=0)
	{
		int res=0;
		for (int i=0;i<=id1;i++) if (sum[i]==mn+2) res++;
		for (int i=n-1;i>=id2;i--) if (sum[i]==mn+2) res++;
		for (int i=id1+1;i<id2;i++) if (sum[i]==mn) res++;
		if (res>ans) ans=res,l=id1+1,r=id2;
	}
	if (h[1]>0&&h[tt]<n)
	{
		int res=0;
		for (int i=0;i<h[1];i++) if (sum[i]==mn+1) res++;
		for (int i=n-1;i>h[tt];i--) if (sum[i]==mn+1) res++;
		if (res>ans) ans=res,l=h[1],r=h[tt]+1;
	}
	for (int i=1;i<tt;i++)
	{
		int res=0;
		for (int j=h[i]+1;j<h[i+1];j++) if (sum[j]==mn+1) res++;
		if (res>ans) ans=res,l=h[i]+1,r=h[i+1];
		int id=-1;
		for (int j=h[i]+1;j<h[i+1];j++) if (sum[j]==mn+1)
		{
			if (id==-1) id=j;
			else
			{
				int res=cnt;
				for (int k=id+1;k<j;k++) if (sum[k]==mn+2) res++;
				if (res>ans) ans=res,l=id+1,r=j;
				id=j;
			}
		}
	}
	tt=0;
	for (int i=0;i<=n;i++) if (sum[i]<=mn+1) h[++tt]=i;
	for (int i=1;i<tt;i++)
	{
		if (h[i]+1==h[i+1]) continue;
		int res=cnt;
		for (int j=h[i]+1;j<h[i+1];j++) if (sum[j]==mn+2) res++;
		if (res>ans) ans=res,l=h[i]+1,r=h[i+1];
	}
	printf("%d\n",ans);
	printf("%d %d\n",l,r);
	return 0;
}