#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c[101],d[101],i,j;
    cin>>a>>b;
    for( i=1; i<=a; i++ ){
        cin>>c[i]>>d[i];
    }
    for( i=1; i<=a; i++ ){
        if( c[i]==7-b || c[i]==b || d[i]==7-b || d[i]==b ){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}