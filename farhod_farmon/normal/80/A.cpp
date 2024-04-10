#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,i,d=0;
    cin>>a>>b;
    while( a!=b ){
        a++;
        for( i=1; i<=a; i++ ){
            if( a%i==0 ){
                d++;
            }
        }
        if( d==2 ){
            if( b==a ){
                cout<<"YES";
                return 0;
            }
            else{
                cout<<"NO";
                return 0;
            }
        }
        d=0;
    }
    cout<<"NO";
    return 0;
}