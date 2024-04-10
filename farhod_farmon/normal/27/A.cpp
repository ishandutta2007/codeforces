#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b[3001],i,cnt=1;
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>b[i];
    }
    sort( b+1, b+a+1 );
    for( i=1; i<=a; i++ ){
        if( b[i]==cnt ){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}