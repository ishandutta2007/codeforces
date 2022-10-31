// Author -- Frame
 
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
 
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
 
const int N=100005;
const int S=350;
ll a[N],b[N];
int L[N],R[N],bel[N];
int block_cnt;
struct Block{
	int _q[S+5],_l,_r;
	ll tag1,tag2;
	// tag1 for k
	// tag2 for b
}f[S+5];
int to[N],rev[N];
bool used[N];
Finline ll X(int x){return a[x];}
Finline ll Y(int x){return b[x]+f[bel[x]].tag2;}
Finline double Slope(int pos1,int pos2)
{
	if(X(pos2)==X(pos1)) return Y(pos2)>Y(pos1)?inf:-inf;
	return (double)(Y(pos2)-Y(pos1))/(X(pos2)-X(pos1));
}
int t[N];
void build(int n)
{
	int cur=0,tmp=S;
	for(int i=1;i<=n;++i)
	{
		++tmp;
		if(tmp>S)
		{
			R[cur]=i-1;
			++cur;
			tmp=1;
			L[cur]=i;
		}
		bel[i]=cur;
	}
	R[cur]=n;
	block_cnt=cur;
	for(cur=1;cur<=block_cnt;++cur)
	{
		int len=0;
		for(int i=L[cur];i<=R[cur];++i) t[++len]=i;
		std::sort(t+1,t+len+1,[](const int &A,const int &B)->bool{return a[A]<a[B];});
		for(int i=1;i<=len;++i)
		{
			to[t[i]]=i+L[cur]-1;
			rev[i+L[cur]-1]=t[i];
			b[i+L[cur]-1]=a[t[i]];
		}
		std::sort(a+L[cur],a+R[cur]+1);
		int &_l=f[cur]._l;
		int &_r=f[cur]._r;
		int *_q=f[cur]._q;
		_l=1,_r=0;
		for(int i=L[cur];i<=R[cur];++i)
		{
			if(i>L[cur]&&a[i]==a[i-1]) continue;
			while(_l<_r&&Slope(_q[_r-1],_q[_r])<=Slope(_q[_r],i)) --_r;
			_q[++_r]=i;
		}
	}
}
void Update_b(int B,int C)
{
	for(int i=1;i<=B;++i)
	{
		f[i].tag2+=C;
	}
}
void Update_k(int B)
{
	for(int i=B;i<=block_cnt;++i)
	{
		++f[i].tag1;
	}
}
void Update(int pos,int C)
{
	int cur=bel[pos];
	Update_b(cur-1,C);
	Update_k(cur+1);
	used[to[pos]]=true;
	for(int i=L[cur];i<=R[cur];++i)
	{
		b[i]+=f[cur].tag2;
	}
	f[cur].tag2=0;
	for(int i=L[cur];i<pos;++i)
	{
		b[to[i]]+=C;
	}
	for(int i=pos+1;i<=R[cur];++i)
	{
		b[to[i]]+=a[to[i]];
	}
	int &_l=f[cur]._l;
	int &_r=f[cur]._r;
	int *_q=f[cur]._q;
	_l=1,_r=0;
	for(int i=L[cur];i<=R[cur];++i)
	{
		if(!used[i])
		{
			if(_l<=_r&&X(i)==X(_q[_r])&&Y(i)==Y(_q[_r])) continue;
			while(_l<_r&&Slope(_q[_r-1],_q[_r])<=Slope(_q[_r],i)) --_r;
			if(_l<=_r&&X(i)==X(_q[_r])&&Y(i)==Y(_q[_r])) continue;
			_q[++_r]=i;
		}
	}
}
ll res;
int Query()
{
	ll maxx=-1e18;
	int pos=0;
	for(int i=1;i<=block_cnt;++i)
	{
		int &_l=f[i]._l;
		int &_r=f[i]._r;
		int *_q=f[i]._q;
		while(_l<_r&&Slope(_q[_l],_q[_l+1])>=-f[i].tag1) ++_l;
		if(_l<=_r)
		{
			ll tmp=a[_q[_l]]*f[i].tag1+Y(_q[_l]);
			if(tmp>maxx)
			{
				maxx=tmp;
				pos=_q[_l];
			}
		}
	}
	res=maxx;
	return pos;
}
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i) read(a[i]);
	build(n);
	ll ans=0,tmp=0;
	for(int i=1;i<=n;++i)
	{
		res=-1e18;
		int pos=Query();
		pos=rev[pos];
		tmp+=res;
		if(tmp<-1e18) break;
		chmax(ans,tmp);
		Update(pos,a[to[pos]]);
	}
	printf("%lld\n",ans);
	return 0;
}