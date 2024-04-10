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
int a, b[100001], k, i, l = -1, r;
int used[100001];

int main()
{
    sc("%d %d", &a, &k);
    for( i = 1; i <= a; i++ ){
        sc("%d", &b[i]);
        if( i > 1 ){
            if( b[i] != b[i - 1] && l == -1 )l = i - 1;
        }
        if( !used[b[i]] ){
            k--;
            if( k <= 0 ){
                l = max(1, l);
                for( int j = 1; j < l; j++ )used[b[l]]--;
                while( used[b[l]] > 1 ){
                    used[b[l]]--;
                    l++;
                }
                cout << l << ' ' << i;
                return 0;
            }
        }
        used[b[i]]++;
    }
    cout << "-1 -1";
}