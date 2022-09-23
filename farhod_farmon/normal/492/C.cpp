#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,t,avg,i,cnt=0,sum=0,d,f;
    cin>>n>>t>>avg;
    pair< long long int , long long int > b[n   ];
    d=avg*n;
    for( i=1; i<=n; i++ ){
        cin>>b[i].second;
        cin>>b[i].first;
        sum+=b[i].second;
    }
    sort( b+1,b+n+1 );
    for( i=1; i<=n; i++ ){
        if( sum>=d ){
            break;
        }
        if( b[i].second<t ){
            b[i].second=t-b[i].second;
            if( b[i].second<=abs( d-sum ) ){
                f=b[i].second;
            }
            else{
                f=d-sum;
            }
            cnt+=b[i].first*f;
            sum+=f;
        }
    }
    cout<<cnt;
    return 0;
}