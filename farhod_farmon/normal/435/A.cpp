#include <iostream>
using namespace std;
int main()
{
    int a,b,c[101],cnt=1,f=0,i;
    cin>>a>>b;
    for( i=1; i<=a; i++ ){
        cin>>c[i];
    }
    f=b;
    for( i=1; i<=a; i++ ){
        if(f-c[i]<0){
            cnt++;
            f=b;
            f-=c[i];
        }
        else{
            f-=c[i];
        }
    }
    cout<<cnt;
    return 0;
}