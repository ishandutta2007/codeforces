// Author -- Frame

#include<cstdio>
#include<cstring>
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

const int N=200005;
int L_min[N],R_min[N];
int L_max[N],R_max[N];
int a[N];
int st[N],top;
void init(int n)
{
	top=0;
	for(int i=1;i<=n;++i)
	{
		while(top&&a[st[top]]>=a[i]) --top;
		L_min[i]=top?st[top]+1:1;
		st[++top]=i;
	}
	
	top=0;
	for(int i=n;i>=1;--i)
	{
		while(top&&a[st[top]]>=a[i]) --top;
		R_min[i]=top?st[top]-1:n;
		st[++top]=i;
	}
	
	top=0;
	for(int i=1;i<=n;++i)
	{
		while(top&&a[st[top]]<=a[i]) --top;
		L_max[i]=top?st[top]+1:1;
		st[++top]=i;
	}
	
	top=0;
	for(int i=n;i>=1;--i)
	{
		while(top&&a[st[top]]<=a[i]) --top;
		R_max[i]=top?st[top]-1:n;
		st[++top]=i;
	}
}
struct node{
	int r,id;
};
std::vector<node> v[N];
std::vector<std::pair<int,int> > _v[N];
int ans[N];
int sum1[N],sum2[N];
std::vector<int> res[N];
std::vector<int> qry[N];
int val[N],id[N];
int main()
{
	int n,q;
	read(n,q);
	for(int i=1;i<=n;++i) read(a[i]);
	for(int i=1;i<n;++i)
	{
		sum1[i]=sum1[i-1]+(a[i+1]>=a[i]);
		sum2[i]=sum2[i-1]+(a[i+1]<=a[i]);
	}
	init(n);
	int x,y;
	for(int i=1;i<=q;++i)
	{
		read(x,y);
		v[x].push_back((node){y,i});
		if(sum1[y-1]-sum1[x-1]==y-x||sum2[y-1]-sum2[x-1]==y-x)
		{
			ans[i]=0;
		}
		else
		{
			ans[i]=3;
		}
	}
	int qwq=inf,qaq=0;
	for(int i=n;i>=1;--i)
	{
		qry[max(R_max[i],R_min[i])+1].push_back(i);
		val[i]=min(L_max[i],L_min[i]);
	}
	for(int i=n;i>=1;--i)
	{
		while(top&&val[st[top]]<=val[i]) --top;
		st[++top]=i;
		for(auto it:qry[i])
		{
			int l=1,r=top;
			while(l<r)
			{
				int mid=(l+r+1)>>1;
				if(val[st[mid]]>it) l=mid;
				else r=mid-1;
			}
			if(val[st[l]]>it) id[it]=st[l];
		}
	}
	for(int i=n;i>=1;--i)
	{
		if(id[i]&&id[i]<qwq)
		{
			qwq=id[i];
			qaq=i;
		}
		for(auto it:v[i])
		{
			if(it.r>=qwq)
			{
				ans[it.id]=4;
				res[it.id].push_back(qaq);
				if(a[qaq]<=a[qwq]) res[it.id].push_back(R_min[qaq]+1);
				else res[it.id].push_back(L_min[qwq]-1);
				if(a[qaq]>=a[qwq]) res[it.id].push_back(R_max[qaq]+1);
				else res[it.id].push_back(L_max[qwq]-1);
				res[it.id].push_back(qwq);
				std::sort(res[it.id].begin(),res[it.id].end());
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		int l=L_min[i]-1;
		int r=R_min[i]+1;
		if(l>=1&&r<=n)
		{
			_v[l].push_back(std::make_pair(i,r));
		}
		l=L_max[i]-1;
		r=R_max[i]+1;
		if(l>=1&&r<=n)
		{
			_v[l].push_back(std::make_pair(i,r));
		}
	}
	qwq=inf,qaq=0;
	int l=0;
	for(int i=n;i>=1;--i)
	{
		for(auto it:_v[i])
		{
			if(it.second<qwq)
			{
				qwq=it.second;
				qaq=it.first;
				l=i;
			}
		}
		for(auto it:v[i])
		{
			if(ans[it.id]==3)
			{
				res[it.id].push_back(l);
				res[it.id].push_back(qaq);
				res[it.id].push_back(qwq);
			}
		}
	}
	for(int i=1;i<=q;++i)
	{
		printf("%d\n",ans[i]);
		for(auto it:res[i])
		{
			printf("%d ",it);
		}
		printf("\n");
	}
	return 0;
}