#include <bits/stdc++.h>

using namespace std;
long gcd(long a,long b)
{
    if(a==0) return b;
    if(a<b) return(gcd(b%a,a));
    else return (gcd(a%b,b));
}
int main()
{
    long n,a[2000],i,k=0;
    cin>>n;
    for(i=0;i<n;++i)
        cin>>a[i];
    for(i=0;i<n-1;++i)
        {
            if(gcd(a[i],a[i+1])!=1)
            {
                k++;
            }
        }
        cout<<k<<endl;
   for(i=0;i<n-1;++i)
        {
            cout<<a[i]<<" ";
            if(gcd(a[i],a[i+1])!=1)
            {
                cout<<1<<" ";
            }
        }
        cout<<a[n-1];
    return 0;
}