#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 490019
#define Mod 245009
#define mod1 491
#define mod2 499
#define pow DCXISSOHANDSOME

struct node
{
	double x,y;
	node() {}
	node(double xx,double yy):x(xx),y(yy) {}
}*pow[21],a[1048576],b[1048576];

const double pi=acos(-1.0);

inline node operator +(const node &x,const node &y) { return node(x.x+y.x,x.y+y.y); }
inline node operator -(const node &x,const node &y) { return node(x.x-y.x,x.y-y.y); }
inline node operator *(const node &x,const node &y) { return node(x.x*y.x-x.y*y.y,x.x*y.y+x.y*y.x); }
inline node operator /(const node &x,const double &y) { return node(x.x/y,x.y/y); }

ll f[1048576],sum[500010],sum1[500010],sum2[500010],bin[500010],c;
int num1[100010],num2[100010],id1[510],id2[510],bin1[510],bin2[510],n,m,Inv1,Inv2;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline ll pls(const ll &x,const ll &y) { return (x+y<mod)?x+y:x+y-mod; }
inline ll mns(const ll &x,const ll &y) { return (x-y<0)?x-y+mod:x-y; }
inline ll ksm(ll x,ll y,const ll &p=mod) { ll res=1;for (;y;y>>=1,x=x*x%p) if (y&1) res=res*x%p;return res; }

inline void pre_gao()
{
	for (int w=2,hh=1;w<=1048576;w<<=1,hh++)
	{
		pow[hh]=new node[w>>1];
		for (int j=0;j<(w>>1);j++) pow[hh][j]=node(cos(pi*2*j/w),sin(pi*2*j/w));
	}
	id1[1]=0;int now=1;
	for (int i=1;i<mod1-1;i++) now=now*2%mod1,id1[now]=i;
	id2[1]=0;now=1;
	for (int i=1;i<mod2-1;i++) now=now*7%mod2,id2[now]=i;
	for (int i=1;i<mod1;i++) bin1[id1[i]]=i;
	for (int i=1;i<mod2;i++) bin2[id2[i]]=i;
	Inv1=ksm(mod2%mod1,mod1-2,mod1);
	Inv2=ksm(mod1%mod2,mod2-2,mod2);
}

inline void fft(node *a,int n,int on)
{
	static int rev[1048576];
	for (int i=1;i<n;i++) rev[i]=(rev[i>>1]>>1)|((i&1)?(n>>1):0);
	for (int i=1;i<n;i++) if (i<rev[i]) swap(a[i],a[rev[i]]);
	for (int w=2,hh=1;w<=n;w<<=1,hh++) for (int k=0;k<n;k+=w) for (int j=k;j<k+(w>>1);j++)
	{
		node u=a[j],t=a[j+(w>>1)]*pow[hh][j-k];
		a[j]=u+t;a[j+(w>>1)]=u-t;
	}
	if (on==-1)
	{
		reverse(a+1,a+n);
		for (int i=0;i<n;i++) a[i]=a[i]/n;
	}
}

inline int Calc(int x,int y) { return x*(mod2-1)*2+y; }
inline int calc(int x,int y) { return ((ll)x*mod2*Inv1+(ll)y*mod1*Inv2)%Mod; }

inline void gao(bool flag)
{
	static ll c[1048576],d[1048576];
	static ll h[1048576];
	memset(f,0,sizeof(f));
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	for (int i=0;i<n;i++) if (flag||(i&1)) c[(ll)i*i%Mod]=pls(c[(ll)i*i%Mod],num1[i]);
	for (int j=0;j<m;j++) if (flag||(j&1)) d[(ll)j*j*j%Mod]=pls(d[(ll)j*j*j%Mod],num2[j]);
	int tt=0;
	for (int i=0;i<Mod;i++) if (i%mod1==0||i%mod2==0) h[++tt]=i;
	for (int i=1;i<=tt;i++) for (int j=0,hh=0;j<Mod;j++,hh=(hh+h[i]>=Mod)?hh+h[i]-Mod:hh+h[i]) f[hh]+=c[h[i]]*d[j]+d[h[i]]*c[j];
	for (int i=1;i<=tt;i++) for (int j=1;j<=tt;j++) f[h[i]*h[j]%Mod]-=c[h[i]]*d[h[j]];
	for (int i=0;i<Mod;i++) f[i]%=mod;
	for (int i=0;i<1048576;i++) a[i]=b[i]=node(0,0);
	for (int i=0;i<Mod;i++) if (i%mod1!=0&&i%mod2!=0)
	{
		int hh=Calc(id1[i%mod1],id2[i%mod2]);
		a[hh]=a[hh]+node(c[i],0);
		b[hh]=b[hh]+node(d[i],0);
	}
	fft(a,1048576,1);fft(b,1048576,1);
	for (int i=0;i<1048576;i++) a[i]=a[i]*b[i];
	fft(a,1048576,-1);
	for (int i=0;i<(mod1-1)*(mod2-1)*4;i++)
	{
		int h1=i/((mod2-1)*2),h2=i%((mod2-1)*2);
		int hh=calc(bin1[h1%(mod1-1)],bin2[h2%(mod2-1)]);
		f[hh]=pls(f[hh],(ll)(a[i].x+0.5)%mod);
	}
}

int main()
{
	n=rd();m=rd();c=rd();pre_gao();
	for (int i=0;i<n;i++) num1[i]=rd();
	for (int i=0;i<m;i++) num2[i]=rd();
	bin[0]=1;
	for (int i=1;i<mod;i++) bin[i]=bin[i-1]*c%mod;
	gao(1);
	for (int i=0;i<Mod;i++) sum2[i]=f[i];
	gao(0);
	for (int i=0;i<Mod;i++) sum1[i]=f[i],sum2[i]=mns(sum2[i],f[i]);
	for (int k=0;k<Mod;k++) (k&1)?(sum[k]=pls(sum[k],sum1[k])):(sum[k+Mod]=pls(sum[k+Mod],sum1[k]));
	for (int k=0;k<Mod;k++) (!(k&1))?(sum[k]=pls(sum[k],sum2[k])):(sum[k+Mod]=pls(sum[k+Mod],sum2[k]));
	ll ans=0;
	for (int i=0;i<mod;i++) ans=pls(ans,bin[i]*sum[i]%mod);
	printf("%lld\n",ans);
	return 0;
}