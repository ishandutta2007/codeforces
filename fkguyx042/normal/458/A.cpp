#include<bits/stdc++.h>
using namespace std;
int a[100020];
char s1[100020],s2[100020];
int main()
{
  scanf("%s%s",s1,s2);
  int len1=strlen(s1),len2=strlen(s2);
  for(int i=len1-1;i>=0;i--)
  {
    if(s1[i]=='1')
      a[len1-i-1]++;
  }
  for(int i=len2-1;i>=0;i--)
  {
    if(s2[i]=='1')
      a[len2-i-1]--;
  }
  for(int i=100000;i>=2;i--)
  {
    if(a[i]==1)
    {
      a[i-1]++;
      a[i-2]++;
    }
    else if(a[i]>=2)
    {
      a[i-1]+=2;
      a[i-2]+=2;
    }
    else if(a[i]==-1)
    {
      a[i-1]--;
      a[i-2]--;
    }
    else if(a[i]<=-2)
    {
      a[i-1]-=2;
      a[i-2]-=2;
    }
    a[i]=0;
  }
  double x=(sqrt(5)+1)/2;
  if(a[1]*x+a[0]>0)
    printf(">\n");
  else if(a[1]*x+a[0]<0)
    printf("<\n");
  else
    printf("=\n");
  return 0;
}