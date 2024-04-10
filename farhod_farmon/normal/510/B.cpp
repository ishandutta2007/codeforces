#include <iostream>
#include <algorithm>
using namespace std;
char c[55][55];
int a,b,i,j,d[51][51]={},h,k;
string ans="No";

void rec( int x, int y, int z )
{
    if( x>a || x<1 || y>b || y<1 || d[x][y]==1 ){return;}
    d[x][y]=1;
    if( z!=2 && c[x][y+1]==c[i][j] ){rec( x, y+1, 1 );}
    if( z!=1 && c[x][y-1]==c[i][j] ){rec( x, y-1, 2 );}
    if( z!=4 && c[x+1][y]==c[i][j] ){rec( x+1, y, 3 );}
    if( z!=3 && c[x-1][y]==c[i][j] ){rec( x-1, y, 4 );}
    if( x==i && y==j ){ans="Yes";}
}

int main()
{
    cin>>a>>b;
    for( i=1; i<=a; i++ ){
        for( j=1; j<=b; j++ ){
            cin>>c[i][j];
        }
    }
    for( i=1; i<=a; i++ ){
        for( j=1; j<=b; j++ ){
            if( c[i][j+1]==c[i][j] ){rec( i, j+1, 1 );}
            if( c[i][j-1]==c[i][j] && d[i][j-1]==0 ){rec( i, j-1, 2 );}
            if( c[i+1][j]==c[i][j] && d[i+1][j]==0 ){rec( i+1, j, 3 );}
            if( c[i-1][j]==c[i][j] && d[i-1][j]==0 ){rec( i-1, j, 4 );}
            for( h=1; h<=a; h++ ){
                for( k=1; k<=b; k++ ){
                    d[h][k]=0;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}