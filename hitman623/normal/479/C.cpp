#include <iostream>
using namespace std;
int main()
{
    long n,m,a[5000],b[5000],j,i,cur=0,l;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i]>>b[i];
    for(i=0;i<n;++i)
    {
        for(j=0;j<n-i-1;++j)
        {
          if(a[j]>a[j+1])
          {
              swap(a[j],a[j+1]);
              swap(b[j],b[j+1]);
          }
        }
    }
    cur=b[0];
    for(i=1;i<n;++i)
    {
        if(b[i]<cur && a[i-1]!=a[i])
        {
            cur=a[i];
        }
        else if(a[i-1]!=a[i]) cur=b[i];
        else if(b[i]>cur) cur=b[i];
    }
    cout<<cur;
    return 0;
}