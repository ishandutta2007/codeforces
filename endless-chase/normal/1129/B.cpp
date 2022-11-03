#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const long long maxn=1e6;
long long k,a,b,d,ans,x,y,pp,ap,bp;
pair<long long,long long> cur;
long long gcd(long long a,long long b)
{
	if (!b) return a;
	return gcd(b,a%b);
}
pair<long long,long long> extgcd(long long a,long long b)
{
	if (!b) return make_pair(1,0);
	pair<long long,long long> cur=extgcd(b,a%b);
	return make_pair(cur.second,cur.first-(a/b)*cur.second);
}
int main()
{
	scanf("%lld",&k);
	for (long long n=1;n<=2000;n++)
	{
		for (long long len=1;len<n;len++)
		{
			a=n-len;b=n;
			d=gcd(a,b);
			if (k%d) continue;
			cur=extgcd(a,b);
			y=cur.first*(k/d);x=cur.second*(k/d);
			ap=a/d;bp=b/d;
			for (long long h=1;h<=2;h++)
			{
				if (y<0)
				{
					pp=(-y+bp)/bp;
					y+=bp*pp;
					x-=ap*pp;
				} 
				if (y>maxn)
				{
					pp=(y-maxn+bp-1)/bp;
					y-=bp*pp;
					x+=ap*pp;
				}
				if (x>=0) 
				{
					pp=(x+ap)/ap;
					x-=ap*pp;
					y+=bp*pp;
				}
				if (x<-maxn)
				{
					pp=(-maxn-x+ap-1)/ap;
					x+=ap*pp;
					y-=bp*pp;
				}
			}
			if (x>=-maxn && x<0 && y>0 && y<=maxn) 
			{
				printf("%lld\n",n);
				for (long long i=1;i<n-len;i++) printf("0 ");
				printf("%lld ",x);
				printf("%lld ",y);
				for (long long i=1;i<len;i++) printf("0 ");
				return Accepted;
			}
		}
	}
	printf("-1\n");
	return Accepted;
}