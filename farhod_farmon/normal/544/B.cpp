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
int main ()
{
    int a, k, i, j, g;
    cin >> a >> k;
    g = a * a;
    if( g / 2 + a % 2 < k ){
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for( i = 1; i <= a; i++ ){
        for( j = 1; j <= a; j++ ){
            if( (i + j) % 2 == 0 && k ){
                k--;
                cout << "L";
            }
            else cout << "S";
        }
        cout << endl;
    }
}