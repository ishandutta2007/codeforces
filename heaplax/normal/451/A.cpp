#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<ctime>

#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
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
int a,b;
int main()
{
	read(a),read(b);
	a=_min(a,b);
	if(a%2)puts("Akshat");
	else puts("Malvika");
	return 0;
}