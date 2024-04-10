#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,cnt=0,maxn=0,minn=0;
    cin>>a>>b;
    c=a;
    d=b;
    if( a==0 && b>0 ){
        cout<<"Impossible";
        return 0;
    }
    while( c>1 && d>0 ){
        c--;
        d--;
        minn++;
    }
    minn+=d;
    if( d==0 ){
        minn+=c;
    }
    maxn+=b+( a-1 );
    if( b==0 ){
        maxn++;
    }
    cout<<minn<<" "<<maxn;
    return 0;
}