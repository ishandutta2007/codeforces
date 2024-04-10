#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,num[10];
int main()
{ scanf("%d",&k);
  for (k++;;k++)
  {  for (i=k;i;i/=10)  
      num[i%10]++;
     for (i=0;i<=9;i++) if (num[i]>1) break;
     if (i==10) {printf("%d\n",k); break;}
    memset(num,0,sizeof(num));
}
}