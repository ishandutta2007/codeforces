// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define pb push_back

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

const int N=100005;
typedef std::pair<int,int> pi;
pi qry(int x)
{
	printf("+ %d\n",x);
	fflush(stdout);
	int a,b;
	read(a,b);
	return std::make_pair(a,b);
}
std::map<int,int> mp;
pi d[N];
int cnt[N],cur[N];
int main()
{
	for(int i=1;i<=300;++i) mp[i*(i+1)*(i-1)/6-i*(i-1)*(i-2)/6]=i;
	int n;
	read(n);
	pi last;
	read(last.first,last.second);
	for(int i=n-1;i>=3;--i) d[i]=qry(i);
	pi a=qry(1);
	pi b=qry(2);
	pi c=qry(1);
	cnt[1]=mp[c.first-b.first]-1;
	cur[1]=cnt[1]+2;
	cnt[3]=(c.second-b.second)-(a.second-d[3].second)-1;
	cur[3]=cnt[3]+1;
	cnt[2]=(c.second-b.second)/cur[3]-1;
	cur[2]=cnt[2]+1;
	for(int i=4;i<=n-1;++i)
	{
		if(i==4)
		{
			cur[i]=(b.second-a.second-(cnt[1]+1)*cur[3])/cur[3];
		}
		else
		{
			cur[i]=(d[i-2].second-d[i-1].second-cnt[i-4]*cnt[i-3]-cnt[i-3]*cur[i-1])/cur[i-1];
		}
		cnt[i]=cur[i]-1;
	}
	ll tot=c.second;
	for(int i=1;i+2<n;++i) tot-=cur[i]*cur[i+1]*cur[i+2];
	cnt[n]=tot/(cur[n-1]*cur[n-2]);
	printf("! ");
	for(int i=1;i<=n;++i) printf("%d ",cnt[i]);
	printf("\n");
	fflush(stdout);
	return 0;
}