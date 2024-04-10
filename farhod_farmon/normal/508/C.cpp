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
    int a,b,c,i,j,d[1000]={},cnt=0,f[1000]={},k,l,z[301];
    cin>>a>>b>>c;
    for( i=1; i<=a; i++ ){
         cin>>z[i];
         z[i]+=301;     
    }
    for( i=1; i<=a; i++ ){
         l=z[i]-1;
         while( d[z[i]]<c ){
                while( f[l]==1 && l>=0 )l--;
                if( l>=0 )f[l]=1;
                for( j=l+1; j<=l+b; j++ ){
                     d[j]++;     
                }  
                cnt++;
                if( cnt>700 || l<0 ){
                    cout<<-1;
                    return 0;    
                }     
         }
    }
    cout<<cnt;
    //system ( "pause" );
    return 0;    
}