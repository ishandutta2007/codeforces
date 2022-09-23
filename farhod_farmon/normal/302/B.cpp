#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b,c[100001],t[100001],v[100001],i,cnt=0,x=0;
    cin>>a>>b;
    for( i=1; i<=a; i++ )cin>>c[i]>>t[i];
    for( i=1; i<=b; i++ )cin>>v[i];
    for( i=1; i<=b; i++ ){
        if( v[i]>cnt ){
            while( v[i]>cnt ){
                x++;
                cnt+=c[x]*t[x];
            }
        }
        cout<<x<<endl;
    }
    return 0;
}