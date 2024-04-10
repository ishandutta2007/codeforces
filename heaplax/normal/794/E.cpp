#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define N 300001
#define LL long long
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;	
}
using namespace std;
int n,mx,ta,tb,la,ra,lb,rb,a[N];
int main()
{
	re(n);
	if(n&1)
	{
		la=(n+1)/2+1;
		ra=(n+1)/2-1;
		lb=(n+1)/2;
		rb=(n+1)/2-1;
	}
	else 
	{
		la=n/2+1;
		ra=n/2;
		lb=n/2+1;
		rb=n/2-1;
	}
	for(int i=1;i<=n;++i)re(a[i]),mx=max(mx,a[i]);
	for(int i=0;i<n-1;++i)
		if((n-i)&1)
		{
			--la;++ra;
			//cerr<<la<<" "<<ra<<endl;
			ta=max(ta,min(a[la],max(a[la-1],a[la+1])));
			ta=max(ta,min(a[ra],max(a[ra-1],a[ra+1])));
			printf("%d ",ta);
		}
		else 
		{
			--lb;++rb;
			//cerr<<lb<<" "<<rb<<endl;
			tb=max(tb,max(a[lb],a[lb+1]));
			tb=max(tb,max(a[rb],a[rb+1]));
			printf("%d ",tb);			
		}
	printf("%d ",mx);
}
/*

1 2 3 4 5

*/