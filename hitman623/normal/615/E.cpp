#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long m,n,x=0,y=0,b,dx[6]={-1,-2,-1,1,2,1},dy[6]={2,0,-2,-2,0,2},j=0;
    cin>>m;
    n=(sqrt((4*m)/3+1)-1)/2;
    m=m-(n*(n+1))*3;
    x=2*n;
    if(m) x+=2;
    while(m>0)
    {
        b=min(n+1,m);
        m-=b;
        x+=b*dx[j];
        y+=b*dy[j];
        j++;
    }
    cout<<x<<" "<<y;
    return 0;
}