#include <iostream>

using namespace std;

int main()
{
    long int len,i,n,ar[100000],f=0;
    cin>>n;
    for(i=0;i<n;++i)
        cin>>ar[i];
        if(n>=2) len=2;
        else len=1;
    for(i=2;i<n;++i)
    {
        if(ar[i]==ar[i-1]+ar[i-2]) ++len;
        else {if(f<len)f=len;len=2;}
    }
    if(f>len)
    cout<<f;
    else cout<<len;
    return 0;
}