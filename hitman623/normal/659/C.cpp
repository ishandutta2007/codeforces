#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int bs(long a[],long b,long n)
{  long beg=0,last=n-1,mid=(beg+last)/2;
 while(last>=beg)
 { if(b<a[mid])
   {
   last=mid-1;
   mid=(beg+last)/2;
      }
   else if(b>a[mid])
   {
   beg=mid+1;
   mid=(beg+last)/2;
      }
   else return 1;
  }
 return 0;
}
int main()
{
  long n,m,a[100000],i,b[100000],l=0;
  long long s=0;
  cin>>n>>m;
  for(i=0;i<n;++i)
    cin>>a[i];
  sort(a,a+n);
  for(i=1;i<=1000000000;++i)
  {
      if(bs(a,i,n)==0) {b[l++]=i;s+=i;}
      if(s>m) break;
  }
  cout<<l-1<<endl;
  for(i=0;i<l-1;i++)
    cout<<b[i]<<" ";
  return 0;
}