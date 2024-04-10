#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int a=0,b=0,i,j;
    cin>>s;
    a=a*10+( s[0]-48 );
    a=a*10+( s[1]-48 );
    b=b*10+( s[3]-48 );
    b=b*10+( s[4]-48 );
    for( i=a; i<=a; i++ ){
        for( j=b+1; j<60; j++ ){
            if( i%10==j/10 && i/10==j%10 ){
                if( i<9 ){
                    cout<<"0"<<i<<":";
                }
                else{
                    cout<<i<<":";
                }
                if( j<9 ){
                    cout<<"0"<<j;
                }
                else{
                    cout<<j;
                }
                return 0;
            }
        }
    }
    a++;
    for( i=a; i<24; i++ ){
        for( j=1; j<60; j++ ){
            if( i%10==j/10 && i/10==j%10 ){
                if( i<9 ){
                    cout<<"0"<<i<<":";
                }
                else{
                    cout<<i<<":";
                }
                if( j<9 ){
                    cout<<"0"<<j;
                }
                else{
                    cout<<j;
                }
                return 0;
            }
        }
    }
    cout<<"00:00";
    return 0;
}