#include <iostream>
#include<iomanip>
using namespace std;
 long long n,p,l[200000],r[200000],i,j;
    long double s=0,q=0,c,d,e,f;
int main()
{   cout<<setprecision(30);
    cin>>n>>p;
    for(i=0;i<n;i++)
    {
        cin>>l[i]>>r[i];
    }
    for(i=0;i<n;++i)
    {
        c=r[i]/p-l[i]/p+!(l[i]%p);
        d=r[i]-l[i]+1-c;
        e=r[(i+1)%n]/p-l[(i+1)%n]/p+!(l[(i+1)%n]%p);
        f=r[(i+1)%n]-l[(i+1)%n]+1-e;
        s+=(c)/(c+d);
        s+=(d*e)/((c+d)*(e+f));
    }
    cout<<2000.0*s;
    return 0;
}