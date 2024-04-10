#include <iostream>
using namespace std;

typedef long long Int;

int main()
{
    Int a,b,c;
    Int l,r,mid;
    Int t,mint=999999999999999;
    cin>>a>>b>>c;
    l=0;
    r=((a*c)/b)+1;
    while (l<=r)
    {
        mid=(l+r)/2;
        t=c+mid;
        if ( t*b>=(t-mid)*a )
        {
            if (mint>mid)
            mint=mid;
            
            r=mid-1;
        }
        else
        l=mid+1;
    }
    cout<<mint<<endl;
    return 0;
}