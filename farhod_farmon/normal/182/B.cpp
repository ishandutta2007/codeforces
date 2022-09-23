#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c[100001],d,i,cnt=0;
    cin>>b>>a;
    d=b;
    for( i=1; i<=a; i++ ){
        cin>>c[i];
    }
    for( i=1; i<=a; i++ ){
        if( d-c[i]==0 ){
            continue;
        }
        if( i<a ){
            cnt+=d-c[i];
        }
        d=b;
    }
    cout<<cnt;
    return 0;
}