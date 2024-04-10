// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<queue>

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

const int N=(1<<21)+5;
int a[N];
bool tag[N];
struct heap{
	std::priority_queue<int> q1,q2;
	Finline void push(int o)
	{
		q1.push(o);
	}
	Finline void pop(int o)
	{
		q2.push(o);
	}
	Finline int top()
	{
		while(!q1.empty()&&!q2.empty()&&q1.top()==q2.top()) q1.pop(),q2.pop();
		return q1.top();
	}
	Finline void clear()
	{
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
	}
}q;
int g;
int nd;
int id[N];
void del(int i)
{
	int l=i<<1;
	int r=i<<1|1;
	if(!a[l]&&!a[r])
	{
		a[i]=0;
		tag[i]=false;
		nd=i;
	}
	else
	{
		bool last;
		if(a[l]>a[r])
		{
			a[i]=a[l];
			last=tag[l];
			del(l);
		}
		else
		{
			a[i]=a[r];
			last=tag[r];
			del(r);
		}
		if(!a[i<<1]&&!a[i<<1|1])
		{
			tag[i]=i>=(1<<g);
		}
		else
		{
			tag[i]=tag[a[i<<1]>a[i<<1|1]?(i<<1):(i<<1|1)];
		}
		if(last&&!tag[i]) q.pop(a[i]);
		id[a[i]]=i;
	}
}
void MAIN()
{
	q.clear();
	int h;
	read(h,g);
	memset(a,0,(1<<h)<<3);
	memset(tag,0,(1<<h)<<1);
	ll sum=0;
	for(int i=1;i<1<<h;++i) read(a[i]),sum+=a[i];
	int n=(1<<h)-1;
	for(int i=1;i<=n;++i)
	{
		tag[i]=true;
		q.push(a[i]);
		id[a[i]]=i;
	}
	std::vector<int> v;
	for(int T=1,lim=(1<<h)-(1<<g);T<=lim;++T)
	{
		int x=q.top();
		q.pop(x);
		v.push_back(id[x]);
		del(id[x]);
		int i=id[x]>>1;
		while(i)
		{
			if(tag[i])
			{
				if(!a[i<<1]&&!a[i<<1|1])
				{
					tag[i]=i>=(1<<g);
				}
				else
				{
					tag[i]=tag[a[i<<1]>a[i<<1|1]?(i<<1):(i<<1|1)];
				}
				if(!tag[i])
				{
					q.pop(a[i]);
				}
			}
			i>>=1;
		}
		sum-=x;
		id[x]=0;
	}
	printf("%lld\n",sum);
	for(auto it:v) printf("%d ",it);
	printf("\n");
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
	return 0;
}