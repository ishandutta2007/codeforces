#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,x[26][26],y[26],z[26],p;
char a[200001],b[200001];
int main()
{
    int i,j;
    cin>>n>>a>>b;
    p=n;
    for(i=0;i<n;i++)
      if(a[i]==b[i])
        p--;
      else
        x[a[i]-'a'][b[i]-'a']=i+1,y[a[i]-'a']=i+1,z[b[i]-'a']=i+1;
    for(i=0;i<26;i++)
      {
       for(j=i+1;j<26;j++)
         if(x[i][j]>0 && x[j][i]>0)
           break;
       if(j<26)
         break;
      }
    if(i<26)
      printf("%d\n%d %d\n",p-2,x[i][j],x[j][i]);
    else
      {
       for(i=0;i<26;i++)
         if(y[i]>0 && z[i]>0)
           break;
       if(i<26)
         printf("%d\n%d %d\n",p-1,y[i],z[i]);
       else
         printf("%d\n%d %d\n",p,-1,-1);
      }
    return 0;
}