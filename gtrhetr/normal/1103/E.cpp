#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define mod 288230376151711744LL

struct node
{
	ull a[4];
	node() { memset(a,0,sizeof(a)); }
	inline void init() { memset(a,0,sizeof(a)); }
}f[100010],h[110];

ull g[110];
int n;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void print(ull x)
{
	static char s[233];
	if (!x) { putchar('0');putchar('\n');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putchar(s[tot]);
	putchar('\n');
}

inline node mul(const node &x,const node &y)
{
	static ull c[10];
	memset(c,0,sizeof(c));
	for (int i=0;i<4;i++) for (int j=0;j<4;j++) c[i+j]+=x.a[i]*y.a[j];
	for (int i=6;i>=4;i--) c[i-1]+=c[i],c[i-2]-=c[i],c[i-3]+=c[i],c[i-4]-=c[i];
	node res;memcpy(res.a,c,sizeof(res.a));
	return res;
}

inline node add(const node &x,const node &y)
{
	node res;
	for (int i=0;i<4;i++) res.a[i]=x.a[i]+y.a[i];
	return res;
}

inline node ksm(node x,ull y)
{
	node res;res.a[0]=1;
	for (;y;y>>=1,x=mul(x,x)) if (y&1) res=mul(res,x);
	return res;
}

inline void fwt(node *f,int n,int on)
{
	static node c[10];
	for (int w=1;w<n;w*=10) for (int k=0;k<n;k++)
	{
		if ((k/w)%10!=0) continue;
		for (int j=0;j<10;j++) c[j]=f[k+j*w];
		for (int j=0;j<10;j++)
		{
			int now=k+j*w;f[now].init();
			for (int l=0;l<10;l++) f[now]=add(f[now],mul(c[l],h[j*l*(on+10)%10]));
		}
	}
}

int main()
{
	n=rd();
	for (int i=1;i<=n;i++) f[rd()].a[0]++;
	h[0].a[0]=h[1].a[1]=1;
	for (int i=2;i<10;i++) h[i]=mul(h[i-1],h[1]);
	fwt(f,100000,1);
	for (int i=0;i<100000;i++) f[i]=ksm(f[i],n);
	fwt(f,100000,-1);
	for (int i=0;i<n;i++) print((f[i].a[0]>>5)*6723469279985657373ull%mod);
	return 0;
}