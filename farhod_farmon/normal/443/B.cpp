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
#define fin freopen( "milk.in", "r", stdin );
#define fout freopen( "input.txt", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int k;
string s;

int f( int x, int a )
{
    int i;
    for( i = x; i > x - a; i-- ){
        if( i < s.size() && s[i] != s[i - a] )return 0;
    }
    return a * 2;
}

int main()
{
    int i, j, ans = 0;
    cin >> s >> k;
    for( i = 0; i < s.size() + k; i++ ){
        for( j = 1; j <= (i + 1) / 2; j++ ){
            ans = max(ans, f(i, j));
        }
    }
    cout << ans;
}