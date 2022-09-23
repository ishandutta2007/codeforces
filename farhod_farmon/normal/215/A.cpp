#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,cnt=0,i;
    float maxn=0,a[100],b[100];
    cin>>n;
    for( i=1; i<=n; i++ ){
        cin>>a[i];
    }
    cin>>m;
    for( i=1; i<=m; i++ ){
        cin>>b[i];
    }
    for( int j=1; j<=n; j++ ){
        for( i=1; i<=m; i++ ){
            if( b[i]/a[j]>maxn && b[i]/a[j]==int( b[i]/a[j] ) ){
                maxn=b[i]/a[j];
                cnt=1;
            }
            else if( b[i]/a[j]==maxn ){
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}