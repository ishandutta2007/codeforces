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

const int N=200005;
int sa[N],rnk[N],tax[N],tp[N];
int height[N];
int n,m;
void Rsort()
{
	memset(tax,0,(m+3)<<2);
	for(int i=1;i<=n;++i) ++tax[rnk[i]];
	for(int i=1;i<=m;++i) tax[i]+=tax[i-1];
	for(int i=n;i>=1;--i) sa[tax[rnk[tp[i]]]--]=tp[i];
}
void SA(char *s)
{
	for(int i=1;i<=n;++i) rnk[i]=s[i],tp[i]=i;
	m=127;
	Rsort();
	for(int w=1,p=0;p<n;w<<=1,m=p)
	{
		p=0;
		for(int i=0;i<w;++i) tp[++p]=n-i;
		for(int i=1;i<=n;++i) if(sa[i]>w) tp[++p]=sa[i]-w;
		Rsort();std::swap(rnk,tp);
		rnk[sa[1]]=p=1;
		for(int i=2;i<=n;++i) rnk[sa[i]]=(tp[sa[i-1]]==tp[sa[i]]&&tp[sa[i-1]+w]==tp[sa[i]+w])?p:++p;
	}
	int k=0;
	for(int i=1;i<=n;++i)
	{
		if(rnk[i]==1) continue;
		if(k) --k;
		int j=sa[rnk[i]-1];
		while(i+k<=n&&j+k<=n&&s[i+k]==s[j+k]) ++k;
		height[rnk[i]]=k;
	}
}
char s[N];
int f[N][21],Log2[N];
Finline int Query(int l,int r)
{
	int k=Log2[r-l+1];
	return min(f[l][k],f[r-(1<<k)+1][k]);
}
pi st[N];
int top;
ll solve(std::vector<int> v1,std::vector<int> v2)
{
	top=0;
	std::vector<pi> v;
	for(auto it:v1) v.pb(mkpr(it,1));
	for(auto it:v2) v.pb(mkpr(it,0));
	std::sort(v.begin(),v.end());
	std::reverse(v.begin(),v.end());
	int last=0;
	ll ans=0,sum=0;
	auto ins=[&](int qwq,int cnt)
	{	
		while(top&&qwq<=st[top].first)
		{
			sum-=1ll*st[top].first*st[top].second;
			cnt+=st[top].second;
			--top;
		}
		st[++top]=mkpr(qwq,cnt);
		sum+=1ll*qwq*cnt;
	};
	for(auto it:v)
	{
		if(last)
		{
			ins(Query(it.first+1,last),0);
		}
		if(it.second==1)
		{
			ans+=sum;
		}
		else
		{
			ins(height[it.first],1);
		}
		last=it.first;
	}
	v.clear();
	return ans;
}
int main()
{
	int _;
	read(n,_);
	read_str(s+1);
	SA(s);
	for(int i=2;i<=n;++i) Log2[i]=Log2[i>>1]+1;
	for(int i=n;i>=1;--i)
	{
		f[i][0]=height[i];
		for(int j=1;j<=20&&i+(1<<(j-1))<=n;++j)
		{
			f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		}
	}
	while(_--)
	{
		int a,b;
		read(a,b);
		std::vector<int> v1,v2;
		int x;
		for(int i=1;i<=a;++i)
		{
			read(x);
			v1.pb(rnk[x]);
		}
		for(int i=1;i<=b;++i)
		{
			read(x);
			v2.pb(rnk[x]);
		}
		std::sort(v1.begin(),v1.end());
		std::sort(v2.begin(),v2.end());
		ll ans=0;
		for(auto it:v1)
		{
			auto itt=std::lower_bound(v2.begin(),v2.end(),it);
			if(itt!=v2.end()&&*itt==it)
			{
				ans+=n-sa[it]+1;
			}
		}
		printf("%lld\n",ans+solve(v1,v2)+solve(v2,v1));
	}
	return 0;
}

/*
7 4
abacaba
1 7
1
1 2 3 4 5 6 7

*/