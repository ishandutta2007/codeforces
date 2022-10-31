#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<cstdio>
#include<cstring>
#include<iostream>
#include<set>
#include<algorithm>
#define IT std::multiset<int>::iterator

typedef long long ll;

template <typename T>T gcd(const T &a,const T &b){return (!b)?a:gcd(b,a%b);}
template <typename T>inline T abs(const T &a){return a>0?a:-a;}
template <typename T>inline T max(const T &a,const T &b){return a<b?b:a;}
template <typename T>inline T min(const T &a,const T &b){return a<b?a:b;}
template <typename T>inline void chmax(T &a,const T &b){(a<b)&&(a=b);}
template <typename T>inline void chmin(T &a,const T &b){(a>b)&&(a=b);}

template <typename T>inline void read(T& x)
{
    register char ch=getchar();
    while(ch<48||ch>57) ch=getchar();
    x=ch&15,ch=getchar();
    while(ch>=48&&ch<=57) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
}
template <typename T,typename... Args> inline void read(T& t, Args&... args)
{
    read(t);read(args...);
}

const int N=200005;
int a[N],b[N],n;
std::multiset<int> s;
inline void add(int &a,const int &b){(a+=b)>=n&&(a-=n);}
int main()
{
	int x;
	read(n);
	for(int i=1;i<=n;++i) read(a[i]);
	for(int i=1;i<=n;++i) read(x),s.insert(x);
	for(int i=1;i<=n;++i)
	{
		int t1=n-a[i];
		if(a[i])
		{
			IT it=s.lower_bound(t1);
			if(it!=s.end())
			{
				b[i]=*it;
				s.erase(it);
			}
			else
			{
				it=s.lower_bound(0);
				b[i]=*it;
				s.erase(it);
			}
		}
		else
		{
			IT it=s.lower_bound(0);
			b[i]=*it;
			s.erase(it);
		}
	}
	for(int i=1;i<=n;++i) add(a[i],b[i]);
	for(int i=1;i<=n;++i) printf("%d ",a[i]);
	return 0;
}
//Frame