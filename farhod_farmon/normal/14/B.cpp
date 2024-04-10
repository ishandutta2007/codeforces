#include <bits/stdc++.h>
using namespace std;
int main()
{
    bool b1[101][1001]={};
    int a,b[101],c[101],x,i,j,h,k,cnt=99999,d,f,ans=999999;
    cin>>a>>x;
    for( i=1; i<=a; i++ ){
        cin>>b[i]>>c[i];
        d=max( b[i], c[i] );
        f=min( b[i], c[i] );
        b[i]=f;
        c[i]=d;
        if( c[i]-b[i]<cnt ){
            cnt=c[i]-b[i];
            h=b[i];
            k=c[i];
        }
    }
    for( i=1; i<=a; i++ ){
        for( j=b[i]; j<=c[i]; j++ ){
            b1[i][j]=1;
        }
    }
    cnt=0;
    for( i=h; i<=k; i++ ){
        for( j=1; j<=a; j++ ){
            cnt+=b1[j][i];
        }
        if( cnt==a ){
            ans=min( ans, abs( i-x ) );
        }
        cnt=0;
    }
    if( ans==999999 ){
        cout<<-1;
        return 0;
    }
    cout<<ans;
    return 0;
}