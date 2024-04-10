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
int a, d[10], i;

int main()
{
    for( i = 1; i <= 9; i++ )cin >> d[i];
    d[9] = (d[4] + d[6] - d[7] - d[8] + d[2] + d[3]) / 2;
    d[5] = d[2] + d[3] - d[9];
    d[1] = d[7] + d[8] - d[5];
    for( i = 1; i <= 9; i++ ){
        cout << d[i] << " ";
        if( i % 3 == 0 )cout << endl; 
    }
}