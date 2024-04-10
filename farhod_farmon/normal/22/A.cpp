#include <bits/stdc++.h>

#define fi first
#define se second

using namespace std;
int main()
{
    int a,b[101],i;
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>b[i];
    }
    sort( b+1, b+a+1 );
    for( i=1; i<a; i++ ){
        if( b[i]!=b[i+1] ){
            cout<<b[i+1];
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}