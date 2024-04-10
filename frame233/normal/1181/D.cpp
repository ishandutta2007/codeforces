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

const int N=500005;
struct node{
	int id;
	ll a;
	Finline bool operator < (const node &o)const{return a==o.a?id<o.id:a<o.a;}
	Finline bool operator < (const ll &o)const{return a<o;}
}A[N];
int a[N],root[N];
struct Chair_tr{
    struct node{
        int ls,rs,sum;
    }f[N<<5];
    int node_cnt;
    int build(int l,int r)
    {
        int cur=++node_cnt;
        if(l==r) return cur;
        int mid=(l+r)>>1;
        f[cur].ls=build(l,mid),f[cur].rs=build(mid+1,r);
        return cur;
    }
    int Update(const int &pos,const int &l,const int &r,const int &rt)
    {
        int cur=++node_cnt;
        f[cur]=f[rt];
        ++f[cur].sum;
        if(l==r) return cur;
        int mid=(l+r)>>1;
        if(pos<=mid) f[cur].ls=Update(pos,l,mid,f[cur].ls);
        else f[cur].rs=Update(pos,mid+1,r,f[cur].rs);
        return cur;
    }
    int Query(const int &l,const int &r,const int &u,const int &v,const int &k)
    {
        if(l==r) return l;
        int mid=(l+r)>>1,cur=f[f[v].ls].sum-f[f[u].ls].sum;
        if(k<=cur) return Query(l,mid,f[u].ls,f[v].ls,k);
        else return Query(mid+1,r,f[u].rs,f[v].rs,k-cur);
    }
}tr;
ll minn,sum[N];
int n,m;
ll calc(ll tim)
{
	int pos=std::lower_bound(A+1,A+m+1,tim)-A;
	--pos;
	return tim*(ll)pos-sum[pos];
}
bool check(ll x,ll tim)
{
	ll need=calc(tim);
	return x>need;
}
int solve(ll x)
{
	if(check(x,n))
	{
		ll rest=x-calc(n);
		return (rest-1)%m+1;
	}
	else
	{
		ll l=minn,r=n;
		while(l<r)
		{
			ll mid=(l+r+1)>>1;
			if(check(x,mid)) l=mid;
			else r=mid-1;
		}
		ll rest=x-calc(l);
		return tr.Query(1,m,root[0],root[std::lower_bound(A+1,A+m+1,l+1)-A-1],rest);
	}
}
int main()
{
	int q;
	ll x;
	read(n,m,q);
	for(int i=1;i<=m;++i)
	{
		A[i].id=i;
	}
	for(int i=1;i<=n;++i)
	{
		read(x);
		++A[x].a;
	}
	std::sort(A+1,A+m+1);
	minn=A[1].a;
	root[0]=tr.build(1,m);
	for(int i=1;i<=m;++i)
	{
		sum[i]=sum[i-1]+A[i].a;
		a[i]=A[i].id;
		root[i]=tr.Update(a[i],1,m,root[i-1]);
	}
	for(int i=1;i<=q;++i)
	{
		read(x);
		printf("%d\n",solve(x-n));
	}
	return 0;
}