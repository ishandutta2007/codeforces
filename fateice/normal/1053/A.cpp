#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,m,p;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d%d",&n,&m,&p);
	int k;
	k=__gcd(n,p);
	n/=k;
	p/=k;
	k=__gcd(m,p);
	m/=k;
	p/=k;
	if(p>2)
	  {
	   printf("NO\n");
	   return 0;
	  }
	else if(p==1)
	  {
	   if(k>1)
	     m*=2;
	   else
	     n*=2;
	  }
	printf("YES\n0 0\n%d 0\n0 %d\n",n,m);
	return 0;
}