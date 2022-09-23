#include <bits/stdc++.h>
using namespace std;
int main()
{
    bool b1=false;
    vector < int > v,v1;
    int a,b,h,i,j;
    string s;
    cin>>a>>b;
    char c[a+1][b+1];
    for( i=1; i<=a; i++ ){
        for( j=1; j<=b; j++ ){
            cin>>c[i][j];
        }
    }
    for( i=1; i<=a; i++ ){
        for( j=1; j<=b; j++ ){
            for( h=j+1; h<=b; h++ ){
                if( c[i][h]==c[i][j] ){
                    b1=true;
                    v.push_back( i );
                    v1.push_back( h );
                }
            }
            for( h=j-1; h>=1; h-- ){
                if( c[i][h]==c[i][j] ){
                    b1=true;
                    v.push_back( i );
                    v1.push_back( h );
                }
            }
            for( h=i+1; h<=a; h++ ){
                if( c[h][j]==c[i][j] ){
                    b1=true;
                    v.push_back( h );
                    v1.push_back( j );
                }
            }
            for( h=i-1; h>=1; h-- ){
                if( c[h][j]==c[i][j] ){
                    b1=true;
                    v.push_back( h );
                    v1.push_back( j );
                }
            }
        }
    }
    for( i=0; i<v.size(); i++ ){
        c[v[i]][v1[i]]='.';
    }
    for( i=1; i<=a; i++ ){
        for( j=1; j<=b; j++ ){
            if( c[i][j]!='.' ){
                s+=c[i][j];
            }
        }
    }
    cout<<s;
    return 0;
}