#include <iostream>
#include <cstdlib>
using namespace std;
long long int a,b,cnt;

void rec( long long x, int c, int d )
{
     if( x>=a*100 )return;    
     if( x>=a && c==d)cnt=min( cnt,x );    
     rec( x*10+4,c,d+1 );
     rec( x*10+7,c+1,d );     
}

int main()
{
    cin>>a;
    b=a;
    cnt=0;
    while( b>0 ){
         b/=10;
         cnt=cnt*10+7;         
    }
    cnt=(cnt*10+7)*10+7;
    rec(0,0,0);
    cout<<cnt;
    return 0;
}