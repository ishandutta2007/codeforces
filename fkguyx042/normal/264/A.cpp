#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k,Min,Max;
char c[1000001];
struct Node{int sum,bh;}a[1000001];
inline bool cmp(Node a,Node b) {return a.sum<b.sum;}
int main()
{   scanf("%s",&c);
     int Len=strlen(c);
     Max=Len; Min=1;
    for (n=0;n<Len;n++)
   {  
       a[n].bh=n;
      if (c[n]=='r') a[n].sum=Min++;
      else a[n].sum=Max--;
  }
  sort(a,a+Len,cmp);
for (i=0;i<Len;i++)
 printf("%d\n",a[i].bh+1);
}