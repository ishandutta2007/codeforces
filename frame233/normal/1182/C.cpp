// Author -- Frame

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

#define Finline __inline__ __attribute__ ((always_inline))

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x7ffffffffffffff;

template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>Finline _Tp abs(const _Tp &a){return a>0?a:-a;}
template <typename _Tp>Finline _Tp max(const _Tp &a,const _Tp &b){return a<b?b:a;}
template <typename _Tp>Finline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template <typename _Tp>Finline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>Finline void chmin(_Tp &a,const _Tp &b){(a>b)&&(a=b);}
template <typename _Tp>Finline void read(_Tp& x)
{
    register char ch(getchar());
    bool f(false);
    while(ch<48||ch>57) f|=ch==45,ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
    if(f) x=-x;
}
template <typename _Tp,typename... Args>Finline void read(_Tp& t, Args&... args)
{
    read(t);read(args...);
}
Finline int read_str(char *s)
{
    register char ch(getchar());
    while(ch<65||ch>122||(ch>90&&ch<97)) ch=getchar();
    register char *tar=s;
    *tar=ch,ch=getchar();
    while((ch>=65&&ch<=90)||(ch>=97&&ch<=122)) *(++tar)=ch,ch=getchar();
    return tar-s+1;
}

const int N=100005;
struct node{
	std::string word;
	int last,cnt;
}a[N];
std::vector<node> v[6];
std::vector<std::pair<node,node> > v1,v2;
std::vector<node> cnt[1000005],left[1000005];
Finline int id(const char &ch)
{
	return ch=='a'?1:ch=='e'?2:ch=='i'?3:ch=='o'?4:ch=='u'?5:0;
}
int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;++i)
	{
		std::cin>>a[i].word;
		for(auto it:a[i].word)
		{
			if(id(it))
			{
				++a[i].cnt;
				a[i].last=id(it);
			}
		}
		v[a[i].last].push_back(a[i]);
	}
	int ans1=0,ans2=0;
	for(int i=1;i<=5;++i)
	{
		for(int j=1;j<=1e6;++j) cnt[j].clear();
		for(auto it:v[i])
		{
			cnt[it.cnt].push_back(it);
		}
		for(int j=1;j<=1e6;++j)
		{
//			printf("J %d size=%llu\n",j,cnt[j].size());
			ans1+=cnt[j].size()>>1;
			for(int k=0;k+1<(int)cnt[j].size();k+=2)
			{
//				printf("	K %d\n",k);
				v1.push_back(std::make_pair(cnt[j][k],cnt[j][k+1]));
			}
			if(cnt[j].size()&1)
			{
				left[j].push_back(*(--cnt[j].end()));
			}
		}
	}
	for(int i=1;i<=1e6;++i)
	{
		ans2+=left[i].size()>>1;
		for(int j=0;j+1<(int)left[i].size();j+=2)
		{
			v2.push_back(std::make_pair(left[i][j],left[i][j+1]));
		}
	}
	if(ans1<=ans2)
	{
		printf("%d\n",ans1);
		for(int i=0;i<ans1;++i)
		{
			printf("%s %s\n",v2[i].first.word.c_str(),v1[i].first.word.c_str());
			printf("%s %s\n",v2[i].second.word.c_str(),v1[i].second.word.c_str());
		}
		return 0;
	}
	else
	{
		printf("%d\n",ans2+((ans1-ans2)>>1));
		for(int i=0;i<ans2;++i)
		{
			printf("%s %s\n",v2[i].first.word.c_str(),v1[i].first.word.c_str());
			printf("%s %s\n",v2[i].second.word.c_str(),v1[i].second.word.c_str());
		}
		for(int i=ans2;i+1<ans1;i+=2)
		{
			printf("%s %s\n",v1[i+1].first.word.c_str(),v1[i].first.word.c_str());
			printf("%s %s\n",v1[i+1].second.word.c_str(),v1[i].second.word.c_str());
		}
		return 0;
	}
    return 0;
}