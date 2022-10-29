#include <iostream>

using namespace std;

int main()
{
    int n,f=2,i=0; long a[100000][2];
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>a[i][0]>>a[i][1];
    if(i>1 && i<n)
   {
       if(a[i-1][0]-a[i-2][0]>a[i-1][1] )
       ++f;
       else if ( a[i][0]-a[i-1][0]>a[i-1][1])
      {
     a[i-1][0]+=a[i-1][1];
      ++f;
      }
   }
    }
    if(n==1) cout<<1;
    else
    cout<<f;
    return 0;
}