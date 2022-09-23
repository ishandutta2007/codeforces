#include <bits/stdc++.h>
using namespace std;
int main()
{
    string p1="LIVE",p2="LIVE";
    int a[1001],b[1001],n,i,j,cnt=0,d[1001],c[3],c1[3];
    cin>>n;
    for( i=1; i<=n; i++ ){
        cin>>d[i]>>a[i]>>b[i];
    }
    for( i=1; i<=n; i++ ){
        c[d[i]]++;
        c1[d[i]]+=a[i];
    }
    if( c[1]*10/2<=c1[1] ){
        cout<<"LIVE\n";
    }
    else{
        cout<<"DEAD\n";
    }
    if( c[2]*10/2<=c1[2] ){
        cout<<"LIVE\n";
    }
    else{
        cout<<"DEAD\n";
    }
    return 0;
}