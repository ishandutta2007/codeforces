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
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7fffffffffffffff;
const double eps=1e-10;

uint seed=19260817;
const uint _RAND_MAX_=4294967295u;
Finline uint Rand(){return seed=seed*998244353u+1000000007u;}

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
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

const int N=1000005;
struct matrix1{
	int a,b,c,d;
	Finline matrix1 operator * (const matrix1 &o)const
	{
		return (matrix1){max(-inf,max(a+o.a,b+o.c)),max(-inf,max(a+o.b,b+o.d)),max(-inf,max(c+o.a,d+o.c)),max(-inf,max(c+o.b,d+o.d))};
	}
};
struct matrix2{
	int a,b,c,d;
	Finline matrix2 operator * (const matrix2 &o)const
	{
		return (matrix2){min(inf,min(a+o.a,b+o.c)),min(inf,min(a+o.b,b+o.d)),min(inf,min(c+o.a,d+o.c)),min(inf,min(c+o.b,d+o.d))};
	}
};
matrix1 one=(matrix1){0,-inf,-inf,0},qwq=(matrix1){1,1,-inf,0},qaq=(matrix1){-1,-1,-inf,0};
matrix2 _one=(matrix2){0,inf,inf,0},_qwq=(matrix2){1,1,inf,0},_qaq=(matrix2){-1,-1,inf,0};
struct seg_tr{
	struct node{
		int ls,rs;
		matrix1 mul1;
		matrix2 mul2;
	}f[N<<1];
	int node_cnt;
	Finline void PushUp(int x)
	{
		f[x].mul1=f[f[x].ls].mul1*f[f[x].rs].mul1;
		f[x].mul2=f[f[x].ls].mul2*f[f[x].rs].mul2;
	}
	int build(int l,int r)
	{
		int cur=++node_cnt;
		f[cur].mul1=one;
		f[cur].mul2=_one;
		if(l==r)
		{
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		return cur;
	}
	void Update(int pos,int l,int r,int cur,int type)
	{
		if(l==r)
		{
			if(type==1)
			{
				f[cur].mul1=qwq;
				f[cur].mul2=_qwq;
			}
			else if(type==2)
			{
				f[cur].mul1=qaq;
				f[cur].mul2=_qaq;
			}
			else
			{
				f[cur].mul1=one;
				f[cur].mul2=_one;
			}
			return;
		}
		int mid=(l+r)>>1;
		if(pos<=mid) Update(pos,l,mid,f[cur].ls,type);
		else Update(pos,mid+1,r,f[cur].rs,type);
		PushUp(cur);
	}
	Finline int Query1(){return max(f[1].mul1.b,f[1].mul1.d);}
	Finline int Query2(){return min(f[1].mul2.b,f[1].mul2.d);}
	Finline int Query3(){return max(f[1].mul1.a,f[1].mul1.c);}
}tr;
char s[N];
int st[N];
int main()
{
	int len;
	read(len);
	len=read_str(s+1);
	int n=1,dep=1;
	for(int i=1;i<=len;++i)
	{
		if(s[i]=='R')
		{
			++dep;
			chmax(n,dep);
		}
		else if(s[i]=='L')
		{
			--dep;
			chmax(dep,1);
		}
	}
	int root=tr.build(1,n);
	int cur=1;
	for(int i=1;i<=len;++i)
	{
		if(s[i]=='R')
		{
			++cur;
		}
		else if(s[i]=='L')
		{
			--cur;
			chmax(cur,1);
		}
		else
		{
			s[i]=(s[i]=='('?1:s[i]==')'?2:0);
			if(s[i]!=st[cur])
			{
				st[cur]=s[i];
				tr.Update(cur,1,n,root,st[cur]);
			}
		}
		printf("%d ",(tr.Query2()<0||tr.Query3())?-1:tr.Query1());
	}
	printf("\n");
    return 0;
}