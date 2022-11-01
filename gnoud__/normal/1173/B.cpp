#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n;
    m=n/2+1;
    cout<<m<<"\n";
    int i=1,j=1;
    while(n--)
    {
        cout<<i<<" "<<j<<"\n";
        ++j;
        if(j==m+1) i=m,j=2;
    }
}