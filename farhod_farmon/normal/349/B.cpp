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
lli v, b[10], i, j, h, cnt, dp[1000001], d[1000001][11];

int main()
{
    bool b1 = false;
    cin >> v;
    for( i = 1; i <= 9; i++ ) cin >> b[i];
    for( i = 1; i <= v; i++ ){
        for( j = 1; j <= 9; j++ ){
            if( i - b[j] >= 0 ){
                d[i - b[j]][j]++;
                int cnt1 = 0, cnt2 = 0;
                for( h = 1; h <= 9; h++ )cnt1 += d[i][h];
                for( h = 1; h <= 9; h++ )cnt2 += d[i - b[j]][h];
                if( cnt2 >= cnt1 ){
                    if( cnt2 > cnt1 ){
                        for( h = 1; h <= 9; h++ )d[i][h] = d[i - b[j]][h];
                    }
                    else{
                        bool b1 = false;
                        for( h = 9; h >= 1; h-- ){
                            if( d[i][h] > d[i - b[j]][h] )break;
                            if( d[i][h] < d[i - b[j]][h] ) b1 = true;
                        }
                        if( b1 ){
                            for( h = 1; h <= 9; h++ )d[i][h] = d[i - b[j]][h];
                        }
                    }
                }
                d[i - b[j]][j]--;
            }
        }
    }
    for( i = 9; i >= 1; i-- ){
        for( j = 0; j < d[v][i]; j++ ){
            b1 = true;
            cout << i;
        }
    }
    if( !b1 )cout << -1;
}