#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b[5][5],i,j,h,k;
    cin>>a;
    for( i=1; i<=4; i++ ){
        for( j=1; j<=4; j++ ){
            cin>>b[i][j];
        }
    }
    for( i=1; i<=4; i++ ){
        for( j=1; j<=2; j++ ){
            if( j==1 ){
                if( b[i][j]+b[i][j+2]<=a ){
                    a-=b[i][j];
                    cout<<i<<" "<<b[i][j]<<" "<<a;
                    return 0;
                }
                else if( b[i][j]+b[i][j+3]<=a ){
                    a-=b[i][j];
                    cout<<i<<" "<<b[i][j]<<" "<<a;
                    return 0;
                }
            }
            if( j==2 ){
                if( b[i][j]+b[i][j+1]<=a ){
                    a-=b[i][j];
                    cout<<i<<" "<<b[i][j]<<" "<<a;
                    return 0;
                }
                else if( b[i][j]+b[i][j+2]<=a ){
                    a-=b[i][j];
                    cout<<i<<" "<<b[i][j]<<" "<<a;
                    return 0;
                }
            }
        }
    }
    cout<<-1;
    return 0;
}