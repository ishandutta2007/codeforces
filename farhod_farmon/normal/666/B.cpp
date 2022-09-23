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

const int N = 3003;

using namespace std;

int n, d1[N][N], a, b, c, d, mx[N][4], mx1[N][4];
vector < int > v[N];

void bfs( int g )
{
    queue < int > q;
    q.push(g);
    while( !q.empty() ){
        int x = q.front();
        q.pop();
        for( int i = 0; i < v[x].size(); i++ ){
            if( d1[g][v[x][i]] == 1e9 ){
                d1[g][v[x][i]] = d1[g][x] + 1;
                q.push(v[x][i]);
            }
        }
    }
}

void upd( int x, int y )
{
    if( x == y || d1[x][y] == 1e9 )
        return;
    if( d1[x][y] > d1[x][mx1[x][1]] ){
        mx1[x][3] = mx1[x][2];
        mx1[x][2] = mx1[x][1];
        mx1[x][1] = y;
    }
    else if( d1[x][y] > d1[x][mx1[x][2]] ){
        mx1[x][3] = mx1[x][2];
        mx1[x][2] = y;
    }
    else if( d1[x][y] > d1[x][mx1[x][3]] ){
        mx1[x][3] = y;
    }
}

void upd1( int x, int y )
{
    if( x == y || d1[y][x] == 1e9 )
        return;
    if( d1[y][x] > d1[mx[x][1]][x] ){
        mx[x][3] = mx[x][2];
        mx[x][2] = mx[x][1];
        mx[x][1] = y;
    }
    else if( d1[y][x] > d1[mx[x][2]][x] ){
        mx[x][3] = mx[x][2];
        mx[x][2] = y;
    }
    else if( d1[y][x] > d1[mx[x][3]][x] ){
        mx[x][3] = y;
    }
}

int main()
{
    int m, i, j, h, x, y;
    cin >> n >> m;
    for( i = 1; i <= m; i++ ){
        cin >> x >> y;
        v[x].pb(y);
    }
    for( i = 1; i <= n; i++ ){
        for( j = 1; j <= n; j++ ){
            d1[i][j] = 1e9;
        }
        d1[i][i] = 0;
    }
    for( i = 1; i <= n; i++ )
        bfs(i);
    for( i = 1; i <= n; i++ )
        for( j = 1; j <= n; j++ )
            upd(i, j), upd1(i, j);
    for( i = 1; i <= n; i++ ){
        for( j = 1; j <= n; j++ ){
            if( i == j || d1[i][j] == 1e9 )
                continue;
            for( int h1 = 1; h1 <= 3; h1++ ){
                for( int h2 = 1; h2 <= 3; h2++ ){
                    x = mx[i][h1];
                    y = mx1[j][h2];
                    if( !x || !y || d1[x][i] == 1e9 || d1[j][y] == 1e9 || x == i || x == j || x == y || y == i || y == j )
                        continue;
                    if( d1[x][i] + d1[i][j] + d1[j][y] > d1[a][b] + d1[b][c] + d1[c][d] ){
                        a = x;
                        b = i;
                        c = j;
                        d = y;
                    }
                }
            }
        }
    }
    cout << a << " " << b << " " << c << " " << d << endl;
}