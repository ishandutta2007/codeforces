// Author -- Frame

#include<cstdio>
#include<cstring>
#include<algorithm>
#define IT std::multiset<int>::iterator

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

const int N=1005;
int p[N<<1],q[N<<1];
int a[N],b[N];
bool used[N<<1];
Finline bool cmp(const int &a,const int &b){return p[a]>p[b];}
int main()
{
	int n,m;
	read(n,m);
	for(int i=1;i<=(n<<1);++i) read(p[i]);
	for(int i=1;i<=m;++i)
	{
		read(a[i],b[i]);
		if(p[a[i]]<p[b[i]]) std::swap(a[i],b[i]);
	}
	int t,x,pos=0;
	read(t);
	if(t==1)
	{
		for(int i=1;i<=m;++i)
		{
			printf("%d\n",a[i]);
			fflush(stdout);
			used[a[i]]=1;
			read(x);
			used[x]=1;
		}
		for(int i=1;i<=n<<1;++i)
		{
			if(!used[i])
			{
				q[++pos]=i;
			}
		}
		std::sort(q+1,q+pos+1,cmp);
		int tmp=1,_=pos>>1;
		for(int i=1;i<=_;++i)
		{
			while(used[q[tmp]]) ++tmp;
			printf("%d\n",q[tmp]);
			fflush(stdout);
			used[q[tmp]]=1;
			read(x);
			used[x]=1;
		}
	}
	else
	{
		while(~scanf("%d",&x))
		{
			used[x]=1;
			bool flag=0;
			for(int i=1;i<=m;++i)
			{
				if(a[i]==x)
				{
					flag=1;
					printf("%d\n",b[i]);
					fflush(stdout);
					used[b[i]]=1;
					break;
				}
				if(b[i]==x)
				{
					flag=1;
					printf("%d\n",a[i]);
					fflush(stdout);
					used[a[i]]=1;
					break;
				}
			}
			if(!flag)
			{
				for(int i=1;i<=m;++i)
				{
					if(!used[a[i]]&&!used[b[i]])
					{
						printf("%d\n",a[i]);
						fflush(stdout);
						used[a[i]]=1;
						read(x);
						used[x]=1;
					}
				}
				for(int i=1;i<=n<<1;++i)
				{
					if(!used[i])
					{
						q[++pos]=i;
					}
				}
				std::sort(q+1,q+pos+1,cmp);
				int tmp=1,_=pos>>1;
				for(int i=1;i<=_;++i)
				{
					while(used[q[tmp]]) ++tmp;
					printf("%d\n",q[tmp]);
					fflush(stdout);
					used[q[tmp]]=1;
					read(x);
					used[x]=1;
				}
				for(int i=1;i<=n<<1;++i)
				{
					if(!used[i])
					{
						printf("%d\n",i);
						fflush(stdout);
					}
				}
				return 0;
			}
		}
	}
	return 0;
}
//*//