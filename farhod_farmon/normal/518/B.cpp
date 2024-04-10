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
    string s,t,ans;
    int i,j,a[30]={},b[30]={},c[30]={},d[30]={},cnt=0,cnt1=0;
    cin>>s>>t;
    for( i=0; i<s.size(); i++ ){
        if( s[i]<97 )a[s[i]-65]++;
        else b[s[i]-97]++;
    }
    for( i=0; i<t.size(); i++ ){
        if( t[i]<97 )c[t[i]-65]++;
        else d[t[i]-97]++;
    }
    for( i=0; i<26; i++ ){
        int x=min( a[i],c[i] ),y=min( b[i],d[i] );
        cnt+=x+y;
        a[i]-=x;
        c[i]-=x;
        b[i]-=y;
        d[i]-=y;
    }
    for( i=0; i<26; i++ ){
        int x=min( a[i],d[i] ),y=min( c[i],b[i] );
        cnt1+=x+y;
    }
    cout<<cnt<<' '<<cnt1;
    return 0;
}