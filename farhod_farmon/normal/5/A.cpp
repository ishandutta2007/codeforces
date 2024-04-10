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
int a, b;
string s;
int main()
{
    string s;
    int cnt = 0,i, j = 0, g;
    while( getline( cin, s ) ){
        if( s[0] == '-' ) j --;
        else if( s[0] == '+' ) j ++;
        else{
            i=0;
            while( s[i]!=':' )i++;
            cnt += ( s.size()-i-1 ) * j;
        }
    }
    cout << cnt;
    return 0;



}