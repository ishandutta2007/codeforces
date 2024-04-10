#include <bits/stdc++.h>
#define long long long
using namespace std;

int main()
{
    string a;
    cin>>a;
    long n=a.length(),i,ae=0,ao=0,be=0,bo=0;
    for(i=0;i<n;++i)
    if(i%2)
    {
        if(a[i]=='a') ao++;
        else bo++;
    }
    else
    {
        if(a[i]=='a') ae++;
        else be++;
    }
    cout<<ao*ae+bo*be<<" "<<(ao*(ao+1))/2+(bo*(bo+1))/2+(ae*(ae+1))/2+(be*(be+1))/2<<endl;
    return 0;
}