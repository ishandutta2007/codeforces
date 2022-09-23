#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b[100001],d[100001],i,j,cnt=0;
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>b[i];
        d[i]=b[i];
    }
    sort( d+1, d+a+1 );
    for( i=1; i<=a; i++ ){
        if( d[i]!=b[i] ){
            cnt++;
        }
        if( cnt>2 ){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}