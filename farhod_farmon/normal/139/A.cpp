#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
    int a,b[1001],i,cnt=0;
    cin>>a;
    for( i=1; i<=7; i++ ){
        cin>>b[i];
    }
    farhod:
    cnt=0;
    for( i=1; i<=7; i++ ){
        a-=b[i];
        cnt++;
        if( a<=0 ){
            break;
        }
    }
    if( a>0 ){
        goto farhod;
    }
    cout<<cnt;
    return 0;
}