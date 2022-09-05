#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<stdio.h>
using namespace std;
long long n,h,a[100005],b[100005];
int main()
{
    long long i,min1,min2,max1,max2,mino,mano;
    cin>>n>>h;
    for(i=0;i<n;i++)cin>>a[i],b[i]=a[i];
    sort(b,b+n);
    min1=b[0];min2=b[1];max1=b[n-2];max2=b[n-1];
    cout<<min(max1+max2-min1-min2,max(max1+max2,min1+max2+h)-min(min1+min2+h,min2+b[2]))<<endl;
    if(max1+max2-min1-min2>max(max1+max2,min1+max2+h)-min(min1+min2+h,min2+b[2]))
    {
        for(i=0;i<n;i++)if(a[i]==min1)cout<<"1"<<" ",min1=-1;else cout<<"2"<<" ";
    }
    else 
    {
         for(i=1;i<=n;i++)cout<<"2"<<" ";
    }
    return 0;
}