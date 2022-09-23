#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c[1001],i;
    cin>>a>>b;
    for( i=1; i<=a; i++ ){
        cin>>c[i];
    }
    sort( c+1, c+a+1 );
    for( i=1; i<a; i++ ){
        b-=c[i];
        if( b<0 ){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}