#include <iostream>
using namespace std;
int main()
{
    int a,b[101],sum=0,cnt=0,i;
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>b[i];
        sum+=b[i];
    }
    for( i=1; i<=a; i++ ){
        if((sum-b[i])%2==0){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}