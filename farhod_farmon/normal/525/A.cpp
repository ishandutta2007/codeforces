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
#define fout freopen( "OUTPUT.TXT", "w", stdout );
#define N 100000
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int main()
{
    int a,i,j,k,l,m,n,d[1001]={},cnt=0;
    string s;
    cin>>a>>s;
    for( i=0; i<s.size(); i++ ){
        if( s[i]<97 ){
            if( d[s[i]+32]>0 )d[s[i]+32]--;
            else cnt++;
        }
        else{
            d[s[i]]++;
        }
    }
    cout<<cnt;
}