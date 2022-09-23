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
#define fin freopen( "birthday.in", "r", stdin );
#define fout freopen( "birthday.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int a, b[111], i, x = 2;

int main()
{
    cin >> a;
    for( i = 1; i <= a; i++ )cin >> b[i];
    for( i = 3; i <= a; i++ ){
        if( abs(b[i] - b[i - 1]) < abs(b[x] - b[x - 1]) )x = i;
    }
    if( abs(b[x] - b[x - 1]) > abs(b[a] - b[1]) )cout << 1 << " " << a << endl;
    else cout << x - 1 << " " << x << endl;  
}