#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,i,j,b[1000],g=1,cnt=0,ans=0;
    cin>>a;
    for( i=1; i<=a; i++ ){
        for( j=1; j<=i; j++ ){
            if( i%j==0 ){
                cnt++;
            }
        }
        if( cnt==2 ){
            b[g]=i;
            g++;
        }
        cnt=0;
    }
    cnt=0;
    for( i=1; i<=a; i++ ){
        for( j=1; j<g; j++ ){
            if( i%b[j]==0 ){
                cnt++;
            }
        }
        if( cnt==2 ){
            ans++;
        }
        cnt=0;
    }
    cout<<ans;
    return 0;
}