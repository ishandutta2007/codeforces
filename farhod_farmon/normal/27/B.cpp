#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c[2500],d[2500],f[2500][2500]={},i,j,g[2500]={};
    cin>>a;
    b=a*( a-1 )/2;
    for( i=1; i<b; i++ ){
        cin>>c[i]>>d[i];
        g[c[i]]++;
        g[d[i]]--;
        f[c[i]][d[i]]=1;
        f[d[i]][c[i]]=1;
        f[i][i]=1;
    }
    for( i=1; i<=a; i++ ){
        g[i]+=( a-1 );
    }
    for( i=1; i<=a; i++ ){
        for( j=1; j<=a; j++ ){
            if( f[i][j]==0 || f[j][i]==0 ){
                if( g[i]>g[j] ){
                    cout<<i<<" "<<j;
                }
                else{
                    cout<<j<<" "<<i;
                }
                return 0;
            }
        }
    }
    return 0;
}