#include <iostream>
using namespace std;
typedef long long Int;


int main()
{
    Int l,r,n,k;
    Int powerk;
    Int linesofcode;
    Int minv=-1,v;
    cin>>n>>k;

    l=1;
    r=n;
    while(l<=r)
    {
        v=(l+r)/2;
        
        powerk=1;
        linesofcode=0;
        while( v/powerk>0 )
        {
            linesofcode=linesofcode+v/powerk;
            powerk=powerk*k;
        }
        if (linesofcode>=n)
        {
            r=v-1;
            minv=v;
        }
        else
        l=v+1;
    }
    cout<<minv<<endl;
    return 0;
}