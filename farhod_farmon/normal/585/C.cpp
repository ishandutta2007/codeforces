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
lli a, b;

int main()
{
    cin >> a >> b;
    if( __gcd(a, b) > 1 ){
        cout << "Impossible" << endl;
        return 0;
    }
    while( a > 1 || b > 1 ){
        if( a > b ){
            cout << (a - 1) / b << "A";
            a -= ((a - 1) / b) * b;
        }
        else{
            cout << (b - 1) / a << "B";
            b -= ((b - 1) / a) * a;
        }
    }
}