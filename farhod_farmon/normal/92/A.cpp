#include <iostream>
using namespace std;
int main()
{
    int a,b,i,c,d=0;
    cin>>a>>b;
    for( i=1; i<=a; i++ ){
        d+=i;
    }
    c=b%d;
    for( i=1; i<=d; i++ ){
        if(c-i<0){
            break;
        }
        else{
            c=c-i       ;
        }
    }
    cout<<c;
    return 0;
}