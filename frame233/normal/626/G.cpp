// Author -- Frame

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-x))
#define Finline __inline__ __attribute__ ((always_inline))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<int,int> pl;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>Finline void read(_Tp &x)
{
	char ch(getchar());
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
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=200005;
template<typename _Tp>
class heap{
private:
	std::priority_queue<_Tp> q1,q2;
	int siz;
public:
	Finline bool empty(){return !siz;}
	Finline int size(){return siz;}
	Finline void push(const _Tp &o){q1.push(o);++siz;}
	Finline void pop(const _Tp &o){q2.push(o);--siz;}
	Finline _Tp top()
	{
		while(!q2.empty()&&q1.top()==q2.top()) q1.pop(),q2.pop();
		return q1.top();
	}
};
struct node{
	double val;
	int id;
	Finline bool operator < (const node &o)const
	{
		return val==o.val?id<o.id:val<o.val;
	}
	Finline bool operator == (const node &o)const
	{
		return val==o.val&&id==o.id;
	}
};
heap<node> q1;
heap<node> q2;
int p[N],l[N];
int cnt[N];
Finline double calc(int x,int k)
{
	if(k<0) return -1e9;
	chmin(k,l[x]);
	return (double)p[x]*k/(l[x]+k);
}
Finline double calc1(int x)
{
	return calc(x,cnt[x]+1)-calc(x,cnt[x]);
}
Finline double calc2(int x)
{
	return calc(x,cnt[x]-1)-calc(x,cnt[x]);
}
Finline void del(int x)
{
	q1.pop((node){calc1(x),x});
	q2.pop((node){calc2(x),x});
}
Finline void add(int x)
{
	q1.push((node){calc1(x),x});
	q2.push((node){calc2(x),x});
}
Finline void Upd(int x,int opt)
{
	del(x);
	cnt[x]+=opt;
	add(x);
}
int main()
{
	int n,t,_;
	read(n,t,_);
	for(int i=1;i<=n;++i) read(p[i]);
	for(int i=1;i<=n;++i)
	{
		read(l[i]);
		add(i);
	}
	int T=t;
	while(T)
	{
		--T;
		node x=q1.top();
		Upd(x.id,1);
	}
	double ans=0;
	for(int i=1;i<=n;++i) ans+=calc(i,cnt[i]);
	int opt,x;
	while(_--)
	{
		read(opt,x);
		ans-=calc(x,cnt[x]);
		del(x);
		if(opt==1) ++l[x];
		else --l[x];
		add(x);
		ans+=calc(x,cnt[x]);
		while(q1.top().val+q2.top().val>0)
		{
			node x=q1.top(),y=q2.top();
			ans+=x.val+y.val;
			Upd(x.id,1);
			Upd(y.id,-1);
		}
		printf("%.12lf\n",ans);
	}
	return 0;
}