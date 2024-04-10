#include <iostream>
using namespace std;
int main()
{
    int a,i,g=0,d,j;
    string s[10];
    cin>>a;
    if( a==0 ){
        cout<<"O-|-OOOO";
    }
    d=a;
    while( d>0 ){
        d/=10;
        g++;
    }
    for( i=1; i<=g; i++ ){
        d=a%10;
        if( d>4 ){
            s[i]+="-O|";
            d-=5;
        }
        else{
            s[i]+="O-|";
        }
        for( j=1; j<=d; j++ ){
            s[i]+="O";
        }
        s[i]+="-";
        for( j=1; j<=5-d-1; j++ ){
            s[i]+="O";
        }
        a/=10;
    }
    for( i=1; i<=g; i++ ){
        cout<<s[i]<<endl;
    }
    return 0;
}