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
    int a,b,i,j,k,d[1001]={},x=0;
    bool used[10001]={};
    cin>>a>>k;
    for( i=2; i<=a; i++ ){
        if( !used[i] ){
            for( j=i+i; j<=a; j+=i ){
                used[j]=true;
            }
        }
    }
    for( i=2; i<=a; i++ ){
        if( !used[i] ){
            d[i]+=d[x]+1;
            x=i;
        }
    }
    for( i=2; i<=a; i++ ){
        for( j=2; j<=a; j++ ){
            if( !used[i] && !used[j] && i>j && !used[i-j-1] && abs(d[i-j-1]-d[j])==1 ){
                k--;
                break;
            }
        }
    }
    if( k<1 )cout<<"YES";
    else cout<<"NO";
}