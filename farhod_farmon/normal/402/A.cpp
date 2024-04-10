#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d,i,cnt=0,f;
    cin>>a>>b>>c>>d;
    while( b>0 ){
        cnt++;
        if( c>0 ){
            if( c-( a-1 )>0 ){
                c-=( a-1 );
                b-=d*a;
            }
            else{
                b-=d*( c+1 );
                c=0;
            }
        }
        else{
            b-=d;
        }
    }
    cout<<cnt;
    return 0;
}