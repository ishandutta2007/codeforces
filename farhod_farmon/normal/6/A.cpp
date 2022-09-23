#include <iostream>
using namespace std;
int main()
{
    int d[5],a,b,c;
    cin>>d[1]>>d[2]>>d[3]>>d[4];
    for( a=1; a<=4; a++ ){
        for( b=1; b<=4; b++ ){
            for( c=1; c<=4; c++ ){
                if( a==b || a==c || b==c ){
                    continue;
                }
                if( d[a]+d[b]>d[c] && d[a]+d[c]>d[b] && d[b]+d[c]>d[a] ){
                    cout<<"TRIANGLE";
                    return 0;
                }
            }
        }
    }
    for( a=1; a<=4; a++ ){
        for( b=1; b<=4; b++ ){
            for( c=1; c<=4; c++ ){
                if( a==b || a==c || b==c ){
                    continue;
                }
                if( d[a]+d[b]>=d[c] && d[a]+d[c]>=d[b] && d[b]+d[c]>=d[a] ){
                    cout<<"SEGMENT";
                    return 0;
                }
            }
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}