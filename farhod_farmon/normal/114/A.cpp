#include <iostream>
using namespace std;
int main()
{
    long long int a,b,cnt=0,c;
    cin>>a>>b;
    c=a;
    while( a<b ){
        a=a*c;
        cnt++;
    }
    if( a==b ){
        cout<<"YES\n"<<cnt;
    }
    else{
        cout<<"NO";
    }
    return 0;
}