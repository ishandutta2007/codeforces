#include <iostream>
using namespace std;
int main()
{
    int a,b,c,d=0;
    string s[2]={"First","Second"};
    cin>>a>>b>>c;
    c*=2;
    if( c>a || c>b ){
        d=1;    
    }
    cout<<s[d];
    return 0;    
}