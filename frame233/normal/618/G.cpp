// Author -- xyr2005

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>inline void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=52;
struct mat{
	double a[N][N];
	mat(){memset(a,0,sizeof(a));}
	mat operator * (const mat &o)const
	{
		mat c;for(int i=1;i<N;++i) for(int k=1;k<N;++k) for(int j=1;j<N;++j) c.a[i][j]+=a[i][k]*o.a[k][j];
		return c;
	}
}M,orig;
double a[N][N],b[N][N],f[N][N],A[N][N],B[N][N];
mat ksm(mat a,int b)
{
	mat res;for(int i=1;i<N;++i) res.a[i][i]=1;
	while(b)
	{
		if(b&1) res=res*a;
		a=a*a,b>>=1;
	}
	return res;
}
int main()
{
	int n,_p;read(n,_p);
	double p=_p/1e9;
	for(int i=1;i<=50;++i)
	{
		a[i][1]=p,a[i][2]=1-p+(i>1?p*p:0),b[i][1]=0,b[i][2]=1-p;
		for(int j=3;j<=50;++j) a[i][j]=a[i][j-1]*a[i-1][j-1],b[i][j]=b[i][j-1]*a[i-1][j-1];
	}
	for(int i=1;i<=50;++i) for(int j=1;j<=50;++j) A[i][j]=a[i][j]*(1.0-a[i-1][j]),B[i][j]=b[i][j]*(1.0-a[i-1][j]);
	f[1][1]=1,f[1][2]=2;
	for(int i=2;i<=50;++i)
	{
		for(int k=2;k<=50;++k) f[i][1]+=f[i-1][k]*B[i-1][k];
		f[i][1]=f[i][1]/std::accumulate(B[i-1]+2,B[i-1]+51,0.0)+1.0;
		for(int j=2;j<=50;++j)
		{
			for(int k=1;k<j;++k) f[i][j]+=f[i-1][k]*A[i-1][k];
			f[i][j]=f[i][j]/std::accumulate(A[i-1]+1,A[i-1]+j,0.0)+j;
		}
	}
	if(n<=50)
	{
		double ans=0;for(int i=1;i<=50;++i)ans+=f[n][i]*A[n][i];
		printf("%.12lf\n",ans);
	}
	else
	{
		double sum=A[50][1];
		for(int i=2;i<=50;++i)
		{
			for(int j=1;j<i;++j) M.a[j][i]=A[50][j]/sum;
			sum+=A[50][i];
		}
		sum=std::accumulate(B[50]+2,B[50]+51,0.0);
		for(int i=2;i<=50;++i) M.a[i][1]=B[50][i]/sum;
		for(int i=1;i<=50;++i) M.a[51][i]=i,orig.a[1][i]=f[50][i];
		orig.a[1][51]=1,M.a[51][51]=1;
		M=orig*ksm(M,n-50);
		double ans=0;for(int i=1;i<=50;++i)ans+=M.a[1][i]*A[50][i];
		printf("%.12lf\n",ans);
	}
	return 0;
}