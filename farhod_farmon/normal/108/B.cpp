#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b[100001],i;
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>b[i];
    }
    sort( b+1, b+a+1 );
    for( i=1; i<a; i++ ){
        if( b[i]*2>b[i+1] && b[i]!=b[i+1] ){
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}