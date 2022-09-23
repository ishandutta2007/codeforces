#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    long long int a,b,c[100001],cnt=0,i;
    cin>>a>>b;
    for( i=1; i<=a; i++ ){
        cin>>c[i];
    }
    sort(c+1,c+a+1);
    for( i=1; i<=a; i++ ){
        cnt+=c[i]*b;
        if( b>1 ){
            b--;
        }
    }
    cout<<cnt;
    return 0;
}