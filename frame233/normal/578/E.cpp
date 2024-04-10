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

const int N=100005;
char s[N];
std::vector<int> v[N];
std::vector<int> v1,v2;
std::vector<std::vector<int> > e[2][2];
int main()
{
	int n=read_str(s+1);
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='R') ++cnt2;
		else ++cnt1;
	}
	int cnt=0;
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='R')
		{
			if(v1.empty())
			{
				v2.pb(++cnt);
				v[cnt].pb(i);
			}
			else
			{
				int x=v1.back();
				v1.pop_back();
				v[x].pb(i);
				v2.pb(x);
			}
		}
		else
		{
			if(v2.empty())
			{
				v1.pb(++cnt);
				v[cnt].pb(i);
			}
			else
			{
				int x=v2.back();
				v2.pop_back();
				v[x].pb(i);
				v1.pb(x);
			}
		}
	}
	printf("%d\n",cnt-1);
	for(int i=1;i<=cnt;++i)
	{
		e[s[v[i][0]]=='R'][s[v[i].back()]=='R'].pb(v[i]);
	}
	auto solve=[&]()->std::vector<int>
	{
		std::vector<int> ans;
		if(!e[0][1].empty()&&!e[1][0].empty())
		{
			std::vector<int> a=e[1][0].back(),b=e[0][1].back();
			e[0][1].pop_back();
			e[1][0].pop_back();
			if(a.back()>b.back())
			{
				b.pb(a.back());
				a.pop_back();
			}
			else
			{
				a.pb(b.back());
				b.pop_back();
			}
			for(int i=0;i<SZ(e[0][0]);++i)
			{
				for(auto it:e[0][0][i]) ans.pb(it);
				for(auto it:e[1][1][i]) ans.pb(it);
			}
			for(int i=0;i<SZ(e[0][1]);++i)
			{
				for(auto it:e[0][1][i]) ans.pb(it);
			}
			for(auto it:b) ans.pb(it);
			for(int i=0;i<SZ(e[1][0]);++i)
			{
				for(auto it:e[1][0][i]) ans.pb(it);
			}
			for(auto it:a) ans.pb(it);
		}
		else
		{
			if(!e[0][1].empty())
			{
				for(int i=0;i<SZ(e[0][0]);++i)
				{
					for(auto it:e[0][0][i]) ans.pb(it);
					for(auto it:e[1][1][i]) ans.pb(it);
				}
				for(auto it:e[0][1])
				{
					for(auto itt:it)
					{
						ans.pb(itt);
					}
				}
			}
			else
			{
				if(!e[0][0].empty()) for(auto it:e[0][0][0]) ans.pb(it);
				for(auto it:e[1][0])
				{
					for(auto itt:it)
					{
						ans.pb(itt);
					}
				}
				if(!e[1][1].empty()) for(auto it:e[1][1][0]) ans.pb(it);
				for(int i=1;i<SZ(e[0][0]);++i)
				{
					for(auto it:e[0][0][i]) ans.pb(it);
					for(auto it:e[1][1][i]) ans.pb(it);
				}
			}
		}
		return ans;
	};
	if(cnt1==cnt2)
	{
		std::vector<int> ans=solve();
		for(auto it:ans) printf("%d ",it);
		printf("\n");
	}
	else
	{
		if(cnt1>cnt2)
		{
			std::vector<int> a=e[0][0].back();
			e[0][0].pop_back();
			std::vector<int> ans=solve();
			if(ans.empty())
			{
				for(auto it:a)
				{
					printf("%d ",it);
				}
				printf("\n");
			}
			else if(s[ans[0]]=='R')
			{
				for(auto it:a) printf("%d ",it);
				for(auto it:ans) printf("%d ",it);
				printf("\n");
			}
			else
			{
				for(auto it:ans) printf("%d ",it);
				for(auto it:a) printf("%d ",it);
				printf("\n");
			}
		}
		else
		{
			std::vector<int> a=e[1][1].back();
			e[1][1].pop_back();
			std::vector<int> ans=solve();
			if(ans.empty())
			{
				for(auto it:a)
				{
					printf("%d ",it);
				}
				printf("\n");
			}
			else if(s[ans[0]]=='L')
			{
				for(auto it:a) printf("%d ",it);
				for(auto it:ans) printf("%d ",it);
				printf("\n");
			}
			else
			{
				for(auto it:ans) printf("%d ",it);
				for(auto it:a) printf("%d ",it);
				printf("\n");
			}
		}
	}
	return 0;
}