#include <iostream>
using namespace std;
int main()
{
    int a,b,c[150001],d[150001],g=0,i,cnt,f1=99999999;
    cin>>a>>b;
    d[0]=0;
    for( i=1; i<=a; i++ ){
        cin>>c[i];
        d[i]=c[i]+d[i-1];
        c[i]=d[i];
    }
    for( i=1; i<=a; i++ ){
        c[i+b]-=d[i];
        if( i>=b ){
            if( c[i]<=f1 ){
                f1=c[i];
                cnt=i-(b-1);
            }
        }
    }
    cout<<cnt;
    return 0;
}