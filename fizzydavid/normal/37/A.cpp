#include<iostream>
#include<cstdlib>
using namespace std;
int n,a[1005],b[1005];
int main()
{
    int i,sum=0,ma=0;
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i],b[a[i]]++;
    for(i=1;i<=1000;i++)
    {
        if(b[i]>0)sum++;
        if(ma<b[i])ma=b[i];
    }
    cout<<ma<<" "<<sum;
    return 0;
}