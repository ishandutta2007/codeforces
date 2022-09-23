#include <iostream>
using namespace std;
int main()
{
    int a,b,c[101][101],i,j,d[101],d1[101];
    cin>>a>>b;
    for( i=1; i<=a; i++ ){
        if( i==a ){
            d[i]=b;
        }
        else{
            d[i]=1;
            b-=1;
        }
    }
    for( i=1; i<=a; i++ ){
        d1[i]=d[i];
    }
    for( i=1; i<=a; i++ ){
        for( j=1; j<=a; j++ ){
            c[i][j]=d[j];
        }
        d1[1]=d[a];
        for( j=2; j<=a; j++ ){
            d1[j]=d[j-1];
        }
        for( j=1; j<=a; j++ ){
            d[j]=d1[j];
        }
    }      
    for( i=1; i<=a; i++ ){
        for( j=1; j<=a; j++ ){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}