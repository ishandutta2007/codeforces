#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<string.h>
using namespace std;
long long n,m,a,b,f[5001],s[5001],q=1000000007;
int main()
{
    int i;
    cin>>n>>a>>b>>m;
    if(a<b)
      {
       n=b-1;
       f[b-a]=1;
       for(i=b-a;i<=n;i++)
         s[i]=1;
      }
    else
      {
       n=n-b;
       f[a-b]=1;
       for(i=a-b;i<=n;i++)
         s[i]=1;
      }
    while(m>0)
      {
       m--;
       for(i=1;i<=n;i++)
         f[i]=(s[n]-s[i/2]-f[i])%q;
       for(i=1;i<=n;i++)
         s[i]=(s[i-1]+f[i])%q;
      }
    cout<<(s[n]+q)%q;
    return 0;
}