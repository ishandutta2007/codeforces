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
int n,ans;
int main()
{
	read(n);
	int last=0,c;
	while(n--)
	{
		read(c);
		if(c != last)ans++;
		last=c;
	}
	printf("%d\n",ans);
	return 0;
}