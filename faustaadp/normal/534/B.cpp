#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll v1,v2,n,d,i,a1[10101010],a2[10101010],hs;
int main()
{
    cin>>v1>>v2;
    cin>>n>>d;
    for(i=1;i<=n;i++)
    {
        a1[i]=v1;
        v1=v1+d;
    }
    for(i=n;i>=1;i--)
    {
        a2[i]=v2;
        v2=v2+d;
    }
    for(i=1;i<=n;i++)
    {
        hs=hs+min(a1[i],a2[i]);
    }
    cout<<hs<<"\n";
}