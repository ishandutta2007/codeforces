#include <iostream>
using namespace std;
int main()
{
    int a,b[101],c,d[101],d1[101],i,j,cnt;
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>b[i];
    }
    cin>>c;
    for( i=1; i<=c; i++ ){
        cin>>d[i]>>d1[i];
    }

    for( i=1; i<=c; i++ ){
        if( d[i]>1 && d[i]<a ){
            b[d[i]-1]+=d1[i]-1;
            b[d[i]+1]+=b[d[i]]-d1[i];
            b[d[i]]=0;
        }
        else if( d[i]>1 && d[i]==a ){
            b[d[i]-1]+=d1[i]-1;
            b[d[i]]=0;
        }
        else if( d[i]==1 && d[i]<a ){
            b[d[i]+1]+=b[d[i]]-d1[i];
            b[d[i]]=0;
        }
        else{
            b[d[i]]=0;
        }
    }
    for( i=1; i<=a; i++ ){
        cout<<b[i]<<endl;
    }
    return 0;
}