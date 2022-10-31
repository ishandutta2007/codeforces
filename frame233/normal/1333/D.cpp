// Author -- Frame

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<iostream>
#include<set>

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

const int N=3005;
char s[N];
int a[N];
std::set<int> S;
void Upd(int x)
{
	if(a[x-1]==1&&a[x]==0) S.erase(x-1);
	if(a[x]==1&&a[x+1]==0) S.erase(x);
	if(a[x+1]==1&&a[x+2]==0) S.erase(x+1);
	std::swap(a[x],a[x+1]);
	if(a[x-1]==1&&a[x]==0) S.insert(x-1);
	if(a[x]==1&&a[x+1]==0) S.insert(x);
	if(a[x+1]==1&&a[x+2]==0) S.insert(x+1);
}
int main()
{
	int n,k;
	read(n,k);
	read_str(s+1);
	a[0]=a[n+1]=-1;
	for(int i=1;i<=n;++i) a[i]=s[i]=='R';
	int sum=0,tot=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]) ++tot;
		else sum+=tot;
	}
	if(sum<k)
	{
		printf("-1\n");
		return 0;
	}
	std::vector<std::vector<int> > ans;
	for(int i=1;i<n;++i)
	{
		if(a[i]==1&&a[i+1]==0)
		{
			S.insert(i);
		}
	}
	for(int i=k;i>=1;--i)
	{
		std::vector<int> v;
		std::set<int>::iterator _it;
		for(_it=S.begin();_it!=S.end()&&sum>=i;++_it)
		{
			--sum;
			v.push_back(*_it);
		}
		S.erase(S.begin(),_it);
		ans.push_back(v);
		for(auto it:v) Upd(it);
	}
	if(sum)
	{
		printf("-1\n");
	}
	else
	{
		for(auto it:ans)
		{
			printf("%d ",(int)it.size());
			for(auto itt:it) printf("%d ",itt);
			printf("\n");
		}
	}
	return 0;
}