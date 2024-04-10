#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c[2001],d[2001],i,j,h,cnt=0,g=0,z[2001],x[2001];
    vector < int > v[2001];
    bool b3=true,b4=true;
    cin>>a>>b;
    for( i=1; i<=b; i++ ){
        cin>>c[i]>>d[i];
    }
    for( i=1; i<=1200; i++ ){
        z[i]=i;
    }
    for( i=1; i<=b; i++ ){
        for( j=1; j<=a/3; j++ ){
            for( h=0; h<v[j].size(); h++ ){
                if( v[j][h]==c[i] ){
                    b3=false;
                }
                if( v[j][h]==d[i] ){
                    b4=false;
                }
            }
            if( b3==false && b4==true ){
                if( v[j].size()<=2 ){
                    v[j].push_back( d[i] );
                }
                else{
                    cout<<-1;
                    return 0;
                }
            }
            else if( b3==true && b4==false ){
                if( v[j].size()<=2 ){
                    v[j].push_back( c[i] );
                }
                else{
                    cout<<-1;
                    return 0;
                }
            }
            if( b3==false || b4==false ){
                break;
            }
        }
        if( b3==true && b4==true ){
            farhod:
            g++;
            if( g>a/3 ){
                cout<<-1;
                return 0;
            }
            if( v[g].size()<=1 ){
                v[g].push_back( c[i] );
                v[g].push_back( d[i] );
                continue;
            }
            goto farhod;
        }
        b3=true;
        b4=true;
    }



    for( i=1; i<=a/3; i++ ){
        for( j=0; j<v[i].size(); j++ ){
            z[v[i][j]]=0;
        }
    }
    g=0;
    for( i=1; i<=1201; i++ ){
        if( z[i]!=0 ){
            g++;
            x[g]=z[i];
        }
    }
    g=0;
    for( i=1; i<=a/3; i++ ){
        for( j=0; j<3; j++ ){
            if( v[i].size()<3 ){
                g++;
                v[i].push_back( x[g] );
            }
        }
    }
    for( i=1; i<=a/3; i++ ){
        for( j=0; j<3; j++ ){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}