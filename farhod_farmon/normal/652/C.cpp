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

lli ans;
int n, m, p[300003], a, b, cnt;
vector < int > v[300003];
bool used[300003];

void add( int x )
{
    x = p[x];
    if( used[x] )
        return;
    used[x] = true;
    for( int i = 0; i < v[x].size(); i++ )
        cnt += used[v[x][i]];
}

void sub( int x )
{
    x = p[x];
    if( !used[x] )
        return;
    used[x] = false;
    for( int i = 0; i < v[x].size(); i++ )
        cnt -= used[v[x][i]];
}

int main()
{
    int i, j, h;
    sc( "%d%d", &n, &m );
    for( i = 1; i <= n; i++ ){
        sc( "%d", &p[i] );
    }
    for( i = 1; i <= m; i++ ){
        sc( "%d%d", &a, &b );
        v[a].pb(b);
        v[b].pb(a);
    }
    for( i = 1, j = 0; i <= n; i++ ){
        while( j <= n && !cnt ){
            j++;
            add(j);
        }
        ans += j - i;
        sub(i);
    }
    pr( "%I64d\n", ans );
}