#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct node { int l1,l2,len; }h[200010];

ll hs1[200010],hs2[200010],bin[200010],mod;
int sum[200010],nxt[200010],n,m,tt;
char s[200010];
bool bo[200010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline ll mns(const ll &x,const ll &y) { return (x-y<0)?x-y+mod:x-y; }

inline void print1() { putchar('Y');putchar('e');putchar('s');putchar('\n'); }
inline void print2() { putchar('N');putchar('o');putchar('\n'); }

inline void gao()
{
	bin[0]=1;
	for (int i=1;i<=200000;i++) bin[i]=bin[i-1]*233%mod;
	tt=0;
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+(s[i]=='0');
	for (int i=1;i<=n;i++) if (s[i]=='0')
	{
		tt++;
		if (i&1) hs1[tt]=(hs1[tt-1]*233+1)%mod,hs2[tt]=(hs2[tt-1]*233+2)%mod;
		else hs1[tt]=(hs1[tt-1]*233+2)%mod,hs2[tt]=(hs2[tt-1]*233+1)%mod;
	}
	nxt[n+1]=n+1;
	for (int i=n;i;i--) nxt[i]=(s[i]=='0')?i:nxt[i+1];
	for (int i=1;i<=m;i++)
	{
		int x1=h[i].l1,y1=h[i].l1+h[i].len-1,x2=h[i].l2,y2=h[i].l2+h[i].len-1;
		if (sum[y1]-sum[x1-1]!=sum[y2]-sum[x2-1]) { bo[i]=true;continue; }
		if (sum[y1]==sum[x1-1]) continue;
		int h1=(x1)&1,h2=(x2)&1,hh=sum[y1]-sum[x1-1];
		if (h1==h2)
		{
			if (mns(hs1[sum[y1]],hs1[sum[x1-1]]*bin[hh]%mod)!=mns(hs1[sum[y2]],hs1[sum[x2-1]]*bin[hh]%mod)) bo[i]=true;
		}
		else
		{
			if (mns(hs1[sum[y1]],hs1[sum[x1-1]]*bin[hh]%mod)!=mns(hs2[sum[y2]],hs2[sum[x2-1]]*bin[hh]%mod)) bo[i]=true;
		}
	}
}

int main()
{
	n=rd();
	scanf("%s",s+1);
	m=rd();
	for (int i=1;i<=m;i++) h[i].l1=rd(),h[i].l2=rd(),h[i].len=rd();
	mod=1000000007;gao();
	mod=998244353;gao();
	for (int i=1;i<=m;i++) if (!bo[i]) print1();else print2();
	return 0;
}