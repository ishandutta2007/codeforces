#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>

#define pb push_back
#define si size
#define sort(a,b) sort( a+1, a+b+1 )
#define fi first
#define se second
#define lli long long int

using namespace std;
int main()
{
    int a=3,i,j;
    char c[5][5];
    for( i=1; i<=a; i++ ){
        for( j=1; j<=a; j++ ){
            cin>>c[i][j];
        }
    }
    if( c[1][1]==c[3][3] && c[1][2]==c[3][2] && c[1][3]==c[3][1] && c[2][1]==c[2][3] ){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}