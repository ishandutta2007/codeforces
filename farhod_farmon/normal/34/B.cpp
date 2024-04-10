#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c[101],i,ans=0;
    cin>>a>>b;
    for( i=1; i<=a; i++ ){
        cin>>c[i];
    }
    sort( c+1, c+a+1 );
    for( i=1; i<=b; i++ ){
        if( c[i]>0 ){
            continue;
        }
        ans+=c[i];
    }
    cout<<abs( ans );
    return 0;
}