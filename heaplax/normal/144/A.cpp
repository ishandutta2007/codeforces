#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<set>
#include<ctime>
#include<queue>
#include<complex>
#include<cstring>
#include<iostream>
#include<algorithm>

#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
#define LL long long
#define _max(a,b) ((a)>(b)?(a):(b))
#define _min(a,b) ((a)<(b)?(a):(b))

using namespace std;
template<class T>
inline void read(T& x)
{
    bool f=false;char ch=getchar();x=0;
    while(ch<48)f=(ch=='-'),ch=getchar();
    while(47<ch)x=(x<<3)+(x<<1)+ch-48,ch=getchar();
    if(f)x=-x;
}
int n,ans,s[233];
int main()
{
	read(n);
	for(int i=1;i<=n;++i)read(s[i]);
	while(1)
	{
		int n1,n2,maxn=0,minn=1<<20;
		for(int i=1;i<=n;++i)
			if(s[i] > maxn)
				maxn=s[i],n1=i;
		for(int i=n;i;i--)
			if(s[i] < minn)
				minn=s[i],n2=i;
		if(n1 == 1 && n2 == n)break;
		ans++;
		if(n1 != 1)swap(s[n1],s[n1-1]);
		else
		if(n2 != n)swap(s[n2],s[n2+1]);
	}
	printf("%d\n",ans);
}