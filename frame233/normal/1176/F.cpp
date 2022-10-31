// Author -- Frame

#include<cstdio>
#include<cstring>
#include<algorithm>

#define Finline __inline__ __attribute__ ((always_inline))

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7ffffffffffffff;

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
    register char *tar=s;
    *tar=ch,ch=getchar();
    while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) *(++tar)=ch,ch=getchar();
    return tar-s+1;
}

const int N=200005;
std::vector<int> v[4];
int a1[4],a2,a3;
ll f[N][10];
Finline bool cmp(const int &a,const int &b){return a>b;}
int main()
{
	int n,k;
	read(n);
	memset(f[0],-63,sizeof(f[0]));
	f[0][0]=0;
	for(int turn=1;turn<=n;++turn)
	{
		memcpy(f[turn],f[turn-1],sizeof(f[turn]));
		v[1].clear();
		v[2].clear();
		v[3].clear();
		read(k);
		int c,w;
		for(int i=1;i<=k;++i)
		{
			read(c,w);
			v[c].push_back(w);
		}
		for(int i=1;i<=3;++i) std::sort(v[i].begin(),v[i].end(),cmp);
		int pos1=0;
		a2=a3=-1;
		for(int i=1;i<=3;++i)
		{
			if(v[1].size()>=i)
			{
				a1[++pos1]=v[1][i-1];
			}
		}
		if(!v[2].empty())
		{
			a2=*v[2].begin();
		}
		if(!v[3].empty())
		{
			a3=*v[3].begin();
		}
		for(int i=0;i<10;++i)
		{
			if(pos1) chmax(f[turn][(i+1)%10],f[turn-1][i]+a1[1]+(i==9?a1[1]:0));
			if(~a2) chmax(f[turn][(i+1)%10],f[turn-1][i]+a2+(i==9?a2:0));
			if(~a3) chmax(f[turn][(i+1)%10],f[turn-1][i]+a3+(i==9?a3:0));
			if(pos1>=2)
			{
				chmax(f[turn][(i+2)%10],f[turn-1][i]+a1[1]+a1[2]+(i>=8?a1[1]:0));
			}
			if(pos1==3)
			{
				chmax(f[turn][(i+3)%10],f[turn-1][i]+a1[1]+a1[2]+a1[3]+(i>=7?a1[1]:0));
			}
			if(~a2&&pos1>=1)
			{
				chmax(f[turn][(i+2)%10],f[turn-1][i]+a1[1]+a2+(i>=8?max(a2,a1[1]):0));
			}
		}
	}
	ll ans=0;
	for(int i=0;i<10;++i) chmax(ans,f[n][i]);
	printf("%lld\n",ans);
    return 0;
}