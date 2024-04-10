#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int main()
{
    long n,m1,m2,m3,mx1,mx2,mx3,a,b,c;
    cin>>n>>m1>>mx1>>m2>>mx2>>m3>>mx3;
    a=min(mx1,n-m2-m3);
    b=min(mx2,n-a-m3);
    c=n-a-b;
    cout<<a<<" "<<b<<" "<<c;
    return 0;
}