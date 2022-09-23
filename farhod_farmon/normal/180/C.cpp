
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

#define lli long long int
#define sc scanf
#define pr printf
#define pb push_back
#define p_b pop_back
#define mp make_pair
#define fi first
#define se second
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );
#define REP(x,y) for( x=1; x<=y; x++ )
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int main()
{
    string s=" ",t;
    int cnt=9999999,i,j,b[100002]={},c[100002]={};
    cin>>t;
    s+=t;
    for( i=1; i<s.size(); i++ ){
        b[i]=b[i-1];
        if( s[i]>=97 )b[i]++;
    }
    for( i=s.size()-1; i>=0; i-- ){
        c[i]=c[i+1];
        if( s[i]<97 )c[i]++;
    }
    for( i=0; i<s.size(); i++ ){
        if( b[i]+c[i+1]<cnt )cnt=b[i]+c[i+1];
    }
    cout<<cnt;
}