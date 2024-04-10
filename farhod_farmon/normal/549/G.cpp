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
#define fin freopen( "msched.in", "r", stdin );
#define fout freopen( "msched.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int a, b[200001], i;

int main()
{
    cin >> a;
    for( i = 1; i <= a; i++ ){
        cin >> b[i];
        b[i] += i;
    }
    sort( b + 1, b + a + 1 );
    b[1] -= 1;
    for( i = 2; i <= a; i++ ){
        b[i] -= i;
        if( b[i] < b[i - 1] ){
            cout << ":(\n";
            return 0;
        }
    }
    for( i = 1; i <= a; i++ )cout << b[i] << " ";
}