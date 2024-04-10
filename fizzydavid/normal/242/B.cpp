#include<iostream>
#include<cstdlib>
#include<set>
using namespace std;
int n;
int main()
{
    int i;
    long long x,y,mi=1000000000,ma=0,le=-1,No=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x>>y;
        if(mi>x)mi=x;
        if(ma<y)ma=y;
        if((y-x)>le){le=y-x;No=i;}
    }
    
    if(mi+le==ma)cout<<No;
    else cout<<"-1";
    return 0;
}