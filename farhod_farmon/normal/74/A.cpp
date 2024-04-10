// http://codeforces.ru/contest/74/problem/A

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
    int a,i;
    string s,x="";
    map < string, int > m;
    cin>>a;
    for( i=1; i<=a; i++ ){
        int mi,pl,A,B,C,D,E;
        cin>>s>>mi>>pl>>A>>B>>C>>D>>E;
        m[s]=mi*100-pl*50+A+B+C+D+E;
        if( m[s]>m[x] || x=="" )x=s;
    }
    cout<<x;
}