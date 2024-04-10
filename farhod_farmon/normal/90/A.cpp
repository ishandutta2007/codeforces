#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    a=((a+1)/2-1)*3+30;
    b=((b+1)/2-1)*3+31;
    c=((c+1)/2-1)*3+32;
    cout<<max( a, max( b, c ) );
    return 0;
}