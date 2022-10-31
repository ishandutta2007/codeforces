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
typedef std::pair<ll,ll> pl;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;

Finline uint rnd()
{
	static uint seed=0x05ad13b4;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
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

const int N=50005;
int mod;
struct matrix{
	ll a,b,c,d;
	Finline void print()
	{
		printf("%lld %lld\n%lld %lld\n\n",a,b,c,d);
	}
	Finline matrix operator * (const matrix &o)const
	{
		return (matrix){(a*o.a+b*o.c)%mod,(a*o.b+b*o.d)%mod,(c*o.a+d*o.c)%mod,(c*o.b+d*o.d)%mod};
	}
};
ll s[N];
int n;
struct seg_tr{
	struct Node{
		int ls,rs;
		matrix mul;
	}f[N<<1];
	int node_cnt;
	Finline void PushUp(int x)
	{
		f[x].mul=f[f[x].ls].mul*f[f[x].rs].mul;
	}
	int build(int l,int r)
	{
		int cur=++node_cnt;
		if(l==r)
		{
			f[cur].mul=(matrix){s[l],1LL,s[l-1],0LL};
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		PushUp(cur);
		return cur;
	}
	void Update(int pos,int k,ll val,int l=1,int r=n,int cur=1)
	{
		if(l==r)
		{
			*(&f[cur].mul.a+k)=val;
			return;
		}
		int mid=(l+r)>>1;
		if(pos<=mid) Update(pos,k,val,l,mid,f[cur].ls);
		else Update(pos,k,val,mid+1,r,f[cur].rs);
		PushUp(cur);
	}
	matrix Query(int L,int R,int l=1,int r=n,int cur=1)
	{
		if(L<=l&&r<=R) return f[cur].mul;
		int mid=(l+r)>>1;
		if(L<=mid&&R>mid) return Query(L,R,l,mid,f[cur].ls)*Query(L,R,mid+1,r,f[cur].rs);
		if(L<=mid) return Query(L,R,l,mid,f[cur].ls);
		return Query(L,R,mid+1,r,f[cur].rs);
	}
}tr;
struct Upd{
	ll id,val;
	int type;
	Finline bool operator < (const Upd &o)const
	{
		return id<o.id;
	}
}Q[N<<1];
int pos;
matrix ksm(matrix a,ll b)
{
	matrix res=(matrix){1LL,0LL,0LL,1LL};
	while(b)
	{
		if(b&1) res=res*a;
		a=a*a,b>>=1;
	}
	return res;
}
int main()
{
	ll k;
	read(k,mod);
	if(mod==1)
	{
	    printf("0\n");
	    return 0;
	}
	if(k==0)
	{
		printf("0\n");
		return 0;
	}
	if(k==1)
	{
		printf("1\n");
		return 0;
	}
	read(n);
	for(int i=0;i<n;++i) read(s[i]);
	s[n]=s[0];
	tr.build(1,n);
	int m;
	read(m);
	ll x,y;
	--k;
	bool flag=false;
	for(int i=1;i<=m;++i)
	{
		read(x,y);
		Q[++pos]=(Upd){x,y,0};
		Q[++pos]=(Upd){x+1,y,2};
		flag|=x==k;
		flag|=(x+1)==k;
	}
	matrix qwq=tr.Query(1,n);
	if(!flag) Q[++pos]=(Upd){k,s[k%n],0};
	std::sort(Q+1,Q+pos+1);
	auto get=[&](ll x)->ll{return (x-1)/n;};
	ll last=-1;
	matrix ans=(matrix){1LL,0LL,0LL,1LL};
	for(int i=1;i<=pos;++i)
	{
		ans=ans*ksm(qwq,get(Q[i].id)-last-1);
		int j=i;
		while(j<pos&&get(Q[i].id)==get(Q[j+1].id)) ++j;
		for(int t=i;t<=j;++t)
		{
			int pos=Q[t].id%n==0?n:Q[t].id%n;
			tr.Update(pos,Q[t].type,Q[t].val);
		}
		if(1ll*n*(get(Q[i].id)+1)<k) ans=ans*tr.Query(1,n);
		else
		{
			ans=ans*tr.Query(1,k-n*get(Q[i].id));
			break;
		}
		last=get(Q[i].id);
		for(int t=i;t<=j;++t)
		{
			int pos=Q[t].id%n==0?n:Q[t].id%n;
			tr.Update(pos,Q[t].type,s[pos-(Q[t].type==2)]);
		}
		i=j;
	}
	matrix qaq=(matrix){1LL,0LL,0LL,0LL}*ans;
	printf("%lld\n",qaq.a);
	return 0;
}