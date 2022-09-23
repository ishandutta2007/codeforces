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
#define fin freopen( "typo.in", "r", stdin );
#define fout freopen( "typo.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int  i, j, h;
char c[222][222], c1[222][222];
pair < pair < int, int >, char > p[4];

void S()
{
    for( i = 1; i <= 2; i++ ){
        swap(p[1].fi.fi, p[1].fi.se);
        for( j = 1; j <= 2; j++ ){
            swap(p[2].fi.fi, p[2].fi.se);
            for( h = 1; h <= 2; h++ ){
                swap(p[3].fi.fi, p[3].fi.se);
                if( p[1].fi.fi + p[2].fi.fi == p[1].fi.se && p[2].fi.fi == p[3].fi.fi && p[2].fi.se + p[3].fi.se == p[1].fi.se ){
                    cout << p[1].fi.se << endl;
                    for( i = 1; i <= p[1].fi.fi; i++ ){
                        for( j = 1; j <= p[1].fi.se; j++ )cout << p[1].se;
                        cout << endl;
                    }
                    for( i = 1; i <= p[2].fi.fi; i++ ){
                        for( j = 1; j <= p[2].fi.se; j++ )cout << p[2].se;
                        for( j = 1; j <= p[3].fi.se; j++ )cout << p[3].se;
                        cout << endl;
                    }
                    exit(0);
                }
                if( p[1].fi.se == p[2].fi.se && p[1].fi.se == p[3].fi.se && p[1].fi.fi + p[2].fi.fi + p[3].fi.fi == p[1].fi.se ){
                    cout << p[1].fi.se << endl;
                    for( i = 1; i <= p[1].fi.fi; i++ ){
                        for( j = 1; j <= p[1].fi.se; j++ )cout << p[1].se;
                        cout << endl;
                    }
                    for( i = 1; i <= p[2].fi.fi; i++ ){
                        for( j = 1; j <= p[2].fi.se; j++ )cout << p[2].se;
                        cout << endl;
                    }
                    for( i = 1; i <= p[3].fi.fi; i++ ){
                        for( j = 1; j <= p[3].fi.se; j++ )cout << p[3].se;
                        cout << endl;
                    }
                    exit(0);
                }
            }
        }
    }
}

int main()
{
    for( i = 1; i <= 3; i++ )cin >> p[i].fi.fi >> p[i].fi.se;
    p[1].se = 'A';
    p[2].se = 'B';
    p[3].se = 'C';
    S();
    swap(p[2], p[3]);
    S();
    swap(p[1],p[2]);
    S();
    swap(p[2],p[3]);
    S();
    swap(p[1],p[2]);
    S();
    swap(p[3],p[2]);
    S();
    cout << -1 << endl;
}