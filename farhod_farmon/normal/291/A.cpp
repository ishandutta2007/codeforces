#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    long long int a,b[1001],d=1,cnt=0,i;
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>b[i];
    }
    sort( b+1,b+a+1 );
    for( i=1; i<=a; i++ ){
        if( b[i]==b[i+1] && b[i]!=0 ){
            d++;
        }
        else{
            if( d==2 ){
                cnt++;
            }
            else if( d>2 ){
                cout<<-1;
                return 0;
            }
            d=1;
        }
    }
    cout<<cnt;
    return 0;
}