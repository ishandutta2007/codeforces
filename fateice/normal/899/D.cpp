#include<bits/stdc++.h>
#define L long long
using namespace std;
int n;
L p;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	L i,j,k;
	scanf("%d",&n);
	for(i=0,j=1;i<999999999 && i*10+9<=2*n-1;i=i*10+9,j*=10);
	for(;i>=0 && i<=2*n-1;i+=j)
	  {
	   k=min((L)n,i-1);
	   if(i-k<k)
	     p+=(k-(i-k)+1)/2;
	  }
	cout<<p;
	return 0;
}