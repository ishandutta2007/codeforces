#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c[5000],i,j,cnt=0,x,y;
    cin>>a>>b;
    for( i=1; i<=a; i++ )c[i]=1;
    for( i=1; i<=b; i++ ){
        cin>>j;
        x=y=0;
        if( j==1 )cin>>x>>y;
        else cin>>x;
        c[x]=c[y]=0;
    }
    for( i=1; i<a; i++ )cnt+=c[i];
    int minn=0;
    for( i=1; i<a; i++ ){
        if( c[i]+c[i+1]==2 ){
            minn++;
            i++;
        }
        else if( c[i]==1 ){
            minn++;
        }
    }
    cout<<minn<<" "<<cnt;
    return 0;
}