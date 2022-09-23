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
#define fin freopen( "cipher.in", "r", stdin );
#define fout freopen( "cipher.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int a, i, j, used[10001];
vector < int > ans;

int main()
{
    cin >> a;
    for( i = 2; i <= a; i++ ){
        if( used[i] )continue;
        for( j = i; j <= a; j *= i )ans.pb(j);
        for( j = i; j <= a; j += i )used[j] = true;
    }
    cout << ans.size() << endl;
    for( i = 0; i < ans.size(); i++ )cout << ans[i] << " ";
}