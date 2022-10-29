#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
int a[1005],b[1005];
int x[1005],y[1005];
int main()
{
  int n;
  while(~scanf("%d",&n))
  {
      memset(x,0,sizeof(x));
      memset(y,0,sizeof(y));
      for(int i=0;i<n;++i)
      {
          scanf("%d%d",&a[i],&b[i]);
          x[a[i]]++;
          y[b[i]]++;
      }
      int sum=0;
      for(int i=0;i<n;++i)
      {
          if(x[b[i]])
        {     if(a[i]!=b[i])
            {  sum+=x[b[i]];
              x[b[i]]=0;
            }
            else if(y[a[i]]>1)
            {
                sum+=x[b[i]];
                x[b[i]]=0;
             }
            else if(x[b[i]]>1)
            {
                sum+=x[b[i]]-1;
                x[b[i]]=1;
            }
         }
      }
      printf("%d\n",n-sum);
  }
  return 0;
}