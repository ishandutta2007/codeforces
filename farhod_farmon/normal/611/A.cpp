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

int d[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, x, i, j, ans;
string s;

int main()
{
    cin >> x >> s >> s;
    if( s == "week" ){
        int g = 5;
        for( i = 1; i <= 366; i++ ){
            if( g == x )ans++;
            g++;
            if( g == 8 )g = 1;
        }
    }
    else{
        for( i = 1; i <= 12; i++ ){
            if( x <= d[i] )ans++;
        }
    }
    cout << ans << endl;
}