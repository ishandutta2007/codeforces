#include<bits/stdc++.h>
#define L long long
using namespace std;
int n;
L p;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	scanf("%d",&n);
	for(i=0;i<=n && i<=8;i++)
	  {
       p+=n-i+1;
       if(i<8)
         for(j=0;j<=n-i && j<=4;j++)
           p+=n-i-j;
      }
    cout<<p;
	return 0;
}