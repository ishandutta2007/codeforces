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
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
double c1, c2, g;
int a, i;
string s, t;

void rec( int x, int cnt )
{
    if( x == s.size() ){
        c2++;
        if( cnt == g )c1++;
        return;
    }
    if( t[x] == '+' )rec(x + 1, cnt + 1);
    else if( t[x] == '-' )rec(x + 1, cnt - 1);
    else{
        rec(x + 1, cnt + 1);
        rec(x + 1, cnt - 1);
    }
}

int main()
{
    cin >> s >> t;
    for( i = 0; i < s.size(); i++ ){
        if( s[i] == '+' )g++;
        else g--;
    }
    rec(0, 0);
    pr( "%.9f", c1 / c2 );
}