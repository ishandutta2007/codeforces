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

const int N=2005,mod=1000000007;
int f[N][N];
int a[N],len,d,m;
char s1[N],s2[N];
Finline void add(int &a,const int &b){(a+=b)>=mod&&(a-=mod);}
int dfs(const int &pos,const int &mod_m,const bool &limit)
{
	if(pos>len) return !mod_m;
	if(!limit&&~f[pos][mod_m]) return f[pos][mod_m];
	int maxx=limit?a[pos]:9,x=0;
	if(pos&1)
	{
		for(int i=0;i<=maxx;++i)
		{
			if(i!=d)
			{
				add(x,dfs(pos+1,(mod_m*10+i)%m,limit&&i==maxx));
			}
		}
	}
	else
	{
		if(d>maxx)
		{
			x=0;
		}
		else
		{
			x=dfs(pos+1,(mod_m*10+d)%m,limit&&d==maxx);
		}
	}
	if(!limit) f[pos][mod_m]=x;
	return x;
}
int solve(char *s,int L)
{
	memset(f,255,sizeof(f));
	len=L;
	for(int i=1;i<=len;++i) a[i]=s[i]-48;
	int ans=0;
	for(int i=1;i<=a[1];++i)
	{
		if(i!=d)
		{
			add(ans,dfs(2,i%m,i==a[1]));
		}
	}
	return ans;
}
bool check(char *s,int L)
{
	for(int i=2;i<=L;i+=2)
	{
		if(s[i]!=d+48)
		{
			return 0;
		}
	}
	for(int i=1;i<=L;i+=2)
	{
		if(s[i]==d+48)
		{
			return 0;
		}
	}
	int x=0;
	for(int i=1;i<=L;++i)
	{
		x=(x*10+s[i]-48)%m;
	}
	return !x;
}
int main()
{
	read(m,d);
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	printf("%d\n",(solve(s2,strlen(s2+1))-solve(s1,strlen(s1+1))+check(s1,strlen(s1+1))+mod)%mod);
	return 0;
}