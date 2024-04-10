#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,a,b;
L p;
inline L gcd(L n,L m)
{
    return m?gcd(m,n%m):n;
}
inline void print(int k)
{
    int i;
    for(i=2;i*i<=k;i++)
      if(k%i==0)
        break;
    if(i*i>k)
      i=k;
    printf("%d\n",i);
    exit(0);
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j,k;
	scanf("%d%d%d",&n,&a,&b);
	for(i=2;i<=n;i++)
	  {
       scanf("%d%d",&j,&k);
       p=gcd(p,(L)j*k);
      }
    k=gcd(a,p);
    if(k>1)
      print(k);
    k=gcd(b,p);
    if(k>1)
      print(k);
    printf("-1\n");
	return 0;
}