#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b[101],c,d[101]={},ans=99999999,i,j;
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>b[i];
    }
    for( i=1; i<=a; i++ ){
        for( j=1; j<=b[i]; j++ ){
            cin>>c;
            d[i]+=c*5;
        }
        d[i]+=b[i]*15;
        ans=min( ans, d[i] );
    }
    cout<<ans;
    return 0;
}