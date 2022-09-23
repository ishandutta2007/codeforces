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
#define fin freopen( "g.in", "r", stdin );
#define fout freopen( "g.out", "w", stdout );
#define N 100000
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int main()
{
    string ans[3]={ "RIGHT\n", "LEFT\n", "PRINT " },s;
    int a,b,k,i,j,cnt=0;
    cin>>a>>k>>s;
    if( k>a/2 ){
        for( i=k; i<a; i++ )cout<<ans[0];
        for( i=s.size()-1; i>=0; i-- ){
            cout<<ans[2]<<s[i]<<endl;
            if( i>0 )cout<<ans[1];
        }
    }
    else{
        for( i=1; i<k; i++ )cout<<ans[1];
        for( i=0; i<s.size(); i++ ){
            cout<<ans[2]<<s[i]<<endl;
            if( i<s.size()-1 )cout<<ans[0];
        }
    }
}