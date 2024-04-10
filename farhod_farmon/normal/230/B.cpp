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
lli a, i, j, x;
bool used[1000001];

int main()
{
    used[1] = true;
    for( i = 2; i <= 1e3; i++ ){
        if( used[i] )continue;
        for( j = i * i; j <= 1e6; j += i )used[j] = true;
    }
    cin >> a;
    for( i = 1; i <= a; i++ ){
        cin >> x;
        j = sqrt(x);
        if( j * j == x && !used[j] )cout << "YES\n";
        else cout << "NO\n";
    }
}