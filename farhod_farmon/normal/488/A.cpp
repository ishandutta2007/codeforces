#include <iostream>
using namespace std;

int abs( int a )
{
    if(a<0){
        a=-a;
    }
    return a;
}

bool sum ( int a )
{
    int cnt=0;
    while( a>0 ){
        if(a%10==8){
            cnt++;
        }
        a/=10;
    }
    return cnt;
}

int main()
{
    int a,b,cnt,i;
    cin>>a;
    for( i=a; ; i++ ){
        if( sum(abs(i))>0 && i-a>0 ){
            cout<<i-a;
            return 0;
        }
    }
    return 0;
}