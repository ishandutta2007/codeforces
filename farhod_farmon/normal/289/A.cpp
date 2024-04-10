#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d=0,cnt=0,ans,i;
    cin>>a>>b;
    for( i=1; i<=a; i++ ){
        cin>>c>>d;
        cnt+=( d-c );
    }
    cnt+=a;
    ans=cnt/b;
    if( cnt%b==0 ){
        cout<<0;
    }
    else{
        cout<<( ( ans+1 )*b )-cnt;
    }
    return 0;
}