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
#define fin freopen( "birthday.in", "r", stdin );
#define fout freopen( "birthday.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
string s[111];
int a;
bool used[222][222], b1, used1[222];
vector < char > ans;

void Pd( char x, char y )
{
    used[x][y] = true;
    for( char c = 'a'; c <= 'z'; c++ ){
        if( used[c][x] )used[c][y] = true;
        if( used[y][c] )used[x][c] = true;
    }
}

bool Pxy( char x, char y )
{
    if( used[x][y] )return true;
    if( used[y][x] )return false;
    for( char c = 'a'; c <= 'z'; c++ ){
        if( used[x][c] && used[c][y] ){
            used[x][y] = true;
            return true;
        }
    }
    return false;
}

void P( string x, string y )
{
    int i, j, h;
    for( i = j = 0; i < x.size() && j < y.size(); i++, j++ ){
        if( x[i] == y[j] )continue;
        if( Pxy(y[i], x[i]) ){
            cout << "Impossible" << endl;
            exit(0);
        }
        Pd( x[i], y[j] );
        break;
    }
    if( j == y.size() ){
        cout << "Impossible" << endl;
        exit(0);
    }
}

int main()
{
    int i, j, h;
    cin >> a;
    for( i = 1; i <= a; i++ ){
        cin >> s[i];
        if( i > 1 )P(s[i - 1], s[i]);
    }
    while( ans.size() != 26 ){
        char x, y;
        for( x = 'a'; x <= 'z'; x++ ){
            for( y = 'a'; y <= 'z'; y++ ){
                if( used[y][x] )break;
            }
            if( y > 'z' && !used1[x] ){
                used1[x] = true;
                for( y = 'a'; y <= 'z'; y++ )used[x][y] = false;
                ans.pb(x);
                break;
            }
        }
    }
    for( i = 0; i < 26; i++ )cout << ans[i];
}