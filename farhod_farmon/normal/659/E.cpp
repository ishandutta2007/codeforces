#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

using namespace std;

int n, m, cnt, c;
vector < int > v[100001];
int used[100001];
bool b1;

void dfs( int x, int p )
{
    used[x] = c;
    for( int i = 0; i < v[x].size(); i++ ){
        if( v[x][i] == p )
            continue;
        if( used[v[x][i]] )
            b1 = false;
        else
            dfs(v[x][i], x);
    }
}

int main()
{
    int i, j, h, x, y;
    sc( "%d%d", &n, &m );
    for( i = 1; i <= m; i++ ){
        sc( "%d%d", &x, &y );
        v[x].pb(y);
        v[y].pb(x);
    }
    for( i = 1; i <= n; i++ ){
        if( !used[i] ){
            c++;
            b1 = true;
            dfs(i, -1);
            cnt += b1;
        }
    }
    pr( "%d\n", cnt );
}