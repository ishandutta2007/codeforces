#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a,b,x,y,i,j;
    char c[51][51];
    cin>>a>>b;
    for( i=1; i<=a; i++ ){
        for( j=1; j<=b; j++ ){
            c[i][j]='.';
        }
    }
    x=2;
    y=b;
    for( i=1; i<=a; i+=2 ){
        for( j=1; j<=b; j++ ){
            c[i][j]='#';
        }
        if( i+2<=a ){
            if( y==b ){
                c[x][y]='#';
                y=1;
                x+=2;
            }
            else{
                c[x][y]='#';
                y=b;
                x+=2;
            }
        }
    }
    for( i=1; i<=a; i++ ){
        for( j=1; j<=b; j++ ){
            cout<<c[i][j];
        }
        cout<<endl;
    }
    return 0;
}