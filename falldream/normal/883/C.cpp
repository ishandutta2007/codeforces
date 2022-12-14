#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
//#define int long long
#define INF 1LL<<62
using namespace std;
int n,T,t0,t1,t2,n1,n2,p1,p2,g1,hav,res,L,R;
ll ans,ust,dst;

inline int read()
{
	int n=0,f=1; char c=getchar();
	while (c<'0' || c>'9') {if(c=='-')f=-1; c=getchar();}
	while (c>='0' && c<='9') {n=n*10+c-'0'; c=getchar();}
	return n*f;
}

void solve()
{
	for (hav=0,g1=0;;hav+=n1,++g1)
	{
		if (hav>n) hav=n;
		res=n-hav;
		if (1LL*hav*t1+1LL*res*min(t0,t2)>T) {if (hav>=n) break; else continue;}
		if (t0<=t2) {ans=min(ans,1LL*g1*p1); if (hav>=n) break; else continue;}
		ust=1LL*hav*t1;
		L=0; R=res/n2+1;
		while (L<R)
		{
			int mid=L+R>>1;
			dst=min(1LL*mid*n2,1LL*res)*t2+max(1LL*res-1LL*mid*n2,0LL)*t0;
			if (ust+dst>T) L=mid+1; else R=mid;
		}
		ans=min(ans,1LL*g1*p1+1LL*L*p2);
		if (hav>=n) break;
	}
}

main()
{
	n=read(); T=read(); t0=read();
	n1=read(); t1=read(); p1=read();
	n2=read(); t2=read(); p2=read();
	ans=INF;
	solve();
	swap(n1,n2); swap(t1,t2); swap(p1,p2);
	solve();
	printf("%I64d",ans==INF?-1:ans);
}