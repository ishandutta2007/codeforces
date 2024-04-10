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
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int main()
{
    int a, d, b[2001], i, j, cnt;
    cin >> a >> d;
    for( i = 1; i <= a; i++ ) cin >> b[i];
    for( i = 2; i <= a; i++ ){
        if( b[i] <= b[i - 1] ){
            cnt += (b[i - 1] - b[i]) / d + 1;
            b[i] = b[i] + ((b[i - 1] - b[i]) / d + 1) * d;
        }
    }
    cout << cnt << endl;
}