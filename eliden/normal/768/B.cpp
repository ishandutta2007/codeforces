#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define debug(x) cerr<<#x<<": "<<x<<endl
const int sz=1e6;

long long n, l ,r;
int main()
{
	scanf("%lld%lld%lld",&n,&l,&r);
	long long count=0;
	long long exp=0;
	long long x=n;
	while(x>0)
	{
		++exp;
		x/=2;
	}
	--exp;
	//debug(exp);
	for(long long i=l;i<=r;++i)
	{
		long long lev=0;
		long long pw=1;
		while((pw&i)==0)
		{
			++lev;
			pw*=2;
		}
		//debug(lev);
		pw=1;
		rep(j,0,exp-lev)
			pw*=2;
		if(n&(pw))
		   ++count;
	}
	printf("%lld\n",count);
}