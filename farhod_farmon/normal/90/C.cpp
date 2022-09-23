#include <bits/stdc++.h>
using namespace std;
int main()
{
    bool b1=true;
    long long int a,b,c,i,d[10001],cnt=999999999;
    cin>>a>>b>>c;
    for( i=1; i<=a; i++ ){
        cin>>d[i];
        if( i%2!=0 && d[i]==0 ){
            b1=false;
        }
        if( i%2!=0 ){
            cnt=min( cnt, d[i] );
        }
    }
    if( a%2==0 || a/2+1>b || b1==false ){
        cout<<0;
        return 0;
    }
    b=b/((a+1)/2);
    b*=c;
    cout<<min( cnt, b );
    return 0;
}