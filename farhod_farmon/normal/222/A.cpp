#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c[100001],d,i,j,cnt=0;
    cin>>a>>b;
    for( i=1; i<=a; i++ ){
        cin>>c[i];
    }
    d=c[b];
    for( i=b; i<a; i++ ){
        if( c[i]!=c[i+1] ){
            cout<<-1;
            return 0;
        }
    }
    for( i=a; i>=1; i-- ){
        if( c[i]!=d ){
            cout<<i;
            return 0;
        }
    }
    cout<<0;
    return 0;
}