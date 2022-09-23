#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c[101],d[101]={},i,j;
    cin>>a>>b;
    for( i=1; i<=b; i++ ){
        cin>>c[i];
    }
    for( i=1; i<=b; i++ ){
        for( j=c[i]; j<=a; j++ ){
            if( d[j]==0 ){
                d[j]=c[i];
            }
        }
    }
    for( i=1; i<=a; i++ ){
        cout<<d[i]<<" ";
    }
    return 0;
}