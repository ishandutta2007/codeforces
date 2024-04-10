// Author -- Frame

#include<cstdio>
#include<cstring>
#include<algorithm>

#define Finline __inline__ __attribute__ ((always_inline))

typedef long long ll;

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
	register int pos(0);
	s[pos]=ch,ch=getchar();
	while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) s[++pos]=ch,ch=getchar();
	return pos+1;
}

const int N=100005;
struct query{
	int l,r,block,id;
	Finline bool operator < (const query &b)const{return block==b.block?(block&1)?r>b.r:r<b.r:block<b.block;}
}q[N];
int cnt[N<<5],a[N],Xor[N];
ll ans[N],res;
int k;
Finline void del(int x)
{
	--cnt[Xor[x]];
	res-=cnt[Xor[x]^k];
}
Finline void add(int x)
{
	res+=cnt[Xor[x]^k];
	++cnt[Xor[x]];
}
int main()
{
	int n,m;
	read(n,m,k);
	const int block=n/__builtin_sqrt(m)+1;
	for(int i=1;i<=n;++i)
	{
		read(a[i]);
		Xor[i]=Xor[i-1]^a[i];
	}
	for(int i=1;i<=m;++i)
	{
		read(q[i].l,q[i].r);
		--q[i].l;
		q[i].block=q[i].l/block;
		q[i].id=i;
	}
	std::sort(q+1,q+m+1);
	int l=0,r=-1;
	for(int i=1;i<=m;++i)
	{
		while(r<q[i].r) add(++r);
		while(r>q[i].r) del(r--);
		while(l<q[i].l) del(l++);
		while(l>q[i].l) add(--l);
		ans[q[i].id]=res;
	}
	for(int i=1;i<=m;++i) printf("%lld\n",ans[i]);
	return 0;
}