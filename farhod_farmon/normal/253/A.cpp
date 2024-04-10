#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen( "input.txt", "r" , stdin );
    freopen( "output.txt", "w" , stdout );
    int a,b,i;
    cin>>a>>b;
    while( a>0 && b>0 ){
        if( b>a ){
            cout<<"GB";
        }
        else{
            cout<<"BG";
        }
        a--;
        b--;
    }
    while( a>0 ){
        cout<<"B";
        a--;
    }
    while( b>0 ){
        cout<<"G";
        b--;
    }
    return 0;
}