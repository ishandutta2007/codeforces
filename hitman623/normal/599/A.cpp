#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    long d1,d2,d3,ans;
    cin>>d1>>d2>>d3;
    ans=d1+d2+d3;
    if(2*d1+2*d3<ans) ans=2*d1+2*d3;
    if(2*d2+2*d3<ans) ans=2*d2+2*d3;
    if(2*d2+2*d1<ans) ans=2*d2+2*d1;
    cout<<ans;
    return 0;
}