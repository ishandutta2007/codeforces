#include <iostream>
using namespace std;
int main()
{
    int a,b,c,g,h;
    float d,f;
    cin>>a>>b>>c;
    d=a*c;
    d/=100;
    if( d>int(d) ){
        h=int(d)+1;
    }
    else{
        h=int(d);
    }
    if( h-b<0 ){
        cout<<0;
        return 0;
    }
    cout<<h-b;
    return 0;
}