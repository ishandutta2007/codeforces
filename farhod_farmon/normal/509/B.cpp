#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <vector>
#include <cmath>
#include <cstring>
#include <cstdio>

#define pb push_back
#define fi first
#define se second

using namespace std;
int main()
{
    int a,b,c[101],d,i,j,minn=999,maxn=0;
    cin>>a>>b;
    for( i=1; i<=a; i++ ){
         cin>>c[i];
         minn=min( minn, c[i] );
         maxn=max( maxn, c[i] );     
    }
    if( maxn/b>minn/b && minn%b<maxn%b || maxn/b-1>minn/b ){
        cout<<"NO";
        return 0;    
    }
    cout<<"YES\n";
    for( i=1; i<=a; i++ ){
         for( j=0; j<c[i]; j++ ){
              cout<<j%b+1<<" ";
         }     
         cout<<endl;
    }
    //system ("pause");
    return 0;    
}