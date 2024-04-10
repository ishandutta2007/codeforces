#include <iostream>
#include <math.h>
#include <map>
using namespace std;
int main()
{
    int a,b,c[100001],i,cnt=0,sum=0,g=0;
    cin>>a>>b;
    for( i=0; i<a; i++ ){
        cin>>c[i];
    }
    for( i=0; i<a; i++ ){
        sum+=c[i];
        while( sum>b ){
            sum-=c[g];
            g++;
        }
        if( i-g+1>cnt ){
            cnt=i-g+1;
        }
    }  
    cout<<cnt;
    return 0;
}