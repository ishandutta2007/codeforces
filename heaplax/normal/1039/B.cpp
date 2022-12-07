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
#define int long long
#define LOG(x) cerr<<#x<<" = "<<x<<endl
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
int n,k;
bool query(int l,int r)
{
	printf("%lld %lld\n",l,r);
	fflush(stdout);
	char tmp[10];
	scanf("%s",tmp+1);
	return tmp[1]=='Y';
}
main()
{
	srand(time(0));
	re(n),re(k);
	++k;
	int l=1,r=n;
	while(1)
	{
		l=max(l,1ll);
		r=min(r,n);
		if(r-l<=50)
		{
			int x=rand()%(r-l+1)+l;
			if(query(x,x))return 0;
			l-=k;r+=k;
		}
		else
		{
			int m=l+r>>1;
			if(rand()&1)
			{
				if(query(l,m))l-=k,r=m+k;
				else r+=k,l=m-k;
			}
			else
			{
				if(query(m+1,r))r+=k,l=m-k;
				else l-=k,r=m+k;
			}
		}
	}
}