#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector < int > v[1001],v1[1001];
    vector < char > s[1001];
    int a,b,c[1001],i,j,k,g=0,m,n,ans;
    cin>>a>>b;
    for( i=1; i<=a; i++ )cin>>c[i];
    for( i=1; i<=1000; i++ ){
        m=i;
        for( j=1; j<=a; j++ ){
            if( c[j]!=m ){
                v[i].push_back( abs(c[j]-m) );
                v1[i].push_back( j );
                if( c[j]>m )s[i].push_back( '-' );
                else s[i].push_back( '+' );
            }
            m+=b;
        }
    }
    n=m=9999;
    for( i=1; i<=1000; i++ ){
        if( v[i].size()<n ){
            m=i;
            n=v[i].size();
        }
    }
    cout<<v[m].size()<<endl;
    for( i=0; i<v[m].size(); i++ ){
        cout<<s[m][i]<<" "<<v1[m][i]<<" "<<v[m][i]<<endl;
    }
    return 0;
}