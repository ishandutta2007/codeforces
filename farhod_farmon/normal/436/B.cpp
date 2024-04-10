#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <deque>
#include <queue>
#include <stack>

#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define p_b pop_back
#define pf push_front
#define p_f pop_front
#define mp make_pair
#define lli long long int
#define p_q priority_queue
#define fin freopen( "INPUT.TXT", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );
#define N 100000
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int main()
{
    int a,b,i,j,k,l,cnt=0,d[2001]={};
    cin>>a>>b>>k;
    char c[2001][2001];
    for( i=1; i<=a; i++ ){
        for( j=1; j<=b; j++ ){
            cin>>c[i][j];
        }
    }
    for( i=2; i<=a; i++ ){
        for( j=1; j<=b; j++ ){
            if( i*2-1<=a && c[i*2-1][j]=='U' )d[j]++;
            if( j+i-1<=b && c[i][j+i-1]=='L' )d[j]++;
            if( j-i+1>=1 && c[i][j-i+1]=='R' )d[j]++;
        }
    }
    for( i=1; i<=b; i++ )cout<<d[i]<<" ";
}