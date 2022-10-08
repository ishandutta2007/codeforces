#include <iostream>
#include <stdio.h>
using namespace std;

int MIN(int a,int b)
{
    if (a<b)
    return a;
    else
    return b;
}

int main()
{
    int a,b,c,d,e;
    int ans=999999;
    
    cin>>a>>b>>c>>d>>e;
    
    ans=MIN(ans,a);
    ans=MIN(ans,b);
    ans=MIN(ans,c/2);
    ans=MIN(ans,d/7);
    ans=MIN(ans,e/4);
    
    cout<<ans<<endl;
    
    return 0;
}