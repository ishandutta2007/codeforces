#include <iostream>
using namespace std;
int main()
{
    int a,b,cnt=0,c=0,i;
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>b;
        c+=b;
    }
    for( i=1; i<=5; i++ ){
        if((c+i)%(a+1)!=1){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}