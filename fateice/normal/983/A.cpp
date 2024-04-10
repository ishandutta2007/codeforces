#include<bits/stdc++.h>
#define L long long
using namespace std;
int t;
L p,q,m;
inline L gcd(L n,L m)
{
    return m?gcd(m,n%m):n;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i;
	L k;
	scanf("%d",&t);
	while(t--)
	  {
       scanf("%lld%lld%lld",&p,&q,&m);
       k=gcd(p,q);
       q/=k;
       k=gcd(q,m);
       while(q>1 && k>1)
         {
          k=gcd(q,k);
          q/=k;
         }
       if(q==1)
         printf("Finite\n");
       else
         printf("Infinite\n");
      }
	return 0;
}