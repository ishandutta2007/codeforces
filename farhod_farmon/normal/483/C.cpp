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
    int a,b,i,j;
    cin>>a>>b;
    j=a;
    bool used[100001]={};
    for( i=1; i<=b; i++ ){
       if( i%2 ) cout<<i/2+1<<" ",used[i/2+1]=1;
       else cout<<j<<" ",j--,used[j+1]=1;
    }
    if( b%2 ){
       for( i=1; i<=a; i++ ){
          if( !used[i] )cout<<i<<" ";
       }
    }
    else{
       for( i=a; i>=1; i-- ){
          if( !used[i] )cout<<i<<" ";
       }
    }
}