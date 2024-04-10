#include <iostream>

using namespace std;

int main()
{
    long long i,n,a[100000],s=0,b=1000000007;
    cin>>n;
    for(i=0;i<n;++i)
        { cin>>a[i];
             if(a[i]%2==0) s+=a[i];
              else {s+=a[i];if(a[i]<b)b=a[i];}
        }
        if(s%2==0) cout<<s;
        else cout<<s-b;
    return 0;
}