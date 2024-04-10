#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b[100001],c[100001],i,cnt=0;
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>b[i];
        c[i]=b[i];
    }
    sort( c+1, c+a+1 );
    if( c[1]==c[2] ){
        cout<<"Still Rozdil";
    }
    else{
        for( i=1; i<=a; i++ ){
            if( c[1]==b[i] ){
                cout<<i;
                return 0;
            }
        }
    }
    return 0;
}