#include<iostream>
#include<algorithm>
#include<cstdio>
#define fr(a,b,c) for (a=b;a<=c;a++)
#define frr(a,b,c) for (a=b;a>=c;a--)
using namespace std;

int n,a[1000100],re=0,b[1000100];

int find(int x)
{
   int l=0,r=re,i,m;
   while (l<=r)
   {
       m=(l+r)/2;
       if (b[m]<x) r=m-1;
       else l=m+1;  
   } 
   frr(i,m+1,m-1)
    if (i>=0 && i<=re && b[i]>=x) return i;
}

int main()
{
    int i,x,t,j;
    scanf("%d",&n);
    fr(i,1,n)
    {
       scanf("%d",&x);
       a[x]=i;
    }
    b[0]=n;
    fr(i,1,n)
    {
       scanf("%d",&x);
       if (a[x]<=b[re]) b[++re]=a[x];
       else 
       {
           t=find(a[x])+1;
           if (b[t]<a[x]) b[t]=a[x];
       }
    }
    cout << re << endl;
//    system("pause");
    return 0;
}