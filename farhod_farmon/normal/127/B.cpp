#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b[101],cnt=0,i;
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>b[i];
    }  
    sort( b+1, b+a+1 );
    for( i=1; i<=a; i++ ){
        if( b[i]==b[i+1] ){
            cnt++;
            i++;
        }
    } 
    cout<<cnt/2;
    return 0;
}