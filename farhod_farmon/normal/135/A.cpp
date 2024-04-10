#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b[100001],i,j,maxn=0;
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>b[i];
        maxn=max( maxn, b[i] );
    }
    for( i=1; i<=a; i++ ){
        if( maxn==1 ){
            b[1]=2;
            break;
        }
        else if( b[i]==maxn ){
            b[i]=1;
            break;
        }
    }
    sort( b+1, b+a+1 );
    for( i=1; i<=a; i++ ){
        cout<<b[i]<<" ";
    }
    return 0;
}