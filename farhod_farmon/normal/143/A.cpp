#include <bits/stdc++.h>
using namespace std;
int main()
{
    int r1,r2,c1,c2,d1,d2,i,j,h,k;
    cin>>r1>>r2>>c1>>c2>>d1>>d2;
    for( i=1; i<=9; i++ ){
        for( j=1; j<=9; j++ ){
            for( h=1; h<=9; h++ ){
                for( k=1; k<=9; k++ ){
                    if( i+j==r1 && h+k==r2 && i+h==c1 && j+k==c2 && i+k==d1 && j+h==d2 && i!=j && i!=h && i!=k && j!=h && j!=k && h!=k ){
                        cout<<i<<" "<<j<<"\n"<<h<<" "<<k;
                        return 0;
                    }
                }
            }
        }
    }
    cout<<-1;
    return 0;
}