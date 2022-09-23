#include <iostream>
using namespace std;
int main()
{
    int a,b[100002],i,cnt=0,c[100002],d[100002];;
    cin>>a;
    for( i=1; i<=a; i++ ){
         cin>>b[i];
         c[i]=0;
         d[i]=0;     
    }
    d[a+1]=0;
    for( i=1; i<=a; i++ ){
         c[i]=b[i]+c[i-1];     
    }
    for( i=a; i>=1; i-- ){
         d[i]=b[i]+d[i+1];     
    }
    for( i=1; i<a; i++ ){
         if( c[i]==d[i+1] )cnt++;     
    }
    cout<<cnt;
    return 0;
}