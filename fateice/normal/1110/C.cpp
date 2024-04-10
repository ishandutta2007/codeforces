#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int t,n;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i;
	scanf("%d",&t);
	while(t--)
	  {
       scanf("%d",&n);
       for(i=1;i<=n;i<<=1);
       if(i==n+1)
         {
          for(i=2;i*i<=n;i++)
            if(n%i==0)
              break;
          if(n%i==0)
            printf("%d\n",n/i);
          else
            printf("1\n");
         }
       else
         printf("%d\n",i-1);
      }
	return 0;
}