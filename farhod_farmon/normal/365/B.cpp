#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b[100001],cnt=0,i,ans=0;
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>b[i];
    }  
    for( i=1; i<=a; i++ ){
        if( i<=2 ){
            continue;
        }
        if( b[i]==b[i-1]+b[i-2] ){
            cnt++;
        }
        else{
            cnt=0;
        }
        ans=max( ans, cnt );
    }
    if( a==1 || a==2 ){
        cout<<a;
        return 0;
    }
    cout<<ans+2;
    return 0;
}