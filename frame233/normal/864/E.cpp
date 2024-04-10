// Author -- Frame

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

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
template <typename _Tp,typename... Args>Finline void read(_Tp& t,Args&... args)
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

const int N=105;
struct node{
	int t,d,p,id;
	Finline bool operator < (const node &o)const{return d<o.d;}
}a[N];
int pos,f[N][2005];
int opt[N][2005];
std::vector<int> v;
void print(int x,int y)
{
	if(x)
	{
		print(x-1,opt[x][y]);
		if(y!=opt[x][y])
		{
			v.push_back(x);
		}
	}
}
int main()
{
	int n,x,y,z;
	read(n);
	for(int i=1;i<=n;++i)
	{
		read(x,y,z);
		if(x<y)
		{
			a[++pos]=(node){x,y,z,i};
		}
	}
	n=pos;
	std::sort(a+1,a+pos+1);
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<=2000;++j)
		{
			f[i][j]=f[i-1][j];
			opt[i][j]=j;
			if(j>=a[i].t&&a[i].d>j)
			{
				if(f[i-1][j-a[i].t]+a[i].p>f[i][j])
				{
					f[i][j]=f[i-1][j-a[i].t]+a[i].p;
					opt[i][j]=j-a[i].t;
				}
			}
		}
	}
	int ans=-1,pos=0;
	for(int i=0;i<=2000;++i)
	{
		if(ans<f[n][i])
		{
			ans=f[n][i];
			pos=i;
		}
	}
	printf("%d\n",ans);
	print(n,pos);
	printf("%u\n",v.size());
	for(auto it:v)
	{
		printf("%d ",a[it].id);
	}
	printf("\n");
	return 0;
}