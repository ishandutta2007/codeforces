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
char s[N],t[N];
int cnt[26];
int st[N],top;
int calc()
{
	int maxx=0;
	for(int i=0;i<26;++i) chmax(maxx,cnt[i]);
	return maxx;
}
struct BIT{
	int c[N],n;
	Finline void add(int x,int C){for(;x<=n;x+=lowbit(x))c[x]+=C;}
	Finline int sum(int x){int ans=0;for(;x;x-=lowbit(x))ans+=c[x];return ans;}
}tr;
int id[N];
int sum[N];
void MAIN()
{
	memset(cnt,0,sizeof(cnt));
	top=0;
	int n=read_str(s+1);
	memset(sum,0,(n+3)<<2);
	tr.n=n;
	memset(tr.c,0,(n+3)<<2);
	int m=0;
	for(int i=1;i<n;++i)
	{
		if(s[i]==s[i+1])
		{
			t[++m]=s[i];
			++cnt[t[m]-97];
			id[m]=i;
		}
	}
	int maxx=0,pos=0;
	for(int i=0;i<26;++i)
	{
		if(cnt[i]>maxx)
		{
			maxx=cnt[i];
			pos=i;
		}
	}
	std::vector<std::pair<int,int> > ans;
	if(maxx*2>=m)
	{
		char ch=pos+97;
		for(int i=1;i<=m;++i)
		{
			if(t[i]==ch)
			{
				if(!top) st[++top]=i;
				else
				{
					if(t[st[top]]==ch) st[++top]=i;
					else
					{
						ans.push_back(std::make_pair(id[st[top]]+1,id[i]));
						--top;
					}
				}
			}
			else
			{
				if(!top) st[++top]=i;
				else
				{
					if(t[st[top]]!=ch) st[++top]=i;
					else
					{
						ans.push_back(std::make_pair(id[st[top]]+1,id[i]));
						--top;
					}
				}
			}
		}
		
	}
	else
	{
		if(m&1)
		{
			--cnt[t[m]-97];
			--m;
		}
		int rest=m;
		for(int i=1;i<=m;++i)
		{
			if(!top||t[st[top]]==t[i]) st[++top]=i;
			else
			{
				--cnt[t[i]-97];
				--cnt[t[st[top]]-97];
				rest-=2;
				if(calc()*2<=rest)
				{
					ans.push_back(std::make_pair(id[st[top]]+1,id[i]));
					--top;
				}
				else
				{
					rest+=2;
					++cnt[t[i]-97];
					++cnt[t[st[top]]-97];
					st[++top]=i;
				}
			}
		}
	}
	for(auto &&it:ans)
	{
		int l=it.first;
		int r=it.second;
		++sum[l],--sum[r+1];
		l-=tr.sum(l);
		r-=tr.sum(r);
		tr.add(it.second,r-l+1);
		it=std::make_pair(l,r);
	}
	for(int i=1;i<=n;++i)
	{
		sum[i]+=sum[i-1];
	}
	m=0;
	for(int i=1;i<=n;++i)
	{
		if(!sum[i])
		{
			t[++m]=s[i];
		}
	}
	int last=1;
	int qwq=0;
	for(int i=1;i<m;++i)
	{
		if(t[i]==t[i+1])
		{
			ans.push_back(std::make_pair(last-qwq,i-qwq));
			qwq+=i-last+1;
			last=i+1;
		}
	}
	ans.push_back(std::make_pair(last-qwq,m-qwq));
	printf("%d\n",(int)ans.size());
	for(auto it:ans)
	{
		printf("%d %d\n",it.first,it.second);
	}
}
int main()
{
	int _;
	read(_);
	while(_--) MAIN();
	return 0;
}
/*
4
aabbcc
aaabbb
aaa
abacad

*/