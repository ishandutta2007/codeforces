#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int main()
{
    long n,m,s=0,r=0;
    cin>>n>>m;
    s=n;
    while(n/m>0)
    {
        s+=n/m;
        n=n/m+n%m;
    }
    cout<<s;
    return 0;
}