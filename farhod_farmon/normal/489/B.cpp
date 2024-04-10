#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c[101],d[101],i,j,cnt=0;
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>c[i];
    }
    cin>>b;
    for( i=1; i<=b; i++ ){
        cin>>d[i];
    }
    sort( c+1, c+a+1 );
    sort( d+1, d+b+1 );
    for( i=1; i<=a; i++ ){
        for( j=1; j<=b; j++ ){
            if( abs( c[i]-d[j] )==1 || abs( c[i]-d[j]==0 ) ){
                cnt++;
                c[i]=9999123131;
                d[j]=1238712312;
                break;
            }
        }
    }
    cout<<cnt;
    return 0;
}