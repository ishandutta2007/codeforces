#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b[1111],c[1111],i,d,f,cnt=0;
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>b[i];
        c[i]=b[i];
    }
    sort( c+1, c+a+1 );
    if( c[a]-c[1]==0 ){
        cout<<"Exemplary pages.";
        return 0;
    }
    for( i=1; i<=a; i++ ){
        if( b[i]==c[1] ){
            d=i;
        }
        if( b[i]==c[a] ){
            f=i;
        }
    }
    cnt=c[a]-c[1];
    cnt/=2;
    c[a]-=cnt;
    c[1]+=cnt;
    sort( c+1, c+a+1 );
    if( c[a]-c[1]!=0 ){
        cout<<"Unrecoverable configuration.";
        return 0;
    }
    if( b[f]>b[d] ){
        cout<<cnt<<" ml. from cup #"<<d<<" to cup #"<<f<<".";
    }
    else{
        cout<<cnt<<" ml. from cup #"<<f<<" to cup #"<<d<<".";
    }
    return 0;
}