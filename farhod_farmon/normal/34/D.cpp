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
#include <iomanip>

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

const int N = 50005;

using namespace std;

int n, pre[N];
vector < int > v[N];

void dfs( int x, int p = -1 )
{
    pre[x] = p;
    for( int i = 0; i < v[x].size(); i++ ){
        int y = v[x][i];
        if( y == p )continue;
        dfs(y, x);
    }
}

int main()
{
    int i, j, h, x, y, r1, r2;
    cin >> n >> r1 >> r2;
    for( i = 1; i < n; i++ ){
        cin >> x;
        y = i;
        if( i >= r1 )y++;
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(r2);
    for( i = 1; i <= n; i++ ){
        if( i == r2 )continue;
        cout << pre[i] << " ";
    }
}