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
int a, i, j, h1, h2, h;
bool used[101][101];
char c[1001][1001], ans[101][101];
vector < int > x, y;

bool che( int x1, int y1 ){
    if( x1 < 1 || y1 < 1 || x1 > a || y1 > a || c[x1][y1] != '.' )return false;
    return true;
}

int main()
{
    cin >> a;
    for( i = 1; i <= a; i++ ){
        for( j = 1; j <= a; j++ ){
            cin >> c[i][j];
            if( c[i][j] == 'o' ){
                x.pb(i);
                y.pb(j);
            }
        }
    }
    for( i = 1; i < a * 2; i++ ){
        for( j = 1; j < a * 2; j++ ){
            ans[i][j] = '.';
        }
    }
    for( h1 = -a; h1 <= a; h1++ ){
        for( h2 = -a; h2 <= a; h2++ ){
            bool b1 = true;
            for( i = 0; i < x.size(); i++ ){
                if( che(x[i] + h1, y[i] + h2) )b1 = false;
            }
            if( b1 )used[h1 + 50][h2 + 50] = 1;
        }
    }
    for( h1 = -a; h1 <= a; h1++ ){
        for( h2 = -a; h2 <= a; h2++ ){
            if( !used[h1 + 50][h2 + 50] )continue;
            for( i = 0; i < x.size(); i++ ){
                if( x[i] + h1 <= a && x[i] + h1 >= 1 && y[i] + h2 <= a && y[i] + h2 >= 1 )c[x[i] + h1][y[i] + h2] = '.';
            }
            ans[a + h1][a + h2] = 'x';
        }
    }
    for( i = 1; i <= a; i++ ){
        for( j = 1; j <= a; j++ ){
            if( c[i][j] == 'x' ){
                cout << "NO";
                return 0;
            }
        }
    }
    ans[a][a] = 'o';
    cout << "YES\n";
    for( i = 1; i < a * 2; i++ ){
        for( j = 1; j < a * 2; j++ ){
            cout << ans[i][j];
        }
        cout << endl;
    }
}