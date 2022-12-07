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
int n,p,s;
bool ok[123],tick=true;
int main()
{
	read(n);
	read(p);while(p--)read(s),ok[s]=true;
	read(p);while(p--)read(s),ok[s]=true;
	for(int i=1;i<=n;i++)tick&=ok[i];
	if(tick)puts("I become the guy.");
	else puts("Oh, my keyboard!");
	return 0;
}