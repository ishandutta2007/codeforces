#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b[100001],i,j,used[5001];
    vector < int > v;
    cin>>a;
    for( i=1; i<=a; i++ ){
        cin>>b[i];
        used[b[i]]++;
        if( used[b[i]]>=2 ){
            used[b[i]]=4;
        }
    }
    sort( b+1, b+a+1 );
    for( i=1; i<=a; i++ ){
        if( used[b[i]]>=3 ){
            v.push_back( b[i] );
            used[b[i]]=2;
        }
        else if( used[b[i]]==1 ){
            v.push_back( b[i] );
            used[b[i]]=0;
        }
    }
    used[b[a]]=0;
    for( i=a; i>=1; i-- ){
        if( used[b[i]]==2 ){
            v.push_back( b[i] ); 
            used[b[i]]=0;
        }
    }
    cout<<v.size()<<endl;
    for( i=0; i<v.size(); i++ ){
        cout<<v[i]<<" ";
    }
    return 0;
}