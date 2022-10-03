#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

pii h[100010];

int c[100010],from[100010],num[100010],t,n,tt,cnt;
bool bo[100010],bo2[100010],now[30];
char s[100010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void print(int x)
{
	static char s[233];
	if (!x) { putchar('0');putchar(' ');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar(' ');
}

inline void gao()
{
	if (!tt) return;
	printf("Q %d ",tt);
	for (int i=1;i<=tt;i++) print(h[i].first),print(h[i].second);
	putchar('\n');fflush(stdout);
	scanf("%s",s+1);
}

int main()
{
	t=rd();
	while (t--)
	{
		n=rd();
		memset(bo,false,sizeof(bo));
		tt=0;
		for (int i=1;i<n;i+=2) h[++tt]=pii(i,i+1);
		gao();
		for (int i=1;i<=tt;i++) bo[h[i].first]=(s[i]=='1');
		tt=0;
		for (int i=2;i<n;i+=2) h[++tt]=pii(i,i+1);
		gao();
		for (int i=1;i<=tt;i++) bo[h[i].first]=(s[i]=='1');
		c[cnt=1]=1;
		for (int i=2;i<=n;i++) if (!bo[i-1]) c[++cnt]=i;
		memset(bo2,false,sizeof(bo2));
		tt=0;
		for (int i=1;i+2<=cnt;i++) if (i%4==1||i%4==2) h[++tt]=pii(c[i],c[i+2]);
		gao();
		for (int i=1;i<=tt;i++) bo2[h[i].first]=(s[i]=='1');
		tt=0;
		for (int i=1;i+2<=cnt;i++) if (i%4==3||i%4==0) h[++tt]=pii(c[i],c[i+2]);
		gao();
		for (int i=1;i<=tt;i++) bo2[h[i].first]=(s[i]=='1');
		c[cnt+1]=n+1;
		for (int i=1;i<=cnt;i++) for (int j=c[i];j<c[i+1];j++) from[j]=i;
		num[1]=0;num[2]=1;
		for (int i=3;i<=cnt;i++)
		{
			if (bo2[c[i-2]]) num[i]=num[i-2];
			else
			{
				now[0]=now[1]=now[2]=0;
				now[num[i-2]]=1;now[num[i-1]]=1;
				for (int j=0;j<3;j++) if (!now[j]) num[i]=j;
			}
		}
		int t1=0,t2=0,t3=0;
		for (int i=1;i<=n;i++)
		{
			if (num[from[i]]==0) t1++;
			else if (num[from[i]]==1) t2++;
			else t3++;
		}
		printf("A %d %d %d\n",t1,t2,t3);
		for (int i=1;i<=n;i++) if (num[from[i]]==0) print(i);putchar('\n');
		for (int i=1;i<=n;i++) if (num[from[i]]==1) print(i);putchar('\n');
		for (int i=1;i<=n;i++) if (num[from[i]]==2) print(i);putchar('\n');
		fflush(stdout);
	}
	return 0;
}