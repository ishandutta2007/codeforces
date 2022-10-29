#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
const int seed=133;
map<long long,int>mp;
long long Sum;
char c1[31],c[100001];
int i,j,m,n,p,k,sum[1501],ans;
int main()
{ scanf("%s",&c); n=strlen(c);
  scanf("%s",&c1);
  scanf("%d",&k);
  for (i=1;i<=n;i++)
    if (c1[c[i-1]-'a']=='0')
       sum[i]=sum[i-1]+1;else 
       sum[i]=sum[i-1];
  for (i=1;i<=n;i++)
  {  Sum=0;
     for (j=i;j<=n;j++)
     {    Sum*=seed;
         Sum+=c[j-1]-'a'+1;
          if (sum[j]-sum[i-1]<=k&&!mp[Sum])
          { mp[Sum]=1;
            ans++;
          }
         }
}
printf("%d\n",ans);
}