#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<set>
#include<ctime>
#include<queue>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>

#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
#define LL long long
#define _max(a,b) (a>b?a:b)
#define _min(a,b) (a<b?a:b)

using namespace std;
template<class T>
inline void read(T& x)
{
    bool f=false;char ch=getchar();x=0;
    while(ch<48)f=(ch=='-'),ch=getchar();
    while(ch>=48)x=(x<<3)+(x<<1)+ch-48,ch=getchar();
    if(f)x*=-1;
}
int a,b,lesss;
int main()
{
	read(a),read(b);
	while(1)
	{
		lesss++;
		a-=lesss;
		if(a<0)
		{
			puts("Vladik");
			return 0;
		}
		lesss++;
		b-=lesss;
		if(b<0)
		{
			puts("Valera");
			return 0;
		}
	}
}