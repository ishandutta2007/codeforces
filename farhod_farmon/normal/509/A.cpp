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
    int a,i,b[11][11]={},j;
    cin>>a;
    for( i=1; i<=a; i++ ){
         b[1][i]=b[i][1]=1;     
    }
    for( i=2; i<=a; i++ ){
         for( j=1; j<=a; j++ ){
              if( j==1 )continue;
              b[i][j]=b[i-1][j]+b[i][j-1];
         }   
    }
    cout<<b[a][a];
    //system ("pause");
    return 0;    
}