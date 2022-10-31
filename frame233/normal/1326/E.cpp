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

const int N=600005;
struct node{
	int cnt1,cnt2,ans;
	Finline node operator + (const node &o)const
	{
		int tmp=min(cnt1,o.cnt2);
		return (node){cnt1+o.cnt1-tmp,cnt2+o.cnt2-tmp,ans+o.ans+tmp};
	}
};
struct seg_tr{
	struct Node{
		int ls,rs;
		node val;
	}f[N<<1];
	int node_cnt;
	Finline void PushUp(int x)
	{
		f[x].val=f[f[x].ls].val+f[f[x].rs].val;
	}
	int build(int l,int r)
	{
		int cur=++node_cnt;
		if(l==r) return cur;
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		return cur;
	}
	void Update(int pos,int l,int r,int cur,int opt)
	{
		if(l==r)
		{
			f[cur].val=(node){opt,!opt,0};
			return;
		}
		int mid=(l+r)>>1;
		if(pos<=mid) Update(pos,l,mid,f[cur].ls,opt);
		else Update(pos,mid+1,r,f[cur].rs,opt);
		PushUp(cur);
	}
	Finline int Query(){return f[1].val.ans;}
}tr;
int a[N];
int id[N];
int main()
{
	int n;
	read(n);
	int lim=n<<1|1;
	for(int i=1;i<=n;++i) read(a[i]),id[a[i]]=i;
	tr.build(1,lim);
	int ans=n,x;
	tr.Update(id[ans]<<1,1,lim,1,1);
	for(int i=1;i<=n;++i)
	{
		printf("%d ",ans);
		read(x);
		tr.Update(x<<1|1,1,lim,1,0);
		while(tr.Query()==n-ans+1)
		{
			--ans;
			if(ans) tr.Update(id[ans]<<1,1,lim,1,1);
		}
	}
	printf("\n");
	return 0;
}