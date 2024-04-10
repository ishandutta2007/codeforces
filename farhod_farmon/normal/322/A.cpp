#include <iostream>
using namespace std;
int main()
{
    int a,b,i;
    cin>>a>>b;
    cout<<a+b-1<<endl;
    for( i=1; i<=b; i++ ){
        cout<<1<<" "<<i<<endl;
    }
    for( i=2; i<=a; i++ ){
        cout<<i<<" "<<b<<endl;
    }
    return 0;
}