#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b=2,i,d=2;
    cin>>a;
    for( i=1; i<a; i++ ){
        if( d%a==0 ){
            cout<<a<<" ";
        }
        else{
            cout<<d%a<<" ";
        }
        d+=b;
        b++;
    }
    return 0;
}