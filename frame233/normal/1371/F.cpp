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
const ll INF=0x3f3f3f3f3f3f3f3f;

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
template <typename _Tp,typename... Args>Finline void read(_Tp &t,Args &...args){read(t);read(args...);}
Finline int read_str(char *s)
{
	char ch(getchar());
	while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;
	*tar=ch,ch=getchar();
	while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=500005;
struct node{
	int L1,L2;    // L1 : left  <   L2 : left  >
	int R1,R2;    // R1 : right <   R2 : right >
	int La1,La2;  // La1: >>><<<    La2: <<<>>>
	int Ra1,Ra2;  // Ra1: >>><<<    Ra2: <<<>>>
	int ans1,ans2;// ans1:>>><<<    ans2:<<<>>>
	int l,r;
	Finline node operator + (const node &o)const
	{
		node c;
		c.L1=L1==r-l+1?L1+o.L1:L1;
		c.R1=o.R1==o.r-o.l+1?o.R1+R1:o.R1;
		
		c.L2=L2==r-l+1?L2+o.L2:L2;
		c.R2=o.R2==o.r-o.l+1?o.R2+R2:o.R2;
		
		c.La1=La1==r-l+1?(L2==r-l+1?La1+o.La1:La1+o.L1):La1;
		c.La2=La2==r-l+1?(L1==r-l+1?La2+o.La2:La2+o.L2):La2;
		
		c.Ra1=o.Ra1==o.r-o.l+1?(o.R1==o.r-o.l+1?o.Ra1+Ra1:o.Ra1+R2):o.Ra1;
		c.Ra2=o.Ra2==o.r-o.l+1?(o.R2==o.r-o.l+1?o.Ra2+Ra2:o.Ra2+R1):o.Ra2;
		
		c.ans1=max(max(ans1,o.ans1),max(Ra1+o.L1,o.La1+R2));
		c.ans2=max(max(ans2,o.ans2),max(Ra2+o.L2,o.La2+R1));
		
		c.l=l,c.r=o.r;
		return c;
	}
	Finline void flip()
	{
		std::swap(L1,L2);std::swap(R1,R2);
		std::swap(La1,La2);std::swap(Ra1,Ra2);
		std::swap(ans1,ans2);
	}
};
char s[N];
struct seg_tr{
	struct Node{
		int ls,rs;
		node val;
		bool tag;  
	}f[N<<1];
	int node_cnt;
	Finline void PushUp(int x)
	{
		f[x].val=f[f[x].ls].val+f[f[x].rs].val;
	}
	int build(int l,int r)
	{
		int cur=++node_cnt;
		if(l==r)
		{
			if(s[l]=='<') f[cur].val=(node){1,0,1,0,1,1,1,1,1,1,l,l};
			else f[cur].val=(node){0,1,0,1,1,1,1,1,1,1,l,l};
			return cur;
		}
		int mid=(l+r)>>1;
		f[cur].ls=build(l,mid);
		f[cur].rs=build(mid+1,r);
		PushUp(cur);
		return cur;
	}
	Finline void flip(int cur)
	{
		f[cur].tag^=1;
		f[cur].val.flip();
	}
	Finline void PushDown(int cur)
	{
		if(f[cur].tag)
		{
			flip(f[cur].ls);
			flip(f[cur].rs);
			f[cur].tag=0;
		}
	}
	void Update(int L,int R,int l,int r,int cur)
	{
		if(L<=l&&r<=R)
		{
			flip(cur);
			return;
		}
		PushDown(cur);
		int mid=(l+r)>>1;
		if(L<=mid) Update(L,R,l,mid,f[cur].ls);
		if(R>mid) Update(L,R,mid+1,r,f[cur].rs);
		PushUp(cur);
	}
	node Query(int L,int R,int l,int r,int cur)
	{
		if(L<=l&&r<=R) return f[cur].val;
		PushDown(cur);
		int mid=(l+r)>>1;
		if(L<=mid&&R>mid) return Query(L,R,l,mid,f[cur].ls)+Query(L,R,mid+1,r,f[cur].rs);
		return L<=mid?Query(L,R,l,mid,f[cur].ls):Query(L,R,mid+1,r,f[cur].rs);
	}
}tr;
int main()
{
	int n,q;
	read(n,q);
	read_str(s+1);
	tr.build(1,n);
	while(q--)
	{
		int l,r;
		read(l,r);
		tr.Update(l,r,1,n,1);
		printf("%d\n",tr.Query(l,r,1,n,1).ans1);
	}
	return 0;
}