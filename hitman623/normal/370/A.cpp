#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int a,b,c,d,r=0,bi=2,k=0,p,q;
    cin>>a>>b>>c>>d;
    p=fabs(c-a);
    q=fabs(d-b);
    if(p>0) r++;
    if(q>0) r++;
    if(p==q) bi=1;
    else if((p+q)%2) bi=0;
    k=p>q?p:q;
    cout<<r<<" "<<bi<<" "<<k;
    return 0;
}