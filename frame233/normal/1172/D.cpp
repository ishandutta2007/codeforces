// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-10;

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline bool _cmp(const _Tp &a,const _Tp &b){return abs(a-b)<=eps;}
template <typename _Tp>Finline void read(_Tp &x)
{
	register char ch(getchar());
	bool f(false);
	while(ch<48||ch>57) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();
	while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args)
{
	read(t);read(args...);
}
Finline int read_str(char *s)
{
	register char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	register char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=1005;
int a[N],b[N];
int p1[N],p2[N];
struct node{
	int x1,y1,x2,y2;
};
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i) read(a[i]),p1[a[i]]=i;
	for(int i=1;i<=n;++i) read(b[i]),p2[b[i]]=i;
	std::vector<node> ans;
	for(int i=1;i<n;++i)
	{
		int x=p1[i];
		int y=p2[i];
		if(x==y&&x==i) continue;
		if(x!=n) ans.push_back((node){x,i,i,n});
		if(y!=n) ans.push_back((node){i,y,n,i});
		if(x==n&&y==n) ans.push_back((node){i,n,n,i});
		if((x==n)+(y==n)==1)
		{
			if(x==n)
			{
				a[n]=a[i];
				p1[a[n]]=n;
				b[y]=b[i];
				p2[b[y]]=y;
			}
			else
			{
				b[n]=b[i];
				p2[b[n]]=n;
				a[x]=a[i];
				p1[a[x]]=x;
			}
			continue;
		}
		a[x]=a[n];
		b[y]=b[n];
		p1[a[x]]=x;	
		p2[b[y]]=y;
		a[n]=a[i];
		b[n]=b[i];
		p1[a[n]]=n;
		p2[b[n]]=n;
	}
	printf("%d\n",(int)ans.size());
	for(auto it:ans) printf("%d %d %d %d\n",it.x1,it.y1,it.x2,it.y2);
	return 0;
}