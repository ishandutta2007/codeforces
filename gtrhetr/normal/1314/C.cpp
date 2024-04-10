#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define inf 2333333333333333333LL

pii h[1000010];

ll f[1010][1010],sum[1010][1010],k;
int mx[1010][1010],num[1010],id[1010],n,m,tt;
char s[1010];

inline ll rd()
{
	ll x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline bool cmp(const int &x,const int &y) { return s[x+mx[x][y]]<s[y+mx[x][y]]; }

inline ll calc(int mid)
{
	memset(f,0,sizeof(f));
	memset(sum,0,sizeof(sum));
	f[n+1][0]=sum[n+1][0]=1;
	int l=h[mid].first,r=h[mid].second,len=r-l+1;
	for (int i=n;i;i--)
	{
		int mn=n+1;
		if (id[i]<id[l])
		{
			if (mx[i][l]>=len) mn=i+len;
			else
			{
				for (int j=0;j<=n;j++) sum[i][j]=min(inf,sum[i+1][j]+f[i][j]);
				continue;
			}
		}
		else if (id[i]==id[l]) mn=i+len;
		else
		{
			if (mx[i][l]>=len) mn=i+len;
			else mn=i+mx[i][l]+1; 
		}
		for (int j=1;j<=n-i+1;j++) f[i][j]=sum[mn][j-1];
		for (int j=0;j<=n;j++) sum[i][j]=min(inf,sum[i+1][j]+f[i][j]);
	}
	return f[1][m];
}

int main()
{
	n=rd();m=rd();k=rd();
	scanf("%s",s+1);s[n+1]=-1;
	for (int i=n;i;i--)
	{
		mx[i][i]=n-i+1;
		for (int j=i+1;j<=n;j++) mx[i][j]=mx[j][i]=(s[i]==s[j])?mx[i+1][j+1]+1:0;
	}
	for (int i=1;i<=n;i++) num[i]=i;
	sort(num+1,num+n+1,cmp);
	for (int i=1;i<=n;i++) id[num[i]]=i;
	for (int i=1;i<=n;i++) for (int j=num[i]+mx[num[i]][num[i-1]];j<=n;j++) h[++tt]=pii(num[i],j);
	int l=1,r=tt;
	while (l<r)
	{
		int mid=((l+r)>>1)+1;
		if (calc(mid)>=k) l=mid;
		else r=mid-1;
	}
	for (int i=h[l].first;i<=h[l].second;i++) putchar(s[i]);
	putchar('\n');
	return 0;
}