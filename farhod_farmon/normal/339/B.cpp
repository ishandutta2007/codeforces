#include <iostream>
using namespace std;
int main()
{
    long long int a,d,c[1000001],cnt=0,i;
    bool b=true;

    cin>>d>>a;

    for( i=1; i<=a; i++ ){
        cin>>c[i];
    }

    for( i=1; i<=a; i++ ){
        if(b==true){
            b=false;
            cnt+=c[i];
        }
        else{
            cnt+=c[i]-c[i-1];
        }
        if(c[i]>c[i+1] && i+1<=a){
            b=true;
            cnt+=d-c[i];
        }
    }

    cout<<cnt-1;

    return 0;
}