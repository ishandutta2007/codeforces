#include <iostream>
using namespace std;
int main()
{
    int a,b,c,i,d,f;
    cin>>a>>b>>c;
    for( i=0; i<=max( a, max( b, c ) ); i++ ){
        d=b-i;
        f=a-i;
        if( f+d==c && d>=0 && f>=0 ){
            cout<<i<<" "<<d<<" "<<f;
            return 0;
        }
    }
    cout<<"Impossible";
    return 0;
}