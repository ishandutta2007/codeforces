// Author -- Frame

#include<cstdio>
#include<cstring>
#include<algorithm>

#define Finline __inline__ __attribute__ ((always_inline))

typedef long long ll;

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline void read(_Tp& x)
{
    register char ch(getchar());
    bool f(false);
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp& t, Args&... args)
{
    read(t);read(args...);
}
Finline int read_str(char *s)
{
	register char ch(getchar());
	while(ch<65||ch>122||(ch>90&&ch<97)) ch=getchar();
	register int pos(0);
	s[pos]=ch,ch=getchar();
	while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) s[++pos]=ch,ch=getchar();
	return pos+1;
}

const int N=100005;
int D[N],sum_d[N],a[N];
ll sum[N],f[N],g[N];
int _q[N],_l,_r;
Finline ll X(const int &p){return p;}
Finline ll Y(const int &p){return g[p]+sum[p];}
Finline double Slope(const int &p1,const int &p2)
{
	return (double)(Y(p2)-Y(p1))/(X(p2)-X(p1));
}
int main()
{
	memset(g,63,sizeof(g));
	g[0]=0;
	int n,m,p,x,y;
	read(n,m,p);
	for(int i=2;i<=n;++i)
	{
		read(D[i]);
		sum_d[i]=sum_d[i-1]+D[i];
	}
	for(int i=1;i<=m;++i)
	{
		read(x,y);
		a[i]=y-sum_d[x];
	}
	std::sort(a+1,a+m+1);
	for(int i=1;i<=m;++i)
	{
		sum[i]=sum[i-1]+a[i];
	}
	for(int j=1;j<=p;++j)
	{
		_q[_l=_r=1]=0;
		for(int i=1;i<=m;++i)
		{
			while(_l<_r&&Slope(_q[_l],_q[_l+1])<=a[i]) ++_l;
			int pos=_q[_l];
			f[i]=g[pos]+1ll*a[i]*(i-pos)-sum[i]+sum[pos];
			while(_l<_r&&Slope(_q[_r-1],_q[_r])>=Slope(_q[_r],i)) --_r;
			_q[++_r]=i;
		}
		memcpy(g,f,sizeof(g));
	}
	printf("%lld\n",f[m]);
	return 0;
}
/*
f[i] = g[j] + t[i]*(i-j) - sum[i] + sum[j]
f[i] = g[j] + t[i]*i - t[i]*j - sum[i] + sum[j]
y             = k     x + b
g[j] + sum[j] = t[i]*j + f[i] - t[i]*i + sum[i]
*/