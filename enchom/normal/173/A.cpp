#include <iostream>
using namespace std;

typedef long long Int;

int main()
{
    Int dots1=0,dots2=0;
    Int times=0;
    Int multi;
    Int i,j;
    string a,b;
    Int uk1,uk2;
    Int n;
    Int aL,bL;
    
    cin>>n;
    cin>>a;
    cin>>b;
    
    aL=a.length();
    bL=b.length();
    
    uk1=0;
    uk2=0;
    if ( a[uk1]==b[uk2] )
    {
        ///Do nothing
    }
    else if ( a[uk1]=='S' && b[uk2]=='P' )
    {
        dots1++;
    }
    else if ( a[uk1]=='P' && b[uk2]=='S' )
    {
        dots2++;
    }
    else if ( a[uk1]=='R' && b[uk2]=='P' )
    {
        dots2++;
    }
    else if ( a[uk1]=='P' && b[uk2]=='R' )
    {
        dots1++;
    }
    else if ( a[uk1]=='S' && b[uk2]=='R' )
    {
        dots2++;
    }
    else if ( a[uk1]=='R' && b[uk2]=='S' )
    {
        dots1++;
    }
    uk1++;
    uk2++;
    if (uk1==aL)
    uk1-=aL;
    if (uk2==bL)
    uk2-=bL;
    
    times=1;
    
    while ( (uk1!=0 || uk2!=0) && times<n )
    {
        times++;
        if ( a[uk1]==b[uk2] )
        {
            ///Do nothing
        }
        else if ( a[uk1]=='S' && b[uk2]=='P' )
        {
            dots1++;
        }
        else if ( a[uk1]=='P' && b[uk2]=='S' )
        {
            dots2++;
        }
        else if ( a[uk1]=='R' && b[uk2]=='P' )
        {
            dots2++;
        }
        else if ( a[uk1]=='P' && b[uk2]=='R' )
        {
            dots1++;
        }
        else if ( a[uk1]=='S' && b[uk2]=='R' )
        {
            dots2++;
        }
        else if ( a[uk1]=='R' && b[uk2]=='S' )
        {
            dots1++;
        }
        uk1++;
        uk2++;
        if (uk1==aL)
        uk1-=aL;
        if (uk2==bL)
        uk2-=bL;
    }
    if (times==n)
    {
        cout<<dots2<<" "<<dots1<<endl;
        return 0;
    }
    
    n=n-times;
    multi=n/times;
    dots1=dots1+dots1*multi;
    dots2=dots2+dots2*multi;
    n=n%times;
        
    times=0;
    uk1=0;
    uk2=0;
    while ( times<n )
    {
        times++;
        if ( a[uk1]==b[uk2] )
        {
            ///Do nothing
        }
        else if ( a[uk1]=='S' && b[uk2]=='P' )
        {
            dots1++;
        }
        else if ( a[uk1]=='P' && b[uk2]=='S' )
        {
            dots2++;
        }
        else if ( a[uk1]=='R' && b[uk2]=='P' )
        {
            dots2++;
        }
        else if ( a[uk1]=='P' && b[uk2]=='R' )
        {
            dots1++;
        }
        else if ( a[uk1]=='S' && b[uk2]=='R' )
        {
            dots2++;
        }
        else if ( a[uk1]=='R' && b[uk2]=='S' )
        {
            dots1++;
        }
        uk1++;
        uk2++;
        if (uk1==aL)
        uk1-=aL;
        if (uk2==bL)
        uk2-=bL;
    }
    cout<<dots2<<" "<<dots1<<endl;
    return 0;
}