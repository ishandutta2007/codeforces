#include<bits/stdc++.h>
using namespace std;
#define ldb long double
#define inf 1e100
#define eps (1e-10)

struct node { ldb c;int v; }a[110];

ldb f[110][1010];
ldb bin[110],c,t;
int T,n;

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
	if (!x) { putchar('0');putchar('\n');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar('\n');
}

inline bool cmp(const node &x,const node &y) { return x.c>y.c; }

int main()
{
	bin[0]=1;
	for (int i=1;i<=100;i++) bin[i]=bin[i-1]*10/9;
	T=rd();
	while (T--)
	{
		n=rd();
		scanf("%Lf%Lf",&c,&t);
		for (int i=1;i<=n;i++) scanf("%Lf%d",&a[i].c,&a[i].v);
		sort(a+1,a+n+1,cmp);
		int tt=0;
		for (int i=1;i<=n;i++) tt+=a[i].v;
		for (int i=0;i<=n;i++) for (int j=0;j<=tt;j++) f[i][j]=inf;
		f[0][0]=0;
		for (int i=1;i<=n;i++) for (int j=n;j;j--) for (int k=a[i].v;k<=tt;k++) f[j][k]=min(f[j][k],f[j-1][k-a[i].v]+a[i].c*bin[j]);
		int ans=0;
		for (int i=tt;i;i--) for (int j=0;j<=n;j++)
		{
			if (ans>i) break;
			ldb sum=f[j][i];
			if (sum>=inf) continue;
			ldb l=0,r=t;
			while (r-l>eps)
			{
				ldb h1=(l+l+r)/3,h2=(l+r+r)/3;
				if (sum/(1+c*h1)+h1<sum/(1+c*h2)+h2) r=h2;
				else l=h1;
			}
			if (sum/(1+c*l)+l<=t-j*10) ans=i;
		}
		print(ans);
	}
	return 0;
}