#include<iostream>
#include<algorithm>
#include<cstdio>
#define fr(a,b,c) for (a=b;a<=c;a++)
#define oo 1000000000
using namespace std;

int m,n,a[100100],b[100100],d[100100],c[100100];

int bs(int val)
{
    int l=0,r=m,mid,i;
    while (l<=r)
    {
       mid=(l+r)/2; 
       if (b[mid]==val) return mid;
       if (b[mid]>val) r=mid-1;
       else l=mid+1;
    }
    fr(i,-1,1)
      if (mid-i>=0 && mid-i<=m && b[mid-i]<val) return mid-i;
}

int main()
{
    int i,j,k,x;
    scanf("%d%d%d%d",&n,&m,&i,&j);
    if (!m)
    {
       cout << n << endl;
       return 0;    
    }
    fr(i,1,n) scanf("%d",&a[i]);
    fr(i,1,m) scanf("%d",&b[i]);
    b[0]=-oo; 
    fr(i,1,n) 
    {
       int kt=0;       
       j=bs(a[i]); 
       if (j<m && b[j+1]-a[i]<a[i]-b[j]) j++; 
       else
            if (j<m && b[j+1]-a[i]==a[i]-b[j]) kt=1;
       if (!kt)
       {
         k=d[j];
         if (!k) d[j]=i,c[i]=j;
         else
         {
             if (a[i]-b[j]<abs(a[k]-b[j])) d[j]=i,c[i]=j,c[k]=0;
             else
             {
                if (a[i]-b[j]==abs(a[k]-b[j])) d[j]=i,c[i]=j; 
             }
         }
       }
       else
       {
           k=d[j];
           if (!k) d[j]=i,c[i]=j;
           else
           {
             if (a[i]-b[j]==abs(a[k]-b[j])) d[j]=i,c[i]=j; 
           }
           if (!c[i]) d[j+1]=i,c[i]=j+1;
       }
    }
    int re=0;
    fr(i,1,n)
      if (!c[i]) re++;
    cout << re << endl;
    //system("pause");
    return 0;
}