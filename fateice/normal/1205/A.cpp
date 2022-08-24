#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,x[200010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i;
	scanf("%d",&n);
	if(n%2==0)
	  printf("NO\n");
	else
	  {
       printf("YES\n");
       for(i=1;i<=n;i++)
         if(i%2==1)
           x[i]=2*i-1,x[i+n]=2*i;
         else
           x[i]=2*i,x[i+n]=2*i-1;
       for(i=1;i<=2*n;i++)
         printf("%d ",x[i]);
       printf("\n");
      }
	return 0;
}