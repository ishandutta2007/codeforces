#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100010,p=1000000007;
struct rec {int n,m,id;};
int q,tot,m;
char ss[N];
rec s[N];
int t[N],fact[N],inv[N],ans[N],g[N];
int C(int n,int m) { return 1LL*fact[n]*inv[m]%p*inv[n-m]%p;}
int cmp(rec a,rec b) { return a.m<b.m;}
int main()
{
	scanf("%d",&q);
	scanf("%s",ss);
	m=strlen(ss);
	g[0]=1;
	for (int i=1;i<=100000;i++) g[i]=25LL*g[i-1]%p;
	fact[0]=fact[1]=inv[0]=inv[1]=1;
	for (int i=2;i<=100000;i++) fact[i]=1LL*fact[i-1]*i%p;
	for (int i=2;i<=100000;i++) inv[i]=-1LL*inv[p%i]*(p/i)%p;
	for (int i=2;i<=100000;i++) inv[i]=1LL*inv[i-1]*inv[i]%p;
	while (q--)
	{
		int kd;
		scanf("%d",&kd);
		if (kd==1)
		{
			scanf("%s",ss);
			m=strlen(ss);
		}
		if (kd==2)
		{
			int x;
			scanf("%d",&x);
			tot++;
			s[tot]=(rec){x,m,tot};
		}
	}
	sort(s+1,s+1+tot,cmp);
	for (int i=1;i<=tot;i++)
	{
		if (s[i].m!=s[i-1].m)
		{
			for (int j=0;j<s[i].m;j++) ans[j]=0;
			ans[s[i].m]=1;
			for (int j=s[i].m+1;j<=100000;j++) ans[j]=(26LL*ans[j-1]+1LL*C(j-1,j-s[i].m)*g[j-s[i].m])%p;
		}
		t[s[i].id]=(ans[s[i].n]+p)%p;
	}
	for (int i=1;i<=tot;i++)
	printf("%d\n",t[i]);
	return 0;
}