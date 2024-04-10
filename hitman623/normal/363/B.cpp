#include <iostream>

using namespace std;

int main()
{
    int s,f=1,p=0,i,j,n,k,a[150001]={0};
    cin>>n>>k;
    a[0]=0;
    for(i=1;i<=n;++i)
    {
       cin>>a[i];
      p+=a[i];
      a[i]=p;
    }
    for(i=1;i<n-k+1;++i)
       {
           if(a[f+k-1]-a[f-1]>a[i+k]-a[i])
            f=i+1;
       }
    cout<<f;
    return 0;
}