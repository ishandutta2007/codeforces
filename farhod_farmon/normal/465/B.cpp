#include <iostream>
using namespace std;
int main()
{
    int a,b[1001],c[1001],i,b1=0,cnt=0;
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>b[i];
        if(b[i]==1){
            b1++;
            c[b1]=i;
        }
    }
    for( i=1; i<b1; i++ ){
        if(c[i]+1!=c[i+1]){
            cnt++;
        }
    }
    cout<<cnt+b1;
    return 0;
}