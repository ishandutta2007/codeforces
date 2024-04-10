#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,m,x[2][100010],p;
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	scanf("%d%d",&n,&m);
	while(m--)
	  {
       scanf("%d%d",&i,&j);
       i--;
       if(!x[i][j])
         {
          x[i][j]=1;
          if(x[i^1][j])
            p++;
          if(x[i^1][j-1])
            p++;
          if(x[i^1][j+1])
            p++;
         }
       else
         {
          x[i][j]=0;
          if(x[i^1][j])
            p--;
          if(x[i^1][j-1])
            p--;
          if(x[i^1][j+1])
            p--;
         }
       if(p)
         printf("No\n");
       else
         printf("Yes\n");
      }
	return 0;
}