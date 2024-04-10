#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int b[4][4],i,j,c[10][10]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},h;
    for( j=1; j<=3; j++ ){
        for( i=1; i<=3; i++ ){
            cin>>b[j][i];
        }
    }
    for( j=1; j<=3; j++ ){
        for( i=1; i<=3; i++ ){
            if(b[j][i]%2!=0){
                b[j][i]--;
                c[j][i]=c[j][i]+=1;
                c[j+1][i]=c[j+1][i]+=1;
                c[j][i+1]=c[j][i+1]+=1;
                c[j][i-1]=c[j][i-1]+=1;
                c[j-1][i]=c[j-1][i]+=1;
            }
        }
    }
    for( j=1; j<=3; j++ ){
        for( i=1; i<=3; i++ ){
            cout<<c[j][i]%2;
        }
        cout<<endl;
    }
    return 0;
}