#include <iostream>
using namespace std;
int main()
{
    long long int n,a[10001],b[10001],i,j,cnt=0,maxn=0;
    cin>>n;
    for( i=1; i<=n; i++ ){
        cin>>a[i]>>b[i];
    }
    for( j=1; j<=n; j++ ){
        for( i=1; i<n; i++ ){
            if( a[i]>a[i+1] ){
                swap( a[i],a[i+1] );
                swap( b[i],b[i+1] );
            }
            else if( a[i]==a[i+1] ){
                swap( a[i],a[i+1] );
                if( b[i]>b[i+1] ){
                    swap( b[i],b[i+1] );
                }
            }
        }
    }
    for( i=1; i<=n; i++ ){
        if( b[i]>=cnt ){
            cnt=b[i];
        }
        else{
            cnt=a[i];
        }
    }
    cout<<cnt;
    return 0;
}