// Author -- Frame

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

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

const int N=200005;
struct node{
	int x,num;
	Finline bool operator < (const node &o)const{return x==o.x?num>o.num:x>o.x;}
}a[N];
bool used[N];
int main()
{
	int _;
	read(_);
	while(_--)
	{
		std::priority_queue<int> q;
		int n,x,y;
		read(n);
		memset(a,0,8*(n+3));
		memset(used,0,n+3);
		for(int i=1;i<=n;++i)
		{
			read(x,y);
			++a[x].x;
			a[x].num+=y;
		}
		std::sort(a+1,a+n+1);
		int ans=0,res=0,tmp=inf;
		for(int i=1;i<=n;++i)
		{
			if(tmp<=1) break;
			--tmp;
			if(tmp>=a[i].x) tmp=a[i].x;
			if(!used[i]) q.push(a[i].num),used[i]=1;
			int j=i;
			while(a[j+1].x>=tmp&&j<n)
			{
				++j;
				if(!used[j])
				{
					q.push(a[j].num);
					used[j]=1;
				}
			}
			ans+=tmp;
			res+=min(tmp,q.top());
			q.pop();
		}
		printf("%d %d\n",ans,res);
	}
	return 0;
}