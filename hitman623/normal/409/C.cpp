#include <bits/stdc++.h>
using namespace std;

int main()
{
    long a,b,c,d,e,x[5],ans=100000,i;
    cin>>a>>b>>c>>d>>e;
    x[0]=a;
    x[1]=b;
    x[2]=c/2;
    x[3]=d/7;
    x[4]=e/4;
    for(i=0;i<5;i++)
    ans=min(ans,x[i]);
    cout<<ans;
    return 0;
}