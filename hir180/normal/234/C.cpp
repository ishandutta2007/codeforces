#include<iostream>
#include<fstream>
#include <cstdio>
using namespace std;
int main()
{
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
int n,i,a[100005],k=0,p=0,m;
scanf("%d",&n);
m=n;
for(i=1;i<=n;i++)
{scanf("%d",&a[i]);
if(a[i]<=0) k++;
}
for(i=1;i<n;i++)
{
if(a[i]>=0) p++;
if(a[i]<=0) k--;
m=min(m,p+k);
}
printf("%d",m);
return 0;
}