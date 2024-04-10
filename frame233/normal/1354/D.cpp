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
	static uint seed=416;
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

const int N=1000005;
struct seg_tr{
	struct Node{
		int ls,rs;
		int sum;
	}f[N<<1];
	int node_cnt;
	Finline void PushUp(int x)
	{
		f[x].sum=f[f[x].ls].sum+f[f[x].rs].sum;
	}
	int build(int l,int r)
	{
		int cur=++node_cnt;
		if(l==r) return cur;
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		PushUp(cur);
		return cur;
	}
	void Update(int k,int l,int r,int cur)
	{
		if(l==r)
		{
			--f[cur].sum;
			return;
		}
		int mid=(l+r)>>1;
		if(k>f[f[cur].ls].sum) Update(k-f[f[cur].ls].sum,mid+1,r,f[cur].rs);
		else Update(k,l,mid,f[cur].ls);
		PushUp(cur);
	}
	void Modify(int pos,int l,int r,int cur)
	{
		if(l==r)
		{
			++f[cur].sum;
			return;
		}
		int mid=(l+r)>>1;
		if(pos<=mid) Modify(pos,l,mid,f[cur].ls);
		else Modify(pos,mid+1,r,f[cur].rs);
		PushUp(cur);
	}
	void output(int l,int r,int cur)
	{
		if(l==r)
		{
			if(f[cur].sum)
			{
				printf("%d\n",l);
				exit(0);
			}
			return;
		}
		int mid=(l+r)>>1;
		output(l,mid,f[cur].ls);
		output(mid+1,r,f[cur].rs);
	}
}tr;
int main()
{
	int n,q;
	read(n,q);
	tr.build(1,n);
	int x;
	for(int i=1;i<=n;++i) read(x),tr.Modify(x,1,n,1);
	while(q--)
	{
		read(x);
		if(x<0)
		{
			tr.Update(-x,1,n,1);
		}
		else
		{
			tr.Modify(x,1,n,1);
		}
	}
	tr.output(1,n,1);
	printf("0\n");
	return 0;
}