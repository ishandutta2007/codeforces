#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c[200001],x[200001],y[200001],i,j,d=0,d1=0;
    cin>>a>>b;
    for( i=1; i<=a; i++ ){
        cin>>c[i];
        if( c[i]<0 ){
            d++;
        }
        else{
            d1++;
        }
    }
    for( i=1; i<=b; i++ ){
        cin>>x[i]>>y[i];
    }
    for( i=1; i<=b; i++ ){
        if( ( abs(y[i]-x[i])+1 )%2==0 ){
            if( ( abs(y[i]-x[i])+1 )/2<=d && ( abs(y[i]-x[i])+1 )/2<=d1 ){
                cout<<1<<endl;
            }
            else{
                cout<<0<<endl;
            }
        }
        else{
            cout<<0<<endl;
        }
    }
    return 0;
}